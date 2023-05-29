#include <iostream>
#include <vsomeip/vsomeip.hpp>

class MyServer : public vsomeip::application {
public:
    MyServer() : vsomeip::application("server") {}

    void on_subscribed(const std::shared_ptr<vsomeip::event> event) {
        std::cout << "Client subscribed to event: " << event->get_service() << ":" << event->get_instance() << ":" << event->get_event() << std::endl;
    }

    void on_notified(const std::shared_ptr<vsomeip::event> event) {
        std::cout << "Received notification from client: " << event->get_service() << ":" << event->get_instance() << ":" << event->get_event() << std::endl;
    }
};

class MyClient : public vsomeip::application {
public:
    MyClient() : vsomeip::application("client") {}

    void on_event(const std::shared_ptr<vsomeip::event> event) {
        std::cout << "Received event: " << event->get_service() << ":" << event->get_instance() << ":" << event->get_event() << std::endl;
    }
};

int main() {
    std::shared_ptr<MyServer> server = std::make_shared<MyServer>();
    std::shared_ptr<MyClient> client = std::make_shared<MyClient>();

    server->init();
    client->init();

    // Offer multiple services
    server->offer_service(0x1234, 0x0001);
    server->offer_service(0x1234, 0x0002);

    client->init();
    client->register_handler(vsomeip::on_event, std::bind(&MyClient::on_event, client, std::placeholders::_1));

    // Allow the user to choose a service to subscribe to
    std::cout << "Available services:" << std::endl;
    std::cout << "1. Service A" << std::endl;
    std::cout << "2. Service B" << std::endl;
    int choice;
    std::cout << "Enter the service number to subscribe: ";
    std::cin >> choice;

    vsomeip::service_t service_id = 0x1234;
    vsomeip::instance_t instance_id;
    if (choice == 1) {
        instance_id = 0x0001;
    } else if (choice == 2) {
        instance_id = 0x0002;
    } else {
        std::cout << "Invalid choice. Exiting..." << std::endl;
        return 1;
    }

    // Subscribe to the chosen service and instance
    client->request_event(service_id, instance_id, vsomeip::ANY_EVENT, true);

    server->register_handler(vsomeip::on_subscribed, std::bind(&MyServer::on_subscribed, server, std::placeholders::_1));
    server->register_handler(vsomeip::on_notified, std::bind(&MyServer::on_notified, server, std::placeholders::_1));
    
    server->start();
    client->start();

    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore();

    server->stop();
    client->stop();

    return 0;
}


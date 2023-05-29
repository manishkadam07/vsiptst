#include <iomanip>
#include <iostream>
#include <sstream>

#include <condition_variable>
#include <thread>

#include <vsomeip/vsomeip.hpp>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421

std::shared_ptr< vsomeip::application > app;
std::mutex mutex;
std::condition_variable condition;

void run() {
  std::unique_lock<std::mutex> its_lock(mutex);
  condition.wait(its_lock);
// Declare a shared pointer to hold the request message
  std::shared_ptr< vsomeip::message > request;
  // Create a new request message using the create_request() function from the vsomeip runtime.
  request = vsomeip::runtime::get()->create_request();
  // Set the service ID of the request message to SAMPLE_SERVICE_ID
  request->set_service(SAMPLE_SERVICE_ID);
  // Set the instance ID of the request message to SAMPLE_SERVICE_ID
  request->set_instance(SAMPLE_INSTANCE_ID);
  // Set the method ID of the request message to SAMPLE_SERVICE_ID
  request->set_method(SAMPLE_METHOD_ID);
// Create a payload object using the vsomeip runtime and assign it to the shared pointer its_payload.
  std::shared_ptr< vsomeip::payload > its_payload = vsomeip::runtime::get()->create_payload();
  // Declare a vector its_payload_data to hold the payload data.
  std::vector< vsomeip::byte_t > its_payload_data;
  // Fill the its_payload_data vector with values from 0 to 9.
  for (vsomeip::byte_t i=0; i<10; i++) {
      its_payload_data.push_back(i % 256);
  }
  its_payload->set_data(its_payload_data);
  request->set_payload(its_payload);
  // Send the request message using the vsomeip application app
  app->send(request);
}
// Define a function on_message that will be called when a vsomeip message is received.
void on_message(const std::shared_ptr<vsomeip::message> &_response) {

  std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
  vsomeip::length_t l = its_payload->get_length();

  // Get payload
  std::stringstream ss;
  for (vsomeip::length_t i=0; i<l; i++) {
     ss << std::setw(2) << std::setfill('0') << std::hex
        << (int)*(its_payload->get_data()+i) << " ";
  }

  std::cout << "CLIENT: Received message with Client/Session ["
      << std::setw(4) << std::setfill('0') << std::hex << _response->get_client() << "/"
      << std::setw(4) << std::setfill('0') << std::hex << _response->get_session() << "] "
      << ss.str() << std::endl;
}
// Define a function on_availability that will be called when the availability of a vsomeip service changes.
void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
// Print a message indicating the availability status of a service
    std::cout << "CLIENT: Service ["
            << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
            << "] is "
            << (_is_available ? "available." : "NOT available.")
            << std::endl;
    condition.notify_one();
}

int main() {
// Create a vsomeip application named "Hello"
    app = vsomeip::runtime::get()->create_application("Hello");
    app->init();
    app->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, on_availability);
    // Send a service request for the specified service and instance IDs
    app->request_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);
    // Creates a new thread sender and assigns it the run function to run concurrently.
    std::thread sender(run);
    app->start();
}

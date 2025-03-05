#include "Client.hpp"
#include "../common/Constants.hpp"
#include <iostream>

Client::Client() 
    : app_(vsomeip::runtime::get()->create_application(Constants::CLIENT_APP_NAME)),
      speedData_(0) {}

void Client::start() {
    app_->init();

    app_->register_message_handler(Constants::SERVICE_ID, Constants::METHOD_ID,
        std::bind(&Client::onDataReceived, this, std::placeholders::_1)
    );

    app_->request_service(Constants::SERVICE_ID, Constants::INSTANCE_ID);
    app_->start();
}

void Client::onDataReceived(const std::shared_ptr<vsomeip::message> &msg) {
    auto payload = msg->get_payload()->get_data();
    if (!payload.empty()) {
        int speed = static_cast<int>(payload[0]);
        if (speedData_ != speed) {
            speedData_ = speed;
            emit speedDataChanged(speedData_);
            std::cout << "Client: Received speed data: " << speedData_ << " km/h" << std::endl;
        }
    }
}


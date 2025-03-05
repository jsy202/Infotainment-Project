#include "Server.hpp"
#include "../common/Constants.hpp"
#include <iostream>
#include <chrono>

Server::Server() 
    : app_(vsomeip::runtime::get()->create_application(Constants::SERVER_APP_NAME)) {}

void Server::start() {
    app_->init();
    app_->offer_service(Constants::SERVICE_ID, Constants::INSTANCE_ID);

    senderThread_ = std::thread(&Server::sendData, this);
    senderThread_.detach();

    app_->start();
}

void Server::sendData() {
    while (true) {
        auto msg = vsomeip::runtime::get()->create_request();
        msg->set_service(Constants::SERVICE_ID);
        msg->set_method(Constants::METHOD_ID);

        std::vector<vsomeip::byte_t> data = {0x64}; // 속도: 100 km/h
        auto payload = vsomeip::runtime::get()->create_payload();
        payload->set_data(data);
        msg->set_payload(payload);

        std::cout << "Server: Sending speed data: " << static_cast<int>(data[0]) << " km/h" << std::endl;
        app_->send(msg);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


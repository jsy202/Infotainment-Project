#ifndef SERVER_HPP
#define SERVER_HPP

#include <vsomeip/vsomeip.hpp>
#include <thread>
#include <memory>

class Server {
public:
    Server();
    void start();

private:
    void sendData();
    std::shared_ptr<vsomeip::application> app_;
    std::thread senderThread_;
};

#endif // SERVER_HPP


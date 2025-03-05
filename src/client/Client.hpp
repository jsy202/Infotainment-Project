#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <vsomeip/vsomeip.hpp>
#include <QObject>

class Client : public QObject {
    Q_OBJECT
    Q_PROPERTY(int speedData READ speedData NOTIFY speedDataChanged)

public:
    Client();
    void start();
    int speedData() const { return speedData_; }

signals:
    void speedDataChanged(int speed);

private:
    void onDataReceived(const std::shared_ptr<vsomeip::message> &msg);

    std::shared_ptr<vsomeip::application> app_;
    int speedData_;
};

#endif // CLIENT_HPP


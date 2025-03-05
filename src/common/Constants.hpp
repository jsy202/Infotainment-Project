#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace Constants {
    constexpr vsomeip::service_t SERVICE_ID = 0x1234;
    constexpr vsomeip::instance_t INSTANCE_ID = 0x01;
    constexpr vsomeip::method_t METHOD_ID = 0x5678;

    constexpr const char *SERVER_APP_NAME = "DataServer";
    constexpr const char *CLIENT_APP_NAME = "DataClient";
}

#endif // CONSTANTS_HPP


cmake_minimum_required(VERSION 3.10)
project(InfotainmentSystem)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(vsomeip REQUIRED)

# 서버 빌드 설정
add_executable(server
    src/server/main_server.cpp
    src/server/Server.cpp
    src/common/Constants.hpp
)
target_link_libraries(server vsomeip3)

# 클라이언트 빌드 설정
add_executable(client
    src/client/main_client.cpp
    src/client/Client.cpp
    src/common/Constants.hpp
)
target_link_libraries(client vsomeip3 Qt6::Core Qt6::Quick)

qt_add_qml_module(client
    URI InstrumentCluster
    VERSION 1.0
    QML_FILES ui/main.qml
)


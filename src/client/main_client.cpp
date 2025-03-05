#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Client.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    Client client;
    client.start();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataClient", &client);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


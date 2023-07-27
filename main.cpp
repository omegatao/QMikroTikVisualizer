#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#include "iplookupgeoip2.h"
#include "routerinfohandler.h"
#include "spdlog/spdlog.h"


int main(int argc, char *argv[])
{
    // temporary debug code ----> start
    IPLookupGeoIP2 ipLookup;
    ipLookup.loadDatabaseFile("GeoLite2-City.mmdb");
    std::string targetIP{"8.8.8.8"};
    auto ipInfo = ipLookup.getIPInfo(targetIP);
    auto [coordinate, str1, str2] = *ipInfo;
    spdlog::info("ip address: {}, Longitude: {}, Lattitude: {}", targetIP, coordinate.first, coordinate.second);


    RouterInfoHandler handler1;
    // temporary debug code ----> end

    QGuiApplication app(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QMikroTikVisualizer_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

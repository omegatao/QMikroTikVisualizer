#include "routerinfohandler.h"
#include "spdlog/spdlog.h"

RouterInfoHandler::RouterInfoHandler(QObject *parent)
    : QObject{parent}
{
    QString address, port, name, password;
    address = QString(std::getenv("ROUTER_IP"));
    port = QString(std::getenv("ROUTER_PORT"));
    name = QString(std::getenv("ROUTER_USER"));
    password = QString(std::getenv("ROUTER_PW"));
    m_api = tikpp::make_api_te(io, [](const auto& err){spdlog::critical("error occured in tikpp: {}", err);});
    m_api->async_open(address.toStdString(), port.toInt(), name.toStdString(), password.toStdString(),[](const auto& err){
        if(err){
            spdlog::critical("error while connecting to the router: {}", err);
        }
    });
}

int RouterInfoHandler::initConnection(QString address, QString port, QString name, QString password)
{

}

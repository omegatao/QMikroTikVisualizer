#include "routerinfohandler.h"

RouterInfoHandler::RouterInfoHandler(QObject *parent)
    : QObject{parent}
{
    auto api = tikpp::make_api(io, [](const auto& err){});

}

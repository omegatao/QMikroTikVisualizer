#ifndef ROUTERINFOHANDLER_H
#define ROUTERINFOHANDLER_H

#include "tikpp/io_context.hpp"
#include "tikpp/api.hpp"
#include <QObject>


class RouterInfoHandler : public QObject
{
    Q_OBJECT
public:
    explicit RouterInfoHandler(QObject *parent = nullptr);
    int initConnection(QString address, QString port, QString name, QString password);

signals:

private:
    tikpp::io_context io{};
    std::shared_ptr<tikpp::api_te> m_api;

};

#endif // ROUTERINFOHANDLER_H

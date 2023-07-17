#ifndef IPLOOKUPGEOIP2_H
#define IPLOOKUPGEOIP2_H

#include "iplookupinterface.h"
#include "maxminddb.h"
#include <optional>

class IPLookupGeoIP2: public IPLookupInterface
{
public:
    IPLookupGeoIP2();
    ~IPLookupGeoIP2();

    int loadDatabaseFile(std::string) override;
    std::optional<std::tuple<std::pair<double, double>, std::string, std::string>> getIPInfo(std::string) override;

private:
    MMDB_s _mmdb;
    bool _dbOpened{false};

};

#endif // IPLOOKUPGEOIP2_H

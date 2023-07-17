#ifndef IPLOOKUPINTERFACE_H
#define IPLOOKUPINTERFACE_H

#include <tuple>
#include <string>
#include <utility>
#include <optional>

class IPLookupInterface
{
public:
    virtual int loadDatabaseFile(std::string) = 0;
    virtual std::optional<std::tuple<std::pair<double,double>, std::string, std::string>> getIPInfo(std::string) = 0;
};

#endif // IPLOOKUPINTERFACE_H

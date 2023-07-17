#include "iplookupgeoip2.h"
#include "spdlog/spdlog.h"

IPLookupGeoIP2::IPLookupGeoIP2()
{

}

IPLookupGeoIP2::~IPLookupGeoIP2()
{
    MMDB_close(&_mmdb);
}

int IPLookupGeoIP2::loadDatabaseFile(std::string fileName)
{
    int status = MMDB_open(fileName.c_str(), MMDB_MODE_MMAP, &_mmdb);
    if(status != MMDB_SUCCESS){
        spdlog::error("Can't open MMDB: {}",MMDB_strerror(status));
        return EXIT_FAILURE;
    }
    _dbOpened = true;
    return EXIT_SUCCESS;
}

std::optional<std::tuple<std::pair<double, double>, std::string, std::string>> IPLookupGeoIP2::getIPInfo(std::string ipAddr)
{
    int gai_error, mmdb_error;
    MMDB_lookup_result_s result = MMDB_lookup_string(&_mmdb, ipAddr.c_str(), &gai_error, &mmdb_error);
    if(gai_error != 0){
        spdlog::error("Error from getaddrinfo: {} ,while looking up ip: {}", gai_strerror(gai_error), ipAddr);
        return std::nullopt;
    }

    if(mmdb_error != MMDB_SUCCESS){
        spdlog::error("Error from libmaxminddb: {} ,while looking up ip: {}", gai_strerror(gai_error), ipAddr);
        return std::nullopt;
    }

    MMDB_entry_data_s entryData;
    int status = MMDB_get_value(&result.entry, &entryData, "location", "latitude", NULL);
    if (status != MMDB_SUCCESS){
        spdlog::error("error getting latitude: {}", MMDB_strerror(status));
        return std::nullopt;
    }
    if(!entryData.has_data){
        spdlog::error("No Lattitude Data");
        return std::nullopt;
    }
    double Lattitude = entryData.double_value;

    status = MMDB_get_value(&result.entry, &entryData, "location", "longitude", NULL);
    if (status != MMDB_SUCCESS){
        spdlog::error("error getting longitude: {}", MMDB_strerror(status));
        return std::nullopt;
    }
    if(!entryData.has_data){
        spdlog::error("No Longitude Data");
        return std::nullopt;
    }
    double Longitude = entryData.double_value;
    return std::make_tuple(std::make_pair(Longitude, Lattitude), "null", "null");

}

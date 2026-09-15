#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include <string>
#include <vector>
#include <map>

struct LocationConfig
{
    std::string path;
    std::vector<std::string> allowedMethods;
    std::string root;
    std::string index;
    bool autoindex;
    std::string cgiExtension;
    std::string cgiPath;
};

class ServerConfig
{
    public:
        ServerConfig();
        ~ServerConfig();

        int getPort() const;
        std::string getHost() const;
        std::string getServerName() const;
        size_t getMaxBodySize() const;
        std::string getErrorPage(int statusCode) const;
        const LocationConfig* matchLocation(const std::string& uri) const;

    private:
        int _port;
        std::string _host;
        std::string _serverName;
        size_t _maxBodySize;
        std::map<int, std::string> _errorPage;
        std::vector<LocationConfig> _locations;
};

#endif

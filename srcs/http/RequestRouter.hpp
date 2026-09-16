#ifndef REQUESTROUTER_HPP
#define REQUESTROUTER_HPP

class HttpRequest;
class ServerConfig;

struct LocationConfig;

struct RouteResult
{
    int statusCode;
    std::string redirectUrl;
    std::string finalPath;
    bool isDirectory;
    bool isCgi;
    std::string cgiExecutor;
    const LocationConfig* matchedLocation;
};

class RequestRouter
{
    public:
        RequestRouter();
        ~RequestRouter();

        RouteResult getRoute(const HttpRequest& request, const ServerConfig& config) const;

    private:
        const LocationConfig* matchLocation() const;
};

#endif
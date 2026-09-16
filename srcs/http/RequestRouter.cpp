#include "RequestRouter.hpp"
#include "../../includes/HttpRequest.hpp"
#include "../../includes/ServerConfig.hpp"
#include "../config/LocationConfig.hpp"

RequestRouter::RequestRouter() {};
RequestRouter::~RequestRouter() {};

RouteResult RequestRouter::getRoute(const HttpRequest& request, const ServerConfig& config) const
{
    
}

const LocationConfig* RequestRouter::matchLocation() const
{

}

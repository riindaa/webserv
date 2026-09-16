#include "../../includes/HttpResponse.hpp"
#include "../../includes/HttpRequest.hpp"
#include "../../includes/ServerConfig.hpp"
#include "../config/LocationConfig.hpp"

HttpResponse::HttpResponse() {}
HttpResponse::~HttpResponse() {}

void HttpResponse::setStatusCode(int code)
{
    _statusCode = code;
}
void HttpResponse::setHeader(const std::string& key, const std::string& value)
{
    _headers[key] = value;
}

void HttpResponse::setBody(const std::string& body)
{
    _body = body;
}

std::string HttpResponse::toString() const
{
    return "";
}

std::string HttpResponse::_getDefaultStatusMessage(int code) const
{
    (void)code;
    return "";
}
#include "HttpRequest.hpp"

HttpRequest::HttpRequest() {}

HttpRequest::~HttpRequest() {}

HttpRequest createMockRequest(const std::string& method, const std::string& uri, const std::string& body)
{
    HttpRequest req;
    return req;
}

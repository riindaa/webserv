#ifndef MOCKHTTPREQUEST_HPP
#define MOCKHTTPREQUEST_HPP

#include <string>

class HttpRequest;

HttpRequest createMockRequest(const std::string& method, const std::string& uri, const std::string& body);

#endif
#include "MockHttpResponse.hpp"
#include "HttpResponse.hpp"
#include <sstream>

void processRequest(HttpRequest req, ServerConfig config)
{
    (void)req;
    (void)config;
}

std::string HttpResponse::toString() const
{
    std::ostringstream stream;

    stream << "HTTP/1.1 " << _statusCode << " OK\r\n";
    stream << "Content-Type: text/html\r\n";
    stream << "Content-Length: " << _body.size() << "\r\n";
    stream << "Connection: close\r\n";
    stream << "\r\n";

    stream << _body;

    return stream.str();
}

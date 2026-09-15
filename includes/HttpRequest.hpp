#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <string>
#include <map>

enum ParseStatus 
{
    PARSING_INCOMPLETE,
    PARSING_COMPLETE,
    PARSING_ERROR
};

class HttpRequest 
{
    public :
        HttpRequest();
        ~HttpRequest();

        ParseStatus parseChunk(const std::string& buffer);

        std::string getMethod() const;
        std::string getUri() const;
        std::string getHttpVersion() const;
        std::string getHeader(const std::string& key) const;
        const std::map<std::string, std::string>& getHeader() const;
        std::string getBody() const;
        ParseStatus getStatus() const;

    private:
        std::string _method;
        std::string _uri;
        std::string _httpVersion;
        std::map<std::string, std::string> _headers;
        std::string _body;
        ParseStatus _status;
};

#endif

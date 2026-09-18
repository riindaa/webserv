#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <map>

class Client;

class Channel
{
    std::string _name;
    std::string _topic;
    std::map<std::string, Client*> _clients;
    
    bool autoindex;
    std::string cgiExtension;
    std::string cgiPath;
};

#endif

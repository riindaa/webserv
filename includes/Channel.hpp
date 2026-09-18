#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <map>

class Channel
{
    std::string path;
    std::vector<std::string> allowedMethods;
    std::string root;
    std::string index;
    bool autoindex;
    std::string cgiExtension;
    std::string cgiPath;
};

#endif

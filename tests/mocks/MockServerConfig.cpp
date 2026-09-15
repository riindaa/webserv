#include "ServerConfig.hpp"

ServerConfig createMockConfig()
{
    ServerConfig config;

    LocationConfig rootLoc;
    rootLoc.path = "/";
    rootLoc.allowedMethods.push_back("GET");
    rootLoc.root = "./www";
    rootLoc.index = "index.html";
    rootLoc.autoindex = false;

    LocationConfig cgiLoc;
    cgiLoc.path = "/cgi-bin";
    cgiLoc.allowedMethods.push_back("GET");
    cgiLoc.allowedMethods.push_back("POST");
    cgiLoc.cgiExtension = ".py";
    cgiLoc.cgiPath = "/usr/bin/python3";

    return config;
}

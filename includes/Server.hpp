#ifndef SERVER_HPP
#define SERVER_HPP

#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <map>

#include "Client.hpp"
#include "Channel.hpp"

class Server
{
  private:
    int _fd;
    int _port;
    std::string _password;
    std::string _host;
    std::map<int, Client*> _clients;
    std::map<std::string, Channel*> _channels;


    bool set_non_blocking();
    bool set_sockopt();
    bool set_bind();

  public:
    Server(int port, const std::string &host, std::string password);
    ~Server();

    bool setup();

    int getFd() const;
    int getPort() const;
    Client* getClient(int fd) const;
    Channel* getChannel(std::string chan) const;
    std::map<int,  Client*> getAllClients(int fd) const;
    std::map<std::string, Channel*> getAllChannels(std::string ChanName) const;
    const std::string &getHost() const;

    void setChannel(std::string ChanName);

    void closeSocket();
};

#endif
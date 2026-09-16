#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

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

class ServerSocket
{
  private:
    int _fd;
    int _port;
    std::string _host;

    bool set_non_blocking();
    bool set_sockopt();
    bool set_bind();

  public:
    ServerSocket(int port, const std::string &host);
    ~ServerSocket();

    bool setup();

    int getFd() const;
    int getPort() const;
    const std::string &getHost() const;

    void closeSocket();
};

#endif
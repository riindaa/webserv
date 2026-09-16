#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

# include <string>
# include <stdexcept>
# include <cstring>
# include <cerrno>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <iostream>

class ServerSocket {
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
    const std::string& getHost() const;

    void closeSocket();
};

#endif
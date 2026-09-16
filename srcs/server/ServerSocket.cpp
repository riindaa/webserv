#include "ServerSocket.hpp"

ServerSocket::ServerSocket(int port, const std::string &host) : _host(host), _port(port), _fd(-1)
{
}

ServerSocket::~ServerSocket()
{
}

bool ServerSocket::set_non_blocking()
{
    int flags = fcntl(_fd, F_GETFL, 0);
    if (flags < 0)
    {
        std::cerr << "Error fcntl F_GETFL: " << std::strerror(errno) << "\n";
        closeSocket();
        return false;
    }
    if (fcntl(_fd, F_SETFL, flags | O_NONBLOCK) < 0)
    {
        std::cerr << "Error fcntl F_SETFL: " << std::strerror(errno) << "\n";
        closeSocket();
        return false;
    }
    return true;
}

bool ServerSocket::set_sockopt()
{
    int opt = 1;
    if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        std::cerr << "Error setsockopt: " << std::strerror(errno) << "\n";
        closeSocket();
        return false;
    }
    return (true);
}

bool ServerSocket::set_bind()
{
    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(_host.c_str());
    if (addr.sin_addr.s_addr = INADDR_NONE)
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(_port);

    if (bind(_fd, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) < 0)
    {
        std::cerr << "Error bind\n";
        closeSocket();
        return false;
    }
    return true;
}

int ServerSocket::getFd() const
{
    return _fd;
}

int ServerSocket::getPort() const
{
    return _port;
}

const std::string &ServerSocket::getHost() const
{
    return _host;
}

void ServerSocket::closeSocket()
{
    if (_fd != -1)
        close(_fd);
    _fd = -1;
}

bool ServerSocket::setup()
{
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_fd < 0)
    {
        std::cerr << "Error\n";
        return false;
    }

    if (!set_sockopt())
        return false;

    if (!set_non_blocking())
        return false;

    if (!set_bind())
        return false;

    if (listen(_fd, SOMAXCONN) < 0)
    {
        std::cerr << "Error listen: " << std::strerror(errno) << "\n";
        closeSocket();
        return false;
    }
    return true;
}

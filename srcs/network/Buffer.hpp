#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <ctime>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

class Client
{
  public:
    enum ClientState
    {
        READING_REQUEST,
        WRITING_RESPONSE,
        WAITING_FOR_CGI,
        DISCONNECT
    };

  private:
    int _fd;
    sockaddr_in _addr;
    std::string _inBuffer;
    std::string _outBuffer;
    time_t _lastActivity;
    ClientState _state;

  public:
    Client();
    Client(int fd, const sockaddr_in &addr);
    ~Client();

    void reset();

    int getFd() const;
    const sockaddr_in &getAddr() const;
    const std::string &getInBuffer() const;
    const std::string &getOutBuffer() const;
    time_t getLastActivity() const;
    ClientState getState() const;

    void setState(ClientState state);
    void appendInBuffer(const char *buf, size_t size);
    void setOutBuffer(const std::string &response);
    void consumeOutBuffer(size_t bytesSent);
    void updateLastActivity();

    bool isTimeout(time_t timeoutInSeconds) const;
};

#endif
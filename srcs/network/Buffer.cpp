#include "Client.hpp"

Client::Client(): 
_fd(-1),
_lastActivity(time(NULL)),
_state(READING_REQUEST)
{
    std::memset(&_addr,0, sizeof(_addr));
}

Client::Client(int fd, const sockaddr_in &addr): 
_fd(fd),
_addr(addr),
_lastActivity(time(NULL)),
_state(READING_REQUEST)
{
}

Client::~Client()
{
}


void Client::reset()
{
    _inBuffer.clear();
    _outBuffer.clear();
    _state = READING_REQUEST;
    _lastActivity = time(NULL);
}

int Client::getFd() const
{
    return _fd;
}

const sockaddr_in &Client::getAddr() const
{
    return _addr;
}

const std::string &Client::getInBuffer() const
{
    return _inBuffer;
}

const std::string &Client::getOutBuffer() const
{
    return _outBuffer;
}

time_t Client::getLastActivity() const
{
    return _lastActivity;
}

Client::ClientState Client::getState() const
{
    return _state;
}

void Client::setState(ClientState state)
{
    _state = state;
}

void Client::appendInBuffer(const char *buf, size_t size)
{
    _inBuffer.append(buf, size);
}

void Client::setOutBuffer(const std::string &response)
{
    _outBuffer = response;
}

void Client::consumeOutBuffer(size_t bytesSent)
{
    if (bytesSent >= _outBuffer.size())
        _outBuffer.clear();
    else
        _outBuffer.erase(0, bytesSent);
}

void Client::updateLastActivity()
{
    _lastActivity = time(NULL);
}

bool Client::isTimeout(time_t timeoutInSeconds) const
{
    return time(NULL) - _lastActivity >= timeoutInSeconds;
}

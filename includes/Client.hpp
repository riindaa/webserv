#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <map>

class Channel;

enum AUTHENTIFICATION_STATE
{
    VALID,
    INVALID
};

class Client
{
    private:
        int _fd;
        std::string _nickname;
        std::string _username;
        std::string _realname;
        std::string _InBuff;
        std::string _OutBuff;
        std::map<std::string, Channel*> _channels;

    public:
        Client();
        ~Client();

        int getFd() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getRealname() const;
        std::string getInBuff() const;
        std::string getOutBuff() const;
};

#endif

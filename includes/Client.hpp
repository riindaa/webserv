#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <set>

class Channel;

class Client
{
    private:
        int _fd;

        std::string _nickname;
        std::string _username;
        std::string _realname;

        std::string _InBuff;
        std::string _OutBuff;

        bool _hasPassword;

        std::set<Channel*> _channels;

    public:
        Client();
        Client(std::string _nickname, std::string _username, std::string _realname);
        ~Client();

        int getFd() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getRealname() const;
        std::string getInBuff() const;
        std::string getOutBuff() const;
        std::map<std::string, Channel*> getChannels() const;
        
        bool isOperator() const;
        bool isRegistered() const;
        bool hasPass() const;

        void setChannel(Channel *newChannel);

        void closeClient();
};

#endif

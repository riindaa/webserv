#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <set>
#include <map>
#include "Channel.hpp"

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
        Client(int fd);
        ~Client();

        int getFd() const;
        const std::string& getNickname() const;
        const std::string& getUsername() const;
        const std::string& getRealname() const;
        const std::string& getInBuff() const;
        const std::string& getOutBuff() const;
        const std::set<std::string, Channel*>& getChannels() const;
        
        void setNickname(const std::string& nick);
        void setUsername(const std::string& user);
        void setRealname(const std::string& real);
        void setHasPass(bool hasPass);
        void setIsRegistered(bool registered);

        void addChannel(Channel* channel);
        void removeChannel(Channel* channel);

        void appendInBuff(const std::string& str);
        void appendOutBuff(const std::string& str);
        void clearInBuff();

        void closeClient();
};

#endif

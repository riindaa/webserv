#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <set>
#include <map>

class Client;

class Channel
{
    private:
        std::string _name;
        std::string _topic;
        std::string _key;

        std::map<Client*, bool> _clients;
        std::set<Client*> _invitedClients;

        size_t _user_limit;
        bool _inviteOnly;
        bool _topicRestricted;

    public:
        Channel();
        ~Channel();
};

#endif

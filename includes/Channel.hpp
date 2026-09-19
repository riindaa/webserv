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

        size_t _userLimit;
        bool _inviteOnly;
        bool _topicRestricted;

    public:
        Channel();
        ~Channel();

        std::string getKey() const;
        std::string getTopic() const;
        std::string getName() const;

        std::map<Client*, bool> getClients() const;
        std::set<Client*> getInvitedClients() const;

        size_t getuserlimit() const;

        bool    isInviteOnly() const;
        bool    isTopicRestricted();
};

#endif

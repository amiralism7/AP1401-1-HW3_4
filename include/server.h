
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "message.h"
#include "user.h"
#include "crypto.h"
#include <algorithm>

class User;

class Server
{
public:
    Server() = default;
    std::vector<User> get_users();
    std::map<std::string, std::string> get_public_keys();
    std::vector<Message*> get_messages();
    User create_user(std::string username);

    
    bool create_message(Message* msg, std::string signature);
    

    std::vector<Message*> get_all_messages_from(std::string username);
    std::vector<Message*> get_all_messages_to(std::string username);
    std::vector<Message*> get_chat(std::string user1, std::string user2);
    static void sort_msgs(std::vector<Message*> &msgs);
private:
    std::vector<User> users;                        // to store our users
    std::map<std::string, std::string> public_keys; // map usernames to their publickeys
    std::vector<Message*> messages;                 // to store all the messages sent by users
};



#endif //SERVER_H
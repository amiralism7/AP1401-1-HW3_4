#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "server.h"
#include "message.h"
#include "crypto.h"

class Server;

class User
{
public:
    User(std::string username, std::string private_key, Server* server);
    std::string get_username();
    bool send_text_message(std::string text, std::string receiver);
    bool send_voice_message(std::string receiver);

private:
    std::string username;     // username of the user
    std::string private_key; // private key of the user
    Server* const server;     // a pointer to the server for communications
};






#endif //USER_H
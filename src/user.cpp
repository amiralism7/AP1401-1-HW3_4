#include "user.h"

User::User(std::string _username, std::string _private_key, Server* _server):
username{_username},
private_key{_private_key},
server{_server}
{
    // std::cout << "User Constructor Called" << std::endl;
}
std::string User::get_username(){
    return username;
}


bool User::send_text_message(std::string text, std::string receiver){

    bool flag{false};
    std::vector<User> server_users{server->get_users()};

    for (size_t i{}; i<server_users.size(); i++){
        if (server_users[i].get_username() == receiver)
            flag = true;
    }
    if (!flag)
        return false;
    TextMessage textmsg(text, this->get_username(), receiver);
    Message* msg{&textmsg};

    std::string tmp_username{this->get_username()};
    std::string tmp_pvkey{private_key};
    std::string tmp_pubkey{server->get_public_keys()[tmp_username]};

    // std::cout << "username is: " << tmp_username << std::endl;
    // std::cout << "pvkey is: " << tmp_pvkey << std::endl;
    // std::cout << "pubkey is: " << tmp_pubkey << std::endl;
    // std::cout << "text is: " << text << std::endl;

    std::string signature = crypto::signMessage(tmp_pvkey, tmp_username);
    bool result{server->create_message(&textmsg, signature)};
    return result;
    
}

bool User::send_voice_message(std::string receiver){
    bool flag{false};
    std::vector<User> server_users{server->get_users()};

    for (size_t i{}; i<server_users.size(); i++){
        if (server_users[i].get_username() == receiver)
            flag = true;
    }

    if (!flag)
        return false;

    VoiceMessage vociemsg(this->get_username(), receiver);
    Message* msg{&vociemsg};

    std::string tmp_username{this->get_username()};
    std::string tmp_pvkey{private_key};
    std::string tmp_pubkey{server->get_public_keys()[tmp_username]};

    // std::cout << "username is: " << tmp_username << std::endl;
    // std::cout << "pvkey is: " << tmp_pvkey << std::endl;
    // std::cout << "pubkey is: " << tmp_pubkey << std::endl;
    

    std::string signature = crypto::signMessage(tmp_pvkey, tmp_username);
    bool result{server->create_message(msg, signature)};
    return result;
}
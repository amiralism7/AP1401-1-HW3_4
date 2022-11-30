#include "server.h"

// getter functions
std::vector<User> Server::get_users(){
    return users;
}
std::map<std::string, std::string> Server::get_public_keys(){
    return public_keys;
}
std::vector<Message*> Server::get_messages(){
    return messages;
}


User Server::create_user(std::string _username){
    std::string public_key{}, private_key{};
    crypto::generate_key(public_key, private_key);
    std::vector<User> server_users{this->get_users()};

    for (size_t i{}; i<server_users.size(); i++){
        if (server_users[i].get_username() == _username)
            throw std::logic_error("This username has been used!");
    }

    public_keys[_username] = public_key;
    User new_user{_username, private_key, this};
    users.push_back(new_user);
    // // Debug
    // std::cout << "***********************************************************" << std::endl;
    // std::cout << "username is: " << _username << std::endl;
    // std::cout << "public_key is: " << public_key << std::endl;
    // std::cout << "private_key is: " << private_key << std::endl;
    // std::cout << "***********************************************************" << std::endl;
    
    return new_user;    
}










bool Server::create_message(Message* msg, std::string signature){
    // std::string signature = crypto::signMessage(private_key, "my data");
    std::string msg_sender{msg->get_sender()};
    std::string public_key{public_keys[msg_sender]};
    bool authentic = crypto::verifySignature(public_key, msg_sender, signature);

    if (authentic){
        messages.push_back(msg);
    }


    // // Debug section
    //
    (this->get_messages()[this->get_messages().size()-1])->print(std::cout);
    std::cout << "In create_message, server address is: " << this << std::endl;
    //
    //



    return authentic;
}







std::vector<Message*> Server::get_all_messages_from(std::string username){

}
std::vector<Message*> Server::get_all_messages_to(std::string username){

}
std::vector<Message*> Server::get_chat(std::string user1, std::string user2){

}
void Server::sort_msgs(std::vector<Message*> msgs){

}
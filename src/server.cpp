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
    
    std::string msg_sender{msg->get_sender()};
    std::string public_key{public_keys[msg_sender]};
    bool authentic = crypto::verifySignature(public_key, msg_sender, signature);

    if (authentic){
        messages.push_back(msg);
    }

    // // Debug section
    //
    // (this->get_messages()[this->get_messages().size()-1])->print(std::cout);
    // std::cout << "In create_message, server address is: " << this << std::endl;
    // std::cout << msg->get_receiver() << std::endl;
    //
    //

    return authentic;
}







std::vector<Message*> Server::get_all_messages_from(std::string username){
    // // without STL
    // std::vector<Message*> user_msgs{};
    // for (size_t i{}; i < messages.size(); i++){
    //     if (messages[i]->get_sender() == username)
    //         user_msgs.push_back(messages[i]);
    // }
    // return user_msgs;

    //////////////

    // // with STL
    // creaes a vector of size (messages.size()) using default constructor
    std::vector<Message*> user_msgs(messages.size());
    // copying the instances that satisfy the given function (return true) into user_msgs
    auto end_user_msgs = std::copy_if(
        messages.begin(), 
        messages.end(), 
        user_msgs.begin(),
        [username](Message* msg){ return msg->get_sender() == username; });
    // removing the extra (unfilled) elements of the user_msgs vector
    user_msgs.erase(end_user_msgs, user_msgs.end());
    return user_msgs;
    

}
std::vector<Message*> Server::get_all_messages_to(std::string username){
    // // with STL
    // creaes a vector of size (messages.size()) using default constructor
    std::vector<Message*> user_msgs(messages.size());
    // copying the instances that satisfy the given function (return true) into user_msgs
    auto end_user_msgs = std::copy_if(
        messages.begin(), 
        messages.end(), 
        user_msgs.begin(),
        [username](Message* msg){ return msg->get_receiver() == username; });
    // removing the extra (unfilled) elements of the user_msgs vector
    user_msgs.erase(end_user_msgs, user_msgs.end());
    return user_msgs;
}

std::vector<Message*> Server::get_chat(std::string user1, std::string user2){
    std::vector<Message*> user_msgs(messages.size());
    // copying the instances that satisfy the given function (return true) into user_msgs
    auto end_user_msgs = std::copy_if(
        messages.begin(), 
        messages.end(), 
        user_msgs.begin(),
        [user1, user2](Message* msg){
            return ((msg->get_sender() == user1) && (msg->get_receiver() == user2)) || 
            ((msg->get_receiver() == user1) && (msg->get_sender() == user2));
            });

    // removing the extra (unfilled) elements of the user_msgs vector
    user_msgs.erase(end_user_msgs, user_msgs.end());
    return user_msgs;

}

void Server::sort_msgs(std::vector<Message*> &msgs){
    // // This doesn't work and I don't know why!!!!!!
    // std::sort(msgs.begin(), msgs.end(),
    // [](Message* _first, Message* _second) { 
    //     std::string first = _first->get_time();
    //     std::string second = _second->get_time();
    //     struct tm timeDate;
    //     struct tm timeDate2;
    //     strptime(first.c_str(),"%a %b %e %H:%M:%S %y", &timeDate);
    //     strptime(second.c_str(),"%a %b %e %H:%M:%S %y", &timeDate2);
    //     time_t t1 = mktime(&timeDate);
    //     time_t t2 = mktime(&timeDate2);
    //     std::cout << difftime(t1, t2) << std::endl;
    //     return (difftime(t1, t2) > 0);
    // });

    std::sort(msgs.begin(), msgs.end(),
    [](Message* _second, Message* _first) { 
        std::string first = _first->get_time();
        std::string second = _second->get_time();
        struct tm timeDate;
        struct tm timeDate2;
        strptime(first.c_str(),"%a %b %e %H:%M:%S %Y", &timeDate);
        strptime(second.c_str(),"%a %b %e %H:%M:%S %Y", &timeDate2);
        
        if (timeDate.tm_year > timeDate2.tm_year)
            return true;
        if (timeDate.tm_yday > timeDate2.tm_yday)
            return true;
        if (timeDate.tm_hour > timeDate2.tm_hour)
            return true;
        if (timeDate.tm_min > timeDate2.tm_min)
            return true;
        if (timeDate.tm_sec >= timeDate2.tm_sec)
            return true;
        return false;
    });
    
}
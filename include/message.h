#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

//////////////////////////////
//////////////////////////////
///// class Message //////////
//////////////////////////////
//////////////////////////////

class Message
{
public:
    Message(std::string type, std::string sender, std::string receiver);
    Message();

    // getter functions
    std::string get_type();
    std::string get_sender();
    std::string get_receiver();
    std::string get_time();
    // display message
    virtual void print(std::ostream &os) {
        os << "*************************" << std::endl;
        os << this->get_sender() << " -> " << this->get_receiver() << std::endl;
        os << "message type: text" << std::endl;
        os << "message time: " << this->get_time() << std::endl;
        os << "*************************" << std::endl;
        os;
    }

    template <typename T>
    friend std::ostream& operator<<(std::ostream &os, const T &c){
        // T msg = *(const_cast<T*>(&c));
        // msg.print(os);

        T* msg = (const_cast<T*>(&c));
        msg->print(os);
        return os;
    }


    
private:
    std::string type;     // type of the message ("text", "voice", ...)
    std::string sender;   // the username who send this message
    std::string receiver; // the username whom this message is intended for
    std::string time;     // creation time of the message
};

//////////////////////////////
//////////////////////////////
///// class TextMessage //////
//////////////////////////////
//////////////////////////////

class TextMessage : public Message
{
public:
    TextMessage(std::string text, std::string sender, std::string receiver);
    std::string get_text();

    virtual void print(std::ostream &os) override{
        os << "*************************" << std::endl;
        os << this->get_sender() << " -> " << this->get_receiver() << std::endl;
        os << "message type: text" << std::endl;
        os << "message time: " << this->get_time() << std::endl;
        os << "text: " << this->get_text() << std::endl;
        os << "*************************" << std::endl;
        os;
    }

    
private:
    std::string text;
};

//////////////////////////////
//////////////////////////////
///// class VocieMessage /////
//////////////////////////////
//////////////////////////////

class VoiceMessage : public Message
{
public:
    VoiceMessage(std::string sender, std::string receiver);
    std::vector<unsigned char> get_voice();

    virtual void print(std::ostream &os) override{
        os << "*************************" << std::endl;
        os << this->get_sender() << " -> " << this->get_receiver() << std::endl;
        os << "message type: voice" << std::endl;
        os << "message time: " << this->get_time() << std::endl;
        std::vector<unsigned char> _v{this->get_voice()};
        os << "voice: " << 
            static_cast<int>(_v[0]) << " " <<
            static_cast<int>(_v[1]) << " " <<
            static_cast<int>(_v[2]) << " " <<
            static_cast<int>(_v[3]) << " " <<
            static_cast<int>(_v[4]) << " " <<
            std::endl;
        os << "*************************" << std::endl;
        os;
        
    }
private:
    std::vector<unsigned char> voice;
};





#endif //MESSAGE_H
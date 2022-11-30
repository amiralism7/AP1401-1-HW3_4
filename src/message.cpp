#include "message.h"




//////////////////////////////
//////////////////////////////
///// class Message //////////
//////////////////////////////
//////////////////////////////

Message::Message(std::string _type, std::string _sender, std::string _receiver):
    type{_type},
    sender{_sender},
    receiver{_receiver}
{
    // std::cout << "Constructor Message Called" << std::endl;
    time_t ttime = std::time(0);
    tm *gmt_time = gmtime(&ttime);
    std::string dt = asctime(gmt_time);
    time = dt.substr(0, dt.size()-1);
    // std::cout << time << std::endl;
}

Message::Message(): Message::Message{"", "", ""}
{
    // std::cout << "Default Constructor Message Called" << std::endl;
}

// Defining Getter Functions
std::string Message::get_type(){
    return type;
}

std::string Message::get_sender(){
    return sender;
}

std::string Message::get_receiver(){
    return receiver;
}

std::string Message::get_time(){
    return time;
}


// message Template:
    // *************************
    // david -> jenifer
    // message type: text
    // message time: Sun Nov 13 17:50:43 2022
    // *************************





//////////////////////////////
//////////////////////////////
///// class TextMessage //////
//////////////////////////////
//////////////////////////////

TextMessage::TextMessage(std::string _text, std::string _sender, std::string _receiver):
    Message::Message{"text", _sender, _receiver},
    text{_text}
{
    // std::cout << "Constructor TextMessage Called" << std::endl;
}

std::string TextMessage::get_text(){
    return text;
}

//////////////////////////////
//////////////////////////////
///// class VocieMessage /////
//////////////////////////////
//////////////////////////////

VoiceMessage::VoiceMessage(std::string _sender, std::string _receiver):
    Message::Message{"voice", _sender, _receiver},
    voice{'a', 'b', 'c', 'd', 'e'}
{
    // std::cout << "Constructor VoiceMessage Called" << std::endl;
}

std::vector<unsigned char> VoiceMessage::get_voice(){
    return voice;
}
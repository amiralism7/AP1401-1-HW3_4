#include <iostream>
#include <gtest/gtest.h>
#include "message.h"
#include "user.h"
#include "server.h"
#include "stl.h"











int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {

        Server server;
        User david = server.create_user("david");
        User jenifer = server.create_user("jenifer");

        david.send_text_message("text 1", "jenifer");
        jenifer.send_voice_message("david");
        

        // std::cout << result << std::endl;
        std::cout << server.get_messages().size() << std::endl;

        std::cout << "In main, sever address is: " << &server << std::endl;
        (server.get_messages()[server.get_messages().size()-1])->print(std::cout);
        




    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}
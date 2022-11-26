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
        // debug section
        // Message msg1{"type1","sender1", "receiver1"};
        // TextMessage txt1{"Hi Amir", "Ali", "Amir"};
        // std::cout << txt1;

        TextMessage textmsg("hello", "david", "jenifer");
        Message* msg{&textmsg};
        std::stringstream ss;
        ss << *msg;
        std::cout << ss.str() << std::endl;

        
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
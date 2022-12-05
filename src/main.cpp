#include <iostream>
#include <gtest/gtest.h>
#include "message.h"
#include "user.h"
#include "server.h"
#include "stl.h"
#include <algorithm>
#include <ctime>
#include <set>
#include <functional>
#include <numeric>


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {

        // Server server;
        // User david = server.create_user("david");
        // User jenifer = server.create_user("jenifer");

        // david.send_text_message("text 1", "jenifer");
        // david.send_text_message("text 2", "jenifer");
        // jenifer.send_text_message("text 2", "david");
        // jenifer.send_voice_message("david");
        

        // std::cout << "In main, sever address is: " << &server << std::endl;
        // (server.get_messages()[server.get_messages().size()-1])->print(std::cout);

        // std::vector<Message*> user_msgs{server.get_all_messages_from("david")};
        // std::cout << user_msgs.size() << std::endl;
        // std::cout << user_msgs[0]->get_type() << std::endl;


        // std::string soon = "Sun Nov 13 17:50:44 2022";
        // std::string late = "Mon Nov 14 17:50:44 2022";
        // struct tm timeDate;
        // struct tm timeDate2;
        // strptime(soon.c_str(),"%a %b %e %H:%M:%S %Y", &timeDate);
        // strptime(late.c_str(),"%a %b %e %H:%M:%S %Y", &timeDate2);
        // std::cout << timeDate.tm << std::endl;
        // std::cout << timeDate2.tm_yday << std::endl;


        // std::vector<int> v;
        // initial_vector_with_3_mutiplies(v, 10);
        // v.push_back(3);
        // v.push_back(9);
        // for (auto i : v)
        //     std::cout << i << " ";
        // std::cout << std::endl;
        // std::set<int, std::less<>> my_set{v.begin(), v.end()};
        // for (auto i : my_set)
        //     std::cout << i << " ";
        // std::cout << std::endl;
        // std::cout << my_set.size() << std::endl;

        // char separator = '*';
        // std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 14};
        // std::cout << v.back() << std::endl;
        // std::string str = std::accumulate(v.rbegin() + 1, v.rend(),
        //                 std::to_string(v.back()), 
        //                 [separator](std::string _str, int _v)
        //                 {
        //                     return _str + separator + std::to_string(_v);
        //                 });

        // std::cout << str << std::endl;



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
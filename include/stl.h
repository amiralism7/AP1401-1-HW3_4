#ifndef STL_H
#define STL_H

#include <iostream>
#include <algorithm>
#include <set>
#include <functional>
#include <numeric>

inline void initial_vector_with_3_mutiplies(std::vector<int>& v, size_t size){
    std::vector<int> tmp(size);
    v = tmp;
    int counter{0};
    std::generate(v.begin(), v.end(), [&counter] () mutable {
         counter += 3;
         return counter; 
         });
    
}



inline int count_unique_above(std::vector<int> v, int n){
    std::set<int, std::less<>> my_set{v.begin(), v.end()};


    std::vector<int> greaters(my_set.size());
    // copying the instances that satisfy the given function (return true) into greaters
    auto end_greaters = std::copy_if(
        my_set.begin(), 
        my_set.end(), 
        greaters.begin(),
        [n](int a){
            return a > n;
            });

    // removing the extra (unfilled) elements of the greaters vector
    greaters.erase(end_greaters, greaters.end());
  
    return greaters.size();
}



inline std::string vector_to_string(std::vector<int> v, char separator){
    std::string str = std::accumulate(v.rbegin() + 1, v.rend(),
                        std::to_string(v.back()), 
                        [separator](std::string _str, int _v)
                        {
                            return _str + separator + std::to_string(_v);
                        });
    return str;
}




#endif //STL_H
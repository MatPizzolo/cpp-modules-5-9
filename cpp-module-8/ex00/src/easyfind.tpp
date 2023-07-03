#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../inc/easyfind.hpp"

template<typename T>
int easyfind(T& cont, int b) {
    typename T::const_iterator temp;
    for (temp = cont.begin(); temp != cont.end(); ++temp) {
        if (*temp == b)
            return b;
    }
    return -1;
}

#endif
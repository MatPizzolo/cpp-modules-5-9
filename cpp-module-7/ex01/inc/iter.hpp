#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename Func>
void iter(T* arrAddr, int len, Func f) {
    int i = -1;
	while (++i < len)
		f(arrAddr[i]);
}


#endif
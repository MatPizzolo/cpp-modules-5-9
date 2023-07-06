#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../inc/easyfind.hpp"

template<typename T>
int easyfind(T& cont, int b) {
	typename T::const_iterator it;
	it = find(cont.begin(), cont.end(), b);
	if (it != cont.end())
		return *it;
	return -1;
}

#endif
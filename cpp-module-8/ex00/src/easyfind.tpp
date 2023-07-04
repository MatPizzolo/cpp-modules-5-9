#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../inc/easyfind.hpp"

template<typename T>
int easyfind(T& vect, int b) {
	typename T::const_iterator it;
	it = find (vect.begin(), vect.end(), b);
	if (it != vect.end())
		return *it;
	return -1;
}

#endif
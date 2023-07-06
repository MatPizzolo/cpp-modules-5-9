#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

template <class T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		typedef std::stack<T, std::deque<T> > stack;
		typedef typename stack::container_type::iterator iterator;

		MutantStack() : stack() {}
		MutantStack(const stack &src) : stack(src) {}
		~MutantStack() {}
		stack &operator=(const stack &src) {
			if (*this != src)
				*this = src;
			return (*this);
		}

		iterator begin() { return stack::c.begin(); }
	    iterator end() { return stack::c.end(); }
};


#endif
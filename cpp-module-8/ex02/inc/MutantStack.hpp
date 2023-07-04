#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack(): std::stack<T>() {}
		void* begin();
		// ~MutantStack();
		// MutantStack(const MutantStack& copy);
		// MutantStack &operator=(const MutantStack& other);

		// Iterators
		// end
		// rbegin
		// rend
		// cbegin
		// cend
		// crbegin
		// crend
	template<typename Container>
	class iterator: public std::iterator<std::bidirectional_iterator_tag, T>
	{
		private:
			typename Container::iterator it;

		public:
			iterator(typename Container::iterator iter) : it(iter) {}

	};
};

#endif




/*

			iterator& operator++() {
				++it;
				return *this;
			}

			iterator operator++(int) {
				iterator temp = *this;
				++(*this);
				return temp;
			}

			bool operator==(const iterator& other) const {
				return it == other.it;
			}

			bool operator!=(const iterator& other) const {
				return !(*this == other);
			}

			reference operator*(){
				return *it;
			}

*/
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class Span {
	private:
		unsigned int size_n;

	public: 
		std::vector<int> vec;
		Span();
		Span(unsigned int n);
		~Span();

		Span(const Span& copy);
		Span &operator=(const Span& other);

		void addNumber(int a);
		int shortestSpan();
		int longestSpan();
		void addLotsOfNumbers(unsigned int many, int n);

};

#endif
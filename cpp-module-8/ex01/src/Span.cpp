#include "../inc/Span.hpp"

Span::Span(): size_n(5) {}

Span::Span(unsigned int n): size_n(n) {}

Span::Span(const Span& copy): size_n(copy.size_n), vec(copy.vec) {}

Span::~Span() {}

void Span::addNumber(int a) {
	try {
		if (size_n > vec.size())
			vec.push_back(a);
		else {
			std::string errorMessage = "Cannot add number ";
			errorMessage += std::to_string(a);
			errorMessage += ", vector has reached its maximum size.";
			throw std::runtime_error(errorMessage);
		}
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int Span::shortestSpan() {
	try {
		if (vec.size() > 1) {
			int shortest = INT_MAX;
			for (std::vector<int>::const_iterator it1 = vec.begin(); it1 != vec.end(); ++it1) {
				for (std::vector<int>::const_iterator it2 = it1 + 1; it2 != vec.end(); ++it2) {
					int diff = std::abs(*it2 - *it1);
					if (diff < shortest) {
						shortest = diff;
					}
				}
			}
			return (shortest);
		} else
			throw std::runtime_error("vector has a size <= 1");
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}

int Span::longestSpan() {
	try {
		if (vec.size() > 1) {
			int biggest = 0;
			for (std::vector<int>::const_iterator it1 = vec.begin(); it1 != vec.end(); ++it1) {
				for (std::vector<int>::const_iterator it2 = it1 + 1; it2 != vec.end(); ++it2) {
					int diff = std::abs(*it2 - *it1);
					if (diff > biggest) {
						biggest = diff;
					}
				}
			}
			return (biggest);
		} else
			throw std::runtime_error("vector has a size <= 1");
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}

void Span::addLotsOfNumbers(unsigned int many, int n) {
	if (vec.size() + many <= size_n)
		vec.insert(vec.end(), many, n);
	else {
		many = size_n - vec.size();
		vec.insert(vec.end(), many, n);
	}
}

Span &Span::operator=(const Span& other) {
	this->size_n = other.size_n;
	this->vec = other.vec;
	return *this;
}

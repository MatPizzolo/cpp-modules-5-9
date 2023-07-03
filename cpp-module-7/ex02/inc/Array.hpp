#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>


template<typename T>
class Array {
	private:
		T* arr;
		unsigned int arrSize;

	public:
    	Array();
		Array(unsigned int size);
		Array(const Array& copy);
		~Array();
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;

};

#include "../src/Array.tpp"

#endif
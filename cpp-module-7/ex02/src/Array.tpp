#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "../inc/Array.hpp"

template<typename T>
Array<T>::Array() {
	T* arr = new T[0];
	this->arr = arr;
	this->arrSize = 0;
}

template<typename T>
Array<T>::Array(unsigned int size) {
	T* arr = new T[size];
	this->arr = arr;
	this->arrSize = size;
}

template<typename T>
Array<T>::~Array() {
	delete[] this->arr;
}

template<typename T>
Array<T>::Array(const Array& copy) {
	arr = new T[copy.arrSize];
	this->arrSize = copy.arrSize;
	for (unsigned int i = 0; i < copy.arrSize; i++)
		arr[i] = copy.arr[i];
	this->arr = arr;
	this->arrSize = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other){
	if (this == other)
		return *this;
	delete[] arr;
	arr = new T[other.arrSize];
	for (unsigned int i = 0; i < other.arrSize; i++)
		arr[i] = other.arr[i];
	this->arr = arr;	
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= this->arrSize)
		throw std::out_of_range("Index out of range");
	return this->arr[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= arrSize) {
		throw std::out_of_range("Index out of range");
	}
	return arr[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->arrSize;
}

#endif
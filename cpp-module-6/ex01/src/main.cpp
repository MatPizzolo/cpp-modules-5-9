#include "../inc/Serializer.hpp"
#include <iostream>

int main() {
	Data* data;
	data = new Data;
	Data* first;

	first = data;
	std::cout << "Data: " << data << std::endl;
	uintptr_t a = Serializer::serialize(data);
	std::cout << "Raw data: " << a << std::endl;
	data = Serializer::deserialize(a);
	std::cout << "Deserialized data: " << data << std::endl;

	std::cout << std::endl;

	std::cout << "Same" << std::endl;
	std::cout << first << std::endl;
	std::cout << data << std::endl;

	delete data;
}
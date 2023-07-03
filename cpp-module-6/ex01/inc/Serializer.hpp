#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>


struct Data {
	int n;
};

class Serializer {
	private:

	public:
		Serializer();
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
};

#endif
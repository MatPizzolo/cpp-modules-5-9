#include "../inc/Array.hpp"

#define MAX_VAL 750
#define GOOD_SIZE 100


class MyClass {
public:
	int value;

	MyClass() : value(0) {}
	MyClass(int val) : value(val) {}
};

struct MyStruct {
	float data;
};

enum MyEnum {
	RED,
	GREEN,
	BLUE
};

void big_test() {
	Array<MyClass> arr_myclass(GOOD_SIZE);
	Array<float> arr_float(GOOD_SIZE);
	Array<MyStruct> arr_struct(GOOD_SIZE);
	Array<MyEnum> arr_enum(GOOD_SIZE);

	// Fill the arrays with some test data
	for (int i = 0; i < GOOD_SIZE; i++) {
		arr_myclass[i] = MyClass(i);
		arr_float[i] = static_cast<float>(i * 0.5);
		arr_struct[i].data = i * 1.5;
		arr_enum[i] = static_cast<MyEnum>(i % 3);
	}

	for (int i = 0; i < GOOD_SIZE; i++) {
		std::cout << "arr_myclass[" << i << "] = " << arr_myclass[i].value << std::endl;
		std::cout << "arr_float[" << i << "] = " << arr_float[i] << std::endl;
		std::cout << "arr_struct[" << i << "].data = " << arr_struct[i].data << std::endl;
		std::cout << "arr_enum[" << i << "] = " << arr_enum[i] << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Before modifications:" << std::endl;
	std::cout << "arr_myclass[0].value = " << arr_myclass[0].value << std::endl;
	std::cout << "arr_float[1] = " << arr_float[1] << std::endl;
	std::cout << "arr_struct[2].data = " << arr_struct[2].data << std::endl;
	std::cout << "arr_enum[3] = " << arr_enum[3] << std::endl;
	std::cout << std::endl;

	// Modify array elements
	arr_myclass[0].value = 10;
	arr_float[1] += 2.5;
	arr_struct[2].data *= 2.0;
	arr_enum[3] = BLUE;

	std::cout << "After modifications:" << std::endl;
	std::cout << "Modified arr_myclass[0].value = " << arr_myclass[0].value << std::endl;
	std::cout << "Modified arr_float[1] = " << arr_float[1] << std::endl;
	std::cout << "Modified arr_struct[2].data = " << arr_struct[2].data << std::endl;
	std::cout << "Modified arr_enum[3] = " << arr_enum[3] << std::endl;
}

void ex_test() {

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return ;
		}
	}
	
	try {
		numbers[-2] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	try {
		numbers[MAX_VAL] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();

	delete [] mirror;
}

int main()
{
	big_test();
	return 0;
}
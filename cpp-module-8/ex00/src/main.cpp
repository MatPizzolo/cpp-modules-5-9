#include "../inc/easyfind.hpp"

int main() {
	int result;
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> numbersV(arr, arr + sizeof(arr) / sizeof(arr[0]));
	std::list<int> numbersL(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "Searching through vector" << std::endl;
	result = easyfind(numbersV, 4);
	if (result != -1)
		std::cout << "Element found: " << result << std::endl;
	else
		std::cout << "Element not found." << std::endl;

	std::cout << std::endl;

	std::cout << "Searching through list" << std::endl;
    result = easyfind(numbersL, 3);
    if (result != -1)
        std::cout << "Element found: " << result << std::endl;
    else
        std::cout << "Element not found." << std::endl;
}
#include "../inc/PmergeMe.hpp"
#include <ctime>

void printVector(const std::vector<int> &vec)
{
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i != vec.size() - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void printList(const std::list<int> &lst)
{
	std::list<int>::const_iterator it;
	for (it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool checkArg(std::string input)
{
	if (input.length() == 0)
		return false;
	std::istringstream iss(input);
	std::string token;
	while (iss >> token)
	{
		if (std::numeric_limits<int>::min() > std::atoi(token.c_str()))
			return false;
		else if (std::numeric_limits<int>::max() < std::atoi(token.c_str()))
			return false;
		if (std::atoi(token.c_str()) < 0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments.\nUsage: " << argv[0] << " \"expression\"" << std::endl;
		return 1;
	}
	if (!checkArg(argv[1]))
	{
		std::cerr << "Error" << std::endl;
		return 2;
	}
	std::cout << "Before: " << argv[1] << std::endl;
	clock_t start = clock();
	PmergeMe mergeSort;
	double xElements = mergeSort.numsToContainers(argv[1]);
	clock_t end = clock();
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	double sortTimeVec = mergeSort.sortVec();
	double sortTimeList = mergeSort.sortList();
	sortTimeVec += elapsedTime;
	sortTimeList += elapsedTime;
	std::cout << "After:  ";
	printVector(mergeSort._myVec);
	std::cout << "After:  ";
	printList(mergeSort._myList);
	std::cout << "Time to process a range of " << xElements << " elements with std::vector : " << sortTimeVec << "us" << std::endl;
	std::cout << "Time to process a range of " << xElements << " elements with std::list : " << sortTimeList << "us" << std::endl;
}

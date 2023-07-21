#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

// merge in sort algo for each container

double PmergeMe::numsToContainers(std::string nums) {
	std::istringstream iss(nums);
	std::string token;

	while (iss >> token) {
		_myList.push_back(std::atoi(token.c_str()));
		_myVec.push_back(std::atoi(token.c_str()));
	}
	double res = _myVec.size();
	return res;
}


double PmergeMe::sortVec() {
	clock_t start = clock();
	// merge in sort

	clock_t end = clock();
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsedTime);
}

double PmergeMe::sortList() {
	clock_t start = clock();
	// merge in sort

	clock_t end = clock();
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsedTime);
}


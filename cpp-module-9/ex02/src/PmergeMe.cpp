#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

double PmergeMe::numsToContainers(std::string nums)
{
	std::istringstream iss(nums);
	std::string token;

	while (iss >> token)
	{
		_myList.push_back(std::atoi(token.c_str()));
		_myVec.push_back(std::atoi(token.c_str()));
	}
	double res = _myVec.size();
	return res;
}

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
	for (Iterator i = begin; i != end; ++i)
	{
		typename Iterator::value_type key = *i;
		Iterator j = i;
		while (j != begin)
		{
			Iterator prev = j;
			--prev;
			if (key < *prev)
			{
				std::swap(*j, *prev);
			}
			else
			{
				break;
			}
			--j;
		}
	}
}

template <typename Iterator>
void merge(Iterator begin, Iterator mid, Iterator end)
{
	std::vector<typename Iterator::value_type> temp(std::distance(begin, end));
	Iterator left = begin, right = mid;
	typename std::vector<typename Iterator::value_type>::iterator tempIt = temp.begin();

	while (left != mid && right != end)
	{
		if (*left <= *right)
		{
			*tempIt = *left;
			++left;
		}
		else
		{
			*tempIt = *right;
			++right;
		}
		++tempIt;
	}

	tempIt = std::copy(left, mid, tempIt);
	std::copy(right, end, tempIt);
	std::copy(temp.begin(), temp.end(), begin);
}

template <typename Iterator>
void mergeInsertionSort(Iterator begin, Iterator end, int threshold)
{
	if (std::distance(begin, end) <= threshold)
	{
		insertionSort(begin, end);
	}
	else
	{
		Iterator mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		mergeInsertionSort(begin, mid, threshold);
		mergeInsertionSort(mid, end, threshold);
		merge(begin, mid, end);
	}
}

double PmergeMe::sortVec()
{
	clock_t start = clock();
	mergeInsertionSort(_myVec.begin(), _myVec.end(), 5);
	clock_t end = clock();
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsedTime);
}

double PmergeMe::sortList()
{
	clock_t start = clock();
	mergeInsertionSort(_myList.begin(), _myList.end(), 5);
	clock_t end = clock();
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsedTime);
}

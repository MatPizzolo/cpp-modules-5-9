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

// Function to perform binary search and find the insertion position
int binarySearchVec(const std::vector<int> &S, int element)
{
	int left = 0;
	int right = S.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (S[mid] == element)
		{
			return mid; // Element already exists in S
		}
		else if (S[mid] < element)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left; // Insert element at the left position
}

std::vector<int> mergeInsertionSortVec(const std::vector<int> &vec)
{
	int n = vec.size();
	if (n <= 1)
		return vec;

	// Pairing
	std::vector<int> largerElements;
	std::vector<std::vector<int> > pairs;
	for (int i = 0; i < n; i += 2)
	{
		std::vector<int> pair;
		if (i + 1 < n)
		{
			pair.push_back(vec[i]);
			pair.push_back(vec[i + 1]);
		}
		else
		{
			pair.push_back(vec[i]);
		}
		pairs.push_back(pair);
	}

	// Comparison and Sorting
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		int largerElement = std::max(pairs[i][0], pairs[i][1]);
		largerElements.push_back(largerElement);
	}

	// Recursion
	std::vector<int> sortedLargerElements = mergeInsertionSortVec(largerElements);

	// Insertion
	std::vector<int> S;
	for (int i = 0; i < n; ++i)
	{
		int insertionPosition = binarySearchVec(S, vec[i]);
		S.insert(S.begin() + insertionPosition, vec[i]);
	}

	return S;
}

std::list<int>::iterator binarySearchList(std::list<int> &S, int element)
{
	std::list<int>::iterator it;
	for (it = S.begin(); it != S.end(); ++it)
	{
		if (*it >= element)
			return it;
	}
	return S.end();
}

std::list<int> mergeInsertionSortList(const std::list<int> &lst)
{
    std::list<int> result;

    if (lst.size() <= 1)
    {
        return lst; // Base case: already sorted or empty list
    }

    // Create pairs
    std::list<std::list<int> > pairs;
    std::list<int> currentPair;
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        currentPair.push_back(*it);
        if (currentPair.size() == 2)
        {
            pairs.push_back(currentPair);
            currentPair.clear();
        }
    }
    if (!currentPair.empty())
    {
        pairs.push_back(currentPair);
    }

    // Comparison and Sorting
    std::list<int> largerElements;
    for (std::list<std::list<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->size() == 2)
        {
            largerElements.push_back(std::max(it->front(), it->back()));
        }
        else
        {
            largerElements.push_back(it->front());
        }
    }

    // Recursion
    std::list<int> sortedLargerElements = mergeInsertionSortList(largerElements);

    // Insertion
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::list<int>::iterator insertionPosition = binarySearchList(result, *it);
        result.insert(insertionPosition, *it);
    }

    return result;
}

double PmergeMe::sortVec()
{
	clock_t start = clock();
	_myVec = mergeInsertionSortVec(_myVec);
	clock_t end = clock();
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsedTime);
}

double PmergeMe::sortList()
{
	clock_t start = clock();
	_myList = mergeInsertionSortList(_myList);
	clock_t end = clock();
	double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	return (elapsedTime);
}

PmergeMe::PmergeMe(PmergeMe &copy)
{
	this->_myList = copy._myList;
	this->_myVec = copy._myVec;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	this->_myList = other._myList;
	this->_myVec = other._myVec;
	return *this;
}
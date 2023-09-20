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
	// Loop through the elements in the range.
	for (Iterator i = begin; i != end; ++i)
	{
		// Store the current element in the 'key' variable.
		typename Iterator::value_type key = *i;
		
		// Initialize a pointer 'j' to the current element.
		Iterator j = i;
		
		// While 'j' is not at the beginning of the range and 'key' is less than the previous element.
		while (j != begin)
		{
			// Create a pointer 'prev' to the previous element.
			Iterator prev = j;
			--prev;
			
			// If 'key' is less than the previous element, swap them.
			if (key < *prev)
			{
				std::swap(*j, *prev);
			}
			else
			{
				// If 'key' is greater or equal to the previous element, break the loop.
				break;
			}
			
			// Move 'j' one position to the left.
			--j;
		}
	}
}

// This is a function to merge two sorted ranges defined by iterators.
template <typename Iterator>
void merge(Iterator begin, Iterator mid, Iterator end)
{
	// Create a temporary vector to store the merged result.
	std::vector<typename Iterator::value_type> temp(std::distance(begin, end));
	
	// Initialize pointers 'left' and 'right' to the beginning of the two sub-ranges.
	Iterator left = begin, right = mid;
	
	// Initialize an iterator 'tempIt' to the beginning of the temporary vector.
	typename std::vector<typename Iterator::value_type>::iterator tempIt = temp.begin();
	
	// Merge the two sub-ranges into the temporary vector.
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
	
	// Copy any remaining elements from the left and right sub-ranges.
	tempIt = std::copy(left, mid, tempIt);
	std::copy(right, end, tempIt);
	
	// Copy the merged result back to the original range 'begin' to 'end'.
	std::copy(temp.begin(), temp.end(), begin);
}

template <typename Iterator>
void mergeInsertionSort(Iterator begin, Iterator end, int threshold)
{
	// If the range size is small enough, use insertion sort.
	if (std::distance(begin, end) <= threshold)
	{
		insertionSort(begin, end);
	}
	else
	{
		// Otherwise, split the range in half and recursively apply mergeInsertionSort.
		Iterator mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		mergeInsertionSort(begin, mid, threshold);
		mergeInsertionSort(mid, end, threshold);
		
		// Merge the two sorted sub-ranges.
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

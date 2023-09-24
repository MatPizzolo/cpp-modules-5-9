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
int binarySearch(const std::vector<int>& S, int element) {
    int left = 0;
    int right = S.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (S[mid] == element) {
            return mid;  // Element already exists in S
        } else if (S[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;  // Insert element at the left position
}

// Function to perform Merge-Insertion Sort
std::vector<int> mergeInsertionSort(const std::vector<int>& X) {
    int n = X.size();
    if (n <= 1) {
        return X;  // Base case: already sorted or empty vector
    }

    // Pairing
    std::vector<int> largerElements;
    std::vector<std::vector<int> > pairs;
    for (int i = 0; i < n; i += 2) {
        std::vector<int> pair;
        if (i + 1 < n) {
            pair.push_back(X[i]);
            pair.push_back(X[i + 1]);
        } else {
            pair.push_back(X[i]);
        }
        pairs.push_back(pair);
    }

    // Comparison and Sorting
    for (size_t i = 0; i < pairs.size(); ++i) {
        int largerElement = std::max(pairs[i][0], pairs[i][1]);
        largerElements.push_back(largerElement);
    }

    // Recursion
    std::vector<int> sortedLargerElements = mergeInsertionSort(largerElements);

    // Insertion
    std::vector<int> S;
    int firstElementOfS = sortedLargerElements[0];
    for (int i = 0; i < n; ++i) {
        if (X[i] != firstElementOfS) {
            int insertionPosition = binarySearch(S, X[i]);
            S.insert(S.begin() + insertionPosition, X[i]);
        }
    }
    
    // Insert the first element (smallest) of the larger elements
    S.insert(S.begin(), firstElementOfS);
    
    return S;
}

double PmergeMe::sortVec()
{
    clock_t start = clock();
    // mergeInsertionSort(_myVec.begin(), _myVec.end(), 5);
    _myVec = mergeInsertionSort(_myVec);
    clock_t end = clock();
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    return (elapsedTime);
}

double PmergeMe::sortList()
{
    clock_t start = clock();
    // mergeInsertionSort(_myList.begin(), _myList.end(), 5);
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
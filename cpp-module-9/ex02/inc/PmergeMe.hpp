#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <cstdlib>

class PmergeMe {
	private:

	public:
		std::list<int> _myList;
		std::vector<int> _myVec;
		PmergeMe();
		~PmergeMe();

		double numsToContainers(std::string nums);
		double sortVec();
		double sortList();
};

#endif
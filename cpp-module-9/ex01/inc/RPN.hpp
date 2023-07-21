#ifndef RPN_H
#define RPN_H

#include <stack>
#include <iostream>
#include <sstream>

class RPN {
	private:
		std::stack<int> _myStack;

	public:
		RPN();
		~RPN();

		void startStack(std::string nums);
		double getResult();
};

#endif
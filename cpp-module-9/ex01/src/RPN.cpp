#include "../inc/RPN.hpp"

bool isNumber(const std::string& str) {
	return !str.empty() && str.find_first_not_of("0123456789.") == std::string::npos;
}

bool isOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

RPN::RPN() {}
RPN::~RPN() {}

void RPN::startStack(std::string nums) {
	std::istringstream iss(nums);
	std::string token;

	while (iss >> token) {
		if (isNumber(token)) {
			double num = std::stod(token);
			_myStack.push(num);
		} else if (isOperator(token[0])) {
			if (_myStack.size() < 2) {
				std::cerr << "Error: Insufficient operands for operator " << token << std::endl;
				return;
			}
			double operand2 = _myStack.top();
			_myStack.pop();
			double operand1 = _myStack.top();
			_myStack.pop();
				double result;
			if (token == "+")
				result = operand1 + operand2;
			else if (token == "-")
				result = operand1 - operand2;
			else if (token == "*")
				result = operand1 * operand2;
			else
				result = operand1 / operand2;
			_myStack.push(result);
		}
	}
}

double RPN::getResult() {
	if (_myStack.empty()) {
		std::cerr << "Error: Stack is empty" << std::endl;
		return 0.0;
	}
	double result = _myStack.top();
	_myStack.pop();
	if (!_myStack.empty()) {
		std::cerr << "Error: Invalid RPN expression" << std::endl;
		return 0.0;
	}
	return result;
}
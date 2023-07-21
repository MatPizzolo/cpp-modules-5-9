#include "../inc/RPN.hpp"

bool isNumber(const std::string& str);
bool isOperator(char ch);

bool checkArg(std::string input) {
	std::stack<int> countStack;

	for (size_t i = 0; i < input.size(); ++i) {
		char ch = input[i];

		if (std::isdigit(ch)) {
			countStack.push(1);
		} else if (isOperator(ch)) {
			if (countStack.size() < 2) {
				return false; // Not enough operands for an operator
			}
			countStack.pop();
			countStack.pop();
			countStack.push(1);
		} else if (std::isspace(ch)) {
			// Ignore spaces
		} else {
			return false; // Invalid character in the input
		}
	}

	return countStack.size() == 1;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Invalid number of arguments. Usage: " << argv[0] << " \"expression\"" << std::endl;
		return 1;
	}
	if (!checkArg(argv[1])) {
		std::cerr << "Invalid input. The expression is not a valid RPN." << std::endl;
		return 2;
	}
	RPN rpnCalculator;
	rpnCalculator.startStack(input);
	double result = rpnCalculator.getResult();
	std::cout << "Result: " << result << std::endl;
}
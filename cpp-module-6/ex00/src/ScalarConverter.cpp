#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { 
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

bool invalidInput(const std::string& literal) {
	// Check for consecutive signs, sign after number, or number after letter
	size_t length = literal.length();
	for (size_t i = 0; i < length; ++i) {
		char current = literal[i];
		if (current == '+' || current == '-') {
			if (i > 0 && (literal[i - 1] == '+' || literal[i - 1] == '-' || isdigit(literal[i - 1]))) {
				return true;
			}
			if (i < length - 1 && !isdigit(literal[i + 1]) && literal[i + 1] != '.' && literal[i + 1] != 'f') {
				return true;
			}
		} else if (isalpha(current)) {
			if (isdigit(literal[i - 1]) && current != 'f') {
				return true;
			}
		}
	}
	return false;
}


void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Invalid input: Empty literal." << std::endl;
		return;
	} else if (invalidInput(literal)) {
		std::cout << "Invalid input" << std::endl;
		return;
	}

	const std::string specialTypes[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};

	std::string charValue = "";
	int intValue = 0;
	float floatValue = 0.0f;
	double doubleValue = 0.0;

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		charValue = literal[0];
		intValue = static_cast<int>(charValue[0]);
		floatValue = static_cast<float>(charValue[0]);
		doubleValue = static_cast<double>(charValue[0]);

		std::cout << "char: " << charValue << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << floatValue << ".0f" << std::endl;
		std::cout << "double: " << doubleValue << ".0" << std::endl;
		return;
	}

	intValue = std::atoi(literal.c_str());

	if (literal[literal.length() - 1] == 'f') {
		floatValue = std::atof(literal.c_str());
		doubleValue = static_cast<double>(floatValue);
	} else {
		doubleValue = std::stod(literal.c_str());
		floatValue = static_cast<float>(doubleValue);
	}
	
	if (std::find(std::begin(specialTypes), std::end(specialTypes), literal) != std::end(specialTypes)) {
		charValue = "impossible";
	}

	if (charValue.empty() && std::isprint(intValue)) {
		charValue = "'" + std::string(1, static_cast<char>(intValue)) + "'";
	} else if (charValue.empty()) {
		charValue = "Non displayable";
	}

	std::cout << "char: " << charValue << std::endl;

	if (charValue == "impossible") {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << intValue << std::endl;
	}

	if (charValue == "impossible" && floatValue == 0.0f) {
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	} else {
		if (charValue != "impossible" && floatValue - static_cast<int>(floatValue) == 0.0f) {
			std::cout << "float: " << floatValue << ".0f" << std::endl;
			std::cout << "double: " << doubleValue << ".0" << std::endl;
		} else {
			std::cout << "float: " << floatValue << "f" << std::endl;
			std::cout << "double: " << doubleValue << std::endl;
		}
	}
}


bool ScalarConverter::isLiteralChar(char c) {
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}


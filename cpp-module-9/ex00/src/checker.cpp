#include "../inc/BitcoinExchange.hpp"

std::vector<std::string> split(const std::string& input, char delimiter) {
    std::vector<std::string> result;
    std::istringstream iss(input);
    std::string token;

    while (std::getline(iss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}

bool specificDateChecker(std::string date, int value) {
	if (date.length() == 0 || date == "") {
		std::cout << "Error: Invalid date format." << std::endl;
		return false;
	}
	if (value < 0) {
		std::cout << "Error: Value cannot be negative." << std::endl;
		return false;
	}
	return true;
}

bool dateChecker(std::string file) {
	std::ifstream fd(file.c_str(), std::fstream::in);
	std::string line;
	std::string date;
	int value;
	while (std::getline(fd, line)) {
		std::vector<std::string> parts = split(line, ',');
		date = parts[0];
		value = std::atoi(parts[1].c_str());
		if (!specificDateChecker(date, value)) {
			fd.close();
			return false;
		}
	}
	fd.close();
	return true;
}

bool argChecker(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: Invalid nbr of args." << std::endl;
		return false;
	}
	std::ifstream fd(argv[1], std::ifstream::in);
	if (!fd.is_open()) {
		std::cout << "Error: Could not open the file." << std::endl;
		return false;
	}
	// check first line
	fd.close();
	return true;
}
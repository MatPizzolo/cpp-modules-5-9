#include "../inc/BitcoinExchange.hpp"

std::string ft_splitDate(std::string line, std::string *vale, char delimiter) {
	std::string date = "";
	std::string val = "";
	int i = -1;
	while (line[++i] != delimiter)
		date += line[i];
	while (line[++i])
		val += line[i];
	*vale = val;
	return date;
}

bool specificDateChecker(std::string date, double value) {
	// Check year-month-day
	// std::cout << date << " - " << value << std::endl;
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
	std::string val;
	double value;
	// check first line
	// check it is correctly as date | value
	while (std::getline(fd, line)) {
		date = ft_splitDate(line, &val, ',');
		try {
			value = std::stof(val.c_str());
		} catch (std::exception &e) {}
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
	fd.close();
	return true;
}

bool dataCsvChecker() {
	std::ifstream fd("data.csv", std::ifstream::in);
	if (!fd.is_open()) {
		std::cout << "Error: Could not open the csv file." << std::endl;
		return false;
	}
	fd.close();
	if (!dateChecker("data.csv"))
		return false;
	return true;
}

// bool argInputChecker(std::string file) {

// }
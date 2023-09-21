#include "../inc/BitcoinExchange.hpp"

bool checkExtraChars(const std::string &str)
{
	bool spaceEncountered = false;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (spaceEncountered)
		{
			if (*it != ' ')
				return false;
		}
		if (!isdigit(*it))
			spaceEncountered = true;
	}
	return true;
}

std::string ft_splitDate(std::string line, std::string *vale, char delimiter)
{
	std::string date = "";
	std::string val = "";
	int i = -1;
	while (line[++i] != delimiter && line[i])
		date += line[i];
	while (line[++i])
		val += line[i];
	*vale = val;
	return date;
}

bool isValidDate(int year, int month, int day)
{
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if ((year > 2023))
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	return true;
}

bool specificDateChecker(std::string line)
{
	if (line.length() == 0 || line == "")
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	std::string val, date;
	double value;
	date = ft_splitDate(line, &val, '|');
	date.erase(date.find_last_not_of(" ") + 1);
	int year, month, day;
	std::istringstream dateStream(line);
	std::string lineCopy = line;
	try
	{
		std::getline(dateStream, line, '-');
		year = std::stoi(line);

		std::getline(dateStream, line, '-');
		month = std::stoi(line);

		if (std::getline(dateStream, line, '|'))
		{
			day = std::stoi(line);
			if (!checkExtraChars(line))
			{
				std::cout << "Error: bad input => " << lineCopy << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Error: bad input => " << lineCopy << std::endl;
			return false;
		}

		if (!isValidDate(year, month, day))
		{
			std::cout << "Error: bad input => " << lineCopy << std::endl;
			return false;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: bad input => " << lineCopy << std::endl;
		return false;
	}
	try
	{
		value = std::stof(val.c_str());
	}
	catch (std::exception &e)
	{

		std::cout << "Error: bad input => " << lineCopy << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > std::numeric_limits<int>::max())
	{
		std::cout << "Error: too large number." << std::endl;
		return false;
	}
	return true;
}

bool argChecker(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid nbr of args." << std::endl;
		return false;
	}
	std::ifstream fd(argv[1], std::ifstream::in);
	if (!fd.is_open())
	{
		std::cout << "Error: Could not open the file." << std::endl;
		return false;
	}
	fd.close();
	return true;
}

bool dataCsvChecker()
{
	std::ifstream fd("data.csv", std::ifstream::in);
	if (!fd.is_open())
	{
		std::cout << "Error: Could not open the csv file." << std::endl;
		return false;
	}
	fd.close();
	return true;
}

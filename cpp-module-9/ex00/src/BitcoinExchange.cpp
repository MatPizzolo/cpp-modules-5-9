#include "../inc/BitcoinExchange.hpp"

void printMapValues(const std::map<std::string, double> &btcMap)
{
	std::map<std::string, double>::const_iterator it;
	for (it = btcMap.begin(); it != btcMap.end(); ++it)
	{
		std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
	}
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::startMap()
{
	std::cout << "startMap" << std::endl;
	std::ifstream fd("data.csv", std::fstream::in);
	std::string line;
	std::string date;
	std::string val;
	double value;
	while (std::getline(fd, line))
	{
		date = ft_splitDate(line, &val, ',');
		try
		{
			value = std::stof(val.c_str());
		}
		catch (std::exception &e)
		{
		}
		_btcMap.insert(std::pair<std::string, double>(date, value));
	}
}

void BitcoinExchange::showPrices(std::string file)
{
	std::ifstream fd(file, std::fstream::in);
	std::string date;
	std::string val;
	std::string line;
	double value;
	double res;
	std::map<std::string, double>::iterator it;
	// printMapValues(_btcMap);
	std::getline(fd, line);
	while (std::getline(fd, line))
	{
		if (specificDateChecker(line))
		{
			date = ft_splitDate(line, &val, '|');
			date.erase(date.find_last_not_of(" ") + 1);
			try
			{
				value = std::stof(val.c_str());
			}
			catch (std::exception &e){}
			it = _btcMap.find(date);
			if (it != _btcMap.end())
			{
				res = value * it->second;
				std::cout << date << " => " << value << " = " << res << std::endl;
			}
			else
			{
				it = _btcMap.lower_bound(date);
				res = value * it->second;
				std::cout << date << " => " << value << " = " << res << std::endl;
			}
		}
	}
}
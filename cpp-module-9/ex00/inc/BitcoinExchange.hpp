#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> _btcMap;

	public:
		// Constructor & Destructor
		BitcoinExchange();
		~BitcoinExchange();

		// Chanonical

		// Member Functions
		void startMap();
		void showPrices(std::string file);
};

std::string ft_splitDate(std::string line, std::string *vale, char delimiter);

#endif
#include "../inc/BitcoinExchange.hpp"

bool argChecker(int argc, char *argv[]);
bool dataCsvChecker();

int main (int argc, char *argv[]) {
	if (!argChecker(argc, argv))
		return (1);
	if (!dataCsvChecker())
		return (2);
	BitcoinExchange BTC;
	BTC.startMap();
	BTC.showPrices(argv[1]);
}
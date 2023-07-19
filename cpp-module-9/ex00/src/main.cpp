#include "../inc/BitcoinExchange.hpp"

int main (int argc, char *argv[]) {
	if (!argChecker(argc, argv))
		return (1);
	if (!dateChecker(argv[1]))
		return (2);
	// get price

}

#include "../inc/Span.hpp"

void print_vector(Span aa) {
	int i = -1;
	int size = static_cast<int>(aa.vec.size());
	while (++i < size)
		std::cout << aa.vec[i] << " ";
	std::cout << std::endl;
}

void exercise_test() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;	
}

void big_test() {
	Span sp(3);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(5);

	std::cout << "Error will occur" << std::endl;
	sp.addNumber(11);
	std::cout << std::endl;

	std::cout << "Adding more than 10,000 nbrs" << std::endl;
	Span my(1000000);
	my.addLotsOfNumbers(500, 4);
	my.addLotsOfNumbers(500, 2);
	my.addLotsOfNumbers(10000, 8);
	print_vector(my);
}

int main()
{
	exercise_test();
	std::cout << std::endl;
	big_test();
}
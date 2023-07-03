#include "../inc/Base.hpp"
#include <iostream>

Base::~Base() {}

Base* generate(void) {
    int randomNum = std::rand() % 3;

    Base* instance = nullptr;
    if (randomNum == 0) {
        instance = new A();
		std::cout << "A generated" << std::endl;
	} else if (randomNum == 1) {
        instance = new B();
		std::cout << "B generated" << std::endl;
    } else {
        instance = new C();
		std::cout << "C generated" << std::endl;
    }
    return instance;
}

void identify(Base* p) {
	if(dynamic_cast<A*>(p) != nullptr)
		std::cout << "P is of base A" << std::endl;
	if(dynamic_cast<B*>(p) != nullptr)
		std::cout << "P is of base B" << std::endl;
	if(dynamic_cast<C*>(p) != nullptr)
		std::cout << "P is of base C" << std::endl;
}


void identify(Base& p) {
   try {
        A& a = dynamic_cast<A&>(p);
		(void)a;
        std::cout << "p is of base A" << std::endl;
		return ;
    } catch (std::bad_cast&) {}
	try {
        B& b = dynamic_cast<B&>(p);
		(void)b;
        std::cout << "p is of base B" << std::endl;
		return ;
    } catch (std::bad_cast&) {}
	try {
        C& c = dynamic_cast<C&>(p);
		(void)c;
        std::cout << "p is of base C" << std::endl;
		return ;
    } catch (std::bad_cast&) {}
}

int main() {
	std::srand(time(NULL));

	Base* ra;
	Base* ran;
	Base* rand;
	Base* rando;
	Base* random;

	std::cout << "Identify with pointer" << std::endl;
	ra = generate();
	identify(ra);
	std::cout << std::endl;
	ran = generate();
	identify(ran);
	std::cout << std::endl;
	rand = generate();
	identify(rand);
	std::cout << std::endl;

	std::cout << "Identify with reference" << std::endl;
	rando = generate();
	identify(rando);
	std::cout << std::endl;
	random = generate();
	identify(random);

	delete ra;
    delete ran;
    delete rand;
    delete rando;
    delete random;
}
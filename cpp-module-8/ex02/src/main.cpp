
#include "../inc/MutantStack.hpp"

#include <list>

void test_with_vec()
{
    std::cout << "/ ***** MutantStack ***** /" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << std::endl;
    std::cout << "/ ***** Vector ***** /" << std::endl;

    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(17);

    std::cout << vec.back() << std::endl;

    vec.pop_back();
    std::cout << vec.size() << std::endl;

    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    // [...]
    vec.push_back(0);

    std::vector<int>::iterator vec_it = vec.begin();
    std::vector<int>::iterator vec_ite = vec.end();

    while (vec_it != vec_ite)
    {
        std::cout << *vec_it << std::endl;
        ++vec_it;
    }
}

void test_with_lst() {
    std::cout << "/ ***** MutantStack ***** /" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    /* -------------------------------------------------------------------- */

    std::cout << std::endl;
    std::cout << "/ ***** List ***** /" << std::endl;

    std::list< int > lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);

    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++it;
    --it;
    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << std::endl;
        ++lst_it;
    }
    std::list<int> l(lst);
}

int main() {
	test_with_lst();
	// test_with_vec();

}
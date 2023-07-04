#include "../inc/MutantStack.hpp"

// template<typename T>
// MutantStack<T>::MutantStack(): std::stack<T>() {}
// MutantStack::MutantStack(const MutantStack& copy) {}
// MutantStack &MutantStack::operator=(const MutantStack& other) {}

template<typename T>
void* MutantStack<T>::begin()
{
    if (std::stack<T>::empty())
        return NULL;

    typename std::stack<T>::container_type::value_type* firstElementPtr = &(std::stack<T>::top());
    return static_cast<void*>(firstElementPtr);
}

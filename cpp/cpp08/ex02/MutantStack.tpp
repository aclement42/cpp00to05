#include "MutantStack.hpp"

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
    return (std::stack<T>::c.crbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
    return (std::stack<T>::c.crend());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (std::stack<T>::c.rend());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return (std::stack<T>::c.cend());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return (std::stack<T>::c.cbegin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    std::cout << "default constructor called" << std::endl;
    return ;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & obj) : std::stack<T>(obj)
{
    std::cout << "copy constructor called" << std::endl;
    return ;
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & rhs)
{
    std::cout << "assign constructor called" << std::endl;
    if (this != &rhs)
        std::stack<T>::operator=(rhs);
    return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "default destructor called" << std::endl;
    return ;
}




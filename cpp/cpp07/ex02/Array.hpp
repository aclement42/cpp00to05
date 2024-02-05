#pragma once

#include <iostream>
#include <cstdlib>

template<typename T>

class Array
{
private:
    unsigned int _size;
    T   *_element;
public:
    Array(void);
    Array(unsigned int n);
    Array(Array const & obj);
    ~Array(void);

    Array & operator=(Array const & rhs);
    T & operator[](unsigned int index);

    unsigned int size(void) const;

    class ErrorIndex : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Invalid index");
        }
    };
    
};

template<typename T>
T & Array<T>::operator[](unsigned int index)
{
    if (index > this->_size)
        throw Array::ErrorIndex();
    return (this->_element[index]);
}

template<typename T>
Array<T>::Array(Array<T> const & obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs)
{
    this->_size = rhs._size;
    this->_element = rhs._element;
    return (*this);
}

template<typename T>
Array<T>::Array() : _size(0), _arr(new T[0])
{
    std::cout << "default constructor is called" << std::endl;
    return ;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n])
{
    std::cout << "Unsigned int constructor is called" << std::endl;
    return ;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _arr;
    std::cout << "default destructor is called" << std::endl;
}

template<typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}
#pragma once

#include <iostream>
#include <cstdlib>

template<typename T>

class Array
{
private:
    T   *_arr;
    unsigned int _size;
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
    if (index < 0 || index >= this->_size)
        throw Array::ErrorIndex();
    return (this->_arr[index]);
}

template<typename T>
Array<T>::Array(Array<T> const & obj) : _arr(new T[obj._size]), _size(obj._size)
{
    std::cout << "Copy constructor called" << std::endl;
    for (unsigned int i = 0; i < _size; i++)
        this->_arr[i] = obj._arr[i];
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs)
{
    if (this != &rhs)
    {
        delete[] (this->_arr);
        this->_size = rhs._size;
        this->_arr = new T[this->_size];
        for (unsigned int i = 0; i < rhs._size; i++)
            this->_arr[i] = rhs._arr[i];
    }
    return (*this);
}

template<typename T>
Array<T>::Array() :  _arr(NULL), _size(0)
{
    std::cout << "default constructor is called" << std::endl;
    return ;
}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
    std::cout << "Unsigned int constructor is called" << std::endl;
    return ;
}

template<typename T>
Array<T>::~Array()
{
    delete[] this->_arr;
    std::cout << "default destructor is called" << std::endl;
}

template<typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}

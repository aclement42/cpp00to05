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
    Array(void) : _arr(NULL), _size(0)
    {
        std::cout << "default constructor is called" << std::endl;
        return ;
    };
    Array(unsigned int n): _arr(new T[n]), _size(n)
    {
        std::cout << "Unsigned int constructor is called" << std::endl;
        return ;
    };
    Array(Array const & obj) : _arr(new T[obj._size]), _size(obj._size)
    {
        std::cout << "Copy constructor called" << std::endl;
        for (unsigned int i = 0; i < _size; i++)
            this->_arr[i] = obj._arr[i];
    };
    ~Array(void)
    {
        delete[] this->_arr;
        std::cout << "default destructor is called" << std::endl;
    };

    Array & operator=(Array const & rhs)
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
    };
    T & operator[](unsigned int index)
    {
        if (index >= this->_size)
            throw Array::ErrorIndex();
        return (this->_arr[index]);
    };

    unsigned int size(void) const
    {
        return (this->_size);
    };

    class ErrorIndex : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Invalid index");
        }
    };
    
};

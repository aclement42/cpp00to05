#pragma once

#include <iostream>

template<typename T>

class Array
{
private:
    /* data */
public:
    Array<T>(void);
    Array<T>(unsigned int);
    Array<T>(Array<T> const & obj);
    Array<T> & operator=(Array<T> const & rhs);
    ~Array<T>(void);

    int size(void) const;
};


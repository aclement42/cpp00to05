#pragma once

#include <iostream>

template<typename Y>
void  add_two(Y &x)
{
    x += 2;
    // std::cout << "add2:" << x << std::endl;
}

template<typename Y>
void foo(Y &element)
{
    std::cout << element << std::endl;
}

template< typename U, typename V >
void    iter(U *addr, int lenght, void (*f)(V&))
{
    if (!addr || !lenght)
    {
        std::cout << "non empty array is needed here..." << std::endl;
        return ;
    }
    else
    {
        for (int i = 0; i < lenght; i++)
            f((addr[i]));
    }
}


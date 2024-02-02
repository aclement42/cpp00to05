#pragma once

#include <iostream>

template< typename U >
void foo(U t)
{
    std::cout << "foo: " << t << std::endl;
}

template< typename U, typename T >
void    iter(U *addr, int lenght, void foo(T))
{
    if (!addr || !lenght)
    {
        std::cout << "non empty array is needed here..." << std::endl;
        return ;
    }
    else
    {
        for (int i = 0; i < lenght; i++)
            foo(addr[i]);
    }
}


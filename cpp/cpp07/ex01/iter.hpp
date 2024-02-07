#pragma once

#include <iostream>

template<typename Y>
void  add_two(Y &x)
{
    x += 2;
}

template<typename Y>
void  add_two2(Y &x)
{
    for (int i = 0; x[i]; i++)
        add_two(x[i]);
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


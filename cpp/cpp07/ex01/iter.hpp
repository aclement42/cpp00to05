#pragma once

#include <iostream>

//template< typename U >
// void foo(U t)
// {
    // std::cout << "foo: " << t << std::endl;
// }
template<typename U, typename V>
U foo(V param)
{
    //(void)param;
    U nb = param;
    //while (nb < 10)
    std::cout << static_cast<U>(param) << std::endl;
    return (nb);
}

template<typename Y>
void foo(Y param)
{
    std::cout << param << std::endl;
    return ;
}

template< typename U, typename V >
void    iter(U *addr, int lenght, void (*foo)(V &))
{
    if (!addr || !lenght)
    {
        std::cout << "non empty array is needed here..." << std::endl;
        return ;
    }
    else
    {
        for (int i = 0; i < lenght; i++)
            foo((addr[i]));
    }
}


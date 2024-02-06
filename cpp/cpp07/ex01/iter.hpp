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
    int nb = static_cast<U>(param);
//
    //while (nb < 10)
    //{
        std::cout << nb << std::endl;
      //  nb++;
    // }
    return (nb);
   // return ;
}

template< typename U, typename V, typename W >
void    iter(U *addr, int lenght, W (*foo)(V))
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


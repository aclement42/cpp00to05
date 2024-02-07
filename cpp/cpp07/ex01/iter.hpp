#pragma once

#include <iostream>

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


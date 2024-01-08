#include <iostream>
#include "Sample.class.hpp"

//ds la class sample je souhaite acceder au construc sample
Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;
    return;
}

//ds la class sample je souhaite acceder au desstruc ~sample
Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}
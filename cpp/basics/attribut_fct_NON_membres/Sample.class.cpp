#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
    std::cout << "constructor called" << std::endl;
    Sample::_NbInst += 1;

    return;
}

Sample::~Sample(void)
{
    std::cout << "destructor called" << std::endl;
    Sample::_NbInst += -1;

    return;
}

int Sample::getNbInst(void)
{
    return (Sample::_NbInst);
}
//jamais faire appel au pointeur this dans fct non membre

int Sample::_NbInst = 0;
//init dun attribut static!!
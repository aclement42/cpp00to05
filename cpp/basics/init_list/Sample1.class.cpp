#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1(char p1, int p2, float p3)
{
    std::cout << "Constructor called" << std::endl;
    //l'attribu a1 de mon instance courante soit egale a p1, ect
    this->a1 = p1;
    std::cout << "this->a1 = " << this->a1 << std::endl;

    this->a2 = p2;
    std::cout << "this->a2 = " << this->a2 << std::endl;

    this->a3 = p3;
    std::cout << "this->a3 = " << this->a3 << std::endl;

    return;
    //faire les assignations a la main
}

Sample1::~Sample1(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}
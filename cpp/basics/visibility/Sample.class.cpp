#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
    std::cout << "constructor called" << std::endl;

    this->publicFoo = 0;
    std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
    this->_privateFoo = 0;
    std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

    this->publicBar();
    this->_privateBar();

    return ;
}

Sample::~Sample(void)
{
    std::cout << "destructor called" << std::endl;
    return ;
}

void    Sample::publicBar(void)const
{
    std::cout << "member fct publicBar called" << std::endl;
    return;
}

void    Sample::_privateBar(void)const
{
    std::cout << "member fct _privateBar called" << std::endl;
    return;
}
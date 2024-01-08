#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
    std::cout << "constrcutor called" << std::endl;

    this->setFoo(0);
    std::cout << "this->getFoo: " << this->getFoo() << std::endl;

    return;
}

Sample::~Sample(void)
{
    std::cout << "destrcutor called" << std::endl;
    return;
}

int    Sample::getFoo(void)const
{
    return (this->_foo);
}

void    Sample::setFoo(int v)
{
    if (v >= 0)
        this->_foo = v;
    return;
}
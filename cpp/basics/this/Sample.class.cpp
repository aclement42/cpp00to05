#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;

    this->foo = 42;//pointeur qui pointe sur linstance courante
    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar();//appel dune fonction membre de mon instance courante 
    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}
void    Sample::bar(void)
{
    std::cout << "Member function bar called" << std::endl;
    return;
}

//this est donc un pointeur special de linstance courante
//si on veut faire reference a notre instance courante : this
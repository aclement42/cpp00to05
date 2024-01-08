#include <iostream>
#include "Sample.class.hpp"

int main()
{
    Sample  instance;

    instance.foo = 42;
    std::cout << "instance.foo " << instance.foo << std::endl;

    instance.bar();
    //appel de la fonction membre bar de mon instance de la class sample
    return (0);
}
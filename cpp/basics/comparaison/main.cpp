#include <iostream>
#include "Sample.class.hpp"

int main()
{
    //pas meme adress mais meme contenus
    Sample  instance1(42);
    Sample  instance2(42);

    //if (&instance1 == &instance1)
    //    std::cout << "instance1 & instance1 are physically equal" << std::endl;
    //else
    //    std::cout << "instance1 & instance1 are not physically equal" << std::endl;

    if (&instance1 == &instance2)
        std::cout << "instance1 & instance2 are physically equal" << std::endl;
    else
        std::cout << "instance1 & instance2 are not physically equal" << std::endl;

    if (instance1.compare(&instance1) == 0)
        std::cout << "instance1 & instance1 are strcut equal" << std::endl;
    else
        std::cout << "instance1 & instance1 are not strcut equal" << std::endl;
    if (instance1.compare(&instance2) == 0)
        std::cout << "instance1 & instance2 are strcut equal" << std::endl;
    else
        std::cout << "instance1 & instance2 are not strcut equal" << std::endl;

}
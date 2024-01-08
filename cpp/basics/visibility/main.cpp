#include "Sample.class.hpp"
#include <iostream>

int main()
{
    Sample  instance;

    instance.publicFoo = 42;
    std::cout << "instance publicfoo: " << instance.publicFoo << std::endl;

    instance.publicBar();

    return (0);
}

/*a ne pas faire
int main()
{
    Sample  instance;

    instance.publicFoo = 42;
    std::cout << "instance publicfoo: " << instance.publicFoo << std::endl;
 !!!   instance._privateFoo = 42;!!!!
 !!!   std::cout << "instance _privatefoo: " << instance._privateFoo << std::endl;
    instance.publicBar();
 !!!   instance._privateBar();

    return (0);
}*/
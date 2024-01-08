#include "Sample1.class.hpp"
#include "Sample2.class.hpp"
#include <iostream>

int main(void)
{
    Sample1 instance1('a', 42, 4.2f);
    Sample2 instance2('z', 13, 3.14f);

    return (0);
}

//les deux sont equivqlentes mais faire sample2 pour init en cpp
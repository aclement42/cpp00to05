#include "Base.hpp"

int main()
{
    Base *tmp = generate();
    Base *tmp2 = generate();
    Base *tmp3 = generate();
    Base *tmp4 = generate();

    identify(tmp);
    identify(*tmp);
    identify(tmp2);
    identify(*tmp2);
    identify(tmp3);
    identify(*tmp3);
    identify(tmp4);
    identify(*tmp4);

    delete (tmp);
    delete (tmp2);
    delete (tmp3);
    delete (tmp4);
    return (0);
}
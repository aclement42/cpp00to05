#include "Base.hpp"

Base::~Base()
{
    std::cout << "default destructor called" << std::endl;
}

Base * generate(void)
{
    static unsigned int count = 0;
    std::srand(static_cast<unsigned int>(std::time(0) + count++));
    // (void)nullptr;
    int random_nb = std::rand() % 3;

    if (random_nb == 0)
    {
        std::cout << "A Type was generate" << std::endl;
        return (new A());
    }
    else if (random_nb == 1)
    {
        std::cout << "B Type was generate" << std::endl;
        return (new B());
    }
    else
    {
        std::cout << "C Type was generate" << std::endl;
        return (new C());
    }
    return (NULL);
}

void    identify(Base* p)
{
    if (A *a = dynamic_cast<A *>(p))
        std::cout << "Pointer Type A was instancied" << std::endl;
    else if (B *b = dynamic_cast<B *>(p))
        std::cout << "Pointer Type B was instancied" << std::endl;
    else if (C *c = dynamic_cast<C *>(p))
        std::cout << "Pointer Type C was instancied" << std::endl;
    else
        std::cout << "something went wrong" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Reference Type A was instancied" << std::endl;
        (void)a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        std::cout << "Reference Type B was instancied" << std::endl;
        (void)b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        std::cout << "Reference Type C was instancied" << std::endl;
        (void)c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

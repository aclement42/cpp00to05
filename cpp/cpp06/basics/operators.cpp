#include <iostream>

class   Foo
{
    public:
        Foo(float const v) : _v(v) {}

        float getV( void)           { return (this->_v); }

        operator float()            { return (this->_v); } 
        operator int()              { return (static_cast<int>(this->_v)); } // om veut _v qui est un float en int

    private:
        float _v;
};

int     main()
{
    Foo a( 420.024f );

    float   b = a;
    int     c = a; // c est le resultat du static_cast de ma valeur float a en int grace a operator int()

    std::cout << a.getV() << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return (0);

}
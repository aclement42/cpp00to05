#include <iostream>

// int main()
// {
    // int a =  42;
// 
    // double b = a;
    // int c =  b;
    // int d = static_cast<int>(b);
// 
    // std::cout << "d: " << d << std::endl;
    // return (0);
// };

class   Parent
{};

class   Child1 : public Parent {};
class   Child2 : public Parent {};

class Unrelated{};

int main()
{
    Child1 a;

    Parent * b = &a; //implicit upcast;

    Child1 * c = b; //hell no!
    Child2 * d = static_cast<Child2 *>(b); // explicit downcast = OK!
    
    Unrelated *e = static_cast<Unrelated *>(&a); //pas lie donc imposs
    
    return (0);
}
//explicit: interdit la construction implicite de notre instance
//soit si je devais avoir une classe C qui serait construite implicitement a partir dune classe A -> OK car le constructor n'est pas explicite
// mais le constructeur qui prend une instance de B est explicite donc le comilo ne voudra pas
//pour faire fonctionner, il faut construire une instance de C dabord a partir dune instance B
//puis denvoyer cette instance de C en param a notre fonction f

#include <iostream>

class       A {};
class       B {};

class       C
{
    public:
        C(A const & _) { return; }
        C(B const & _) { return; }
};

void    f( C const & _)
{
    return ;
}

int main()
{
    f( A() ); //implicit conversion OK
    f( B() ); // implicit conversion NOT OK, constructor explicit

    return (0);
}
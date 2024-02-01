#include "Swap.hpp"
#include "Min.hpp"
#include "Max.hpp"

int main( void )
{
    int a = 2;
    int b = 3;
    Swap::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << Min::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << Max::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    Swap::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << Min::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << Max::max( c, d ) << std::endl;
    return 0;
}

// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2
#include "iter.hpp"

// int main()
// {
    // 
    // double tab[10];
    // int i = 0;
    // 
    // while (i < 10)
    // {
        // tab[i] = i + 0.1;
        // std::cout << tab[i] << std::endl;
        // i++;
    // }
    // iter(tab, 10, foo<float, double>);
    // 
    // std::cout << std::endl;
// 
    // std::string tabString[3];
// 
    // tabString[0] = "lundi";
    // tabString[1] = "mardi";
    // tabString[2] = "mercredi";
// 
    // i = 0;
    // 
    // while (i < 3)
    // {
        // std::cout << tabString[i] << std::endl;
        // i++;
    // }
   //iter(tabString, 3, foo<void, std::string>);
// 
    // return (0);
// }
// 

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

static std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
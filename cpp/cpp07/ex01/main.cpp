#include "iter.hpp"

int main()
{
 
 int tab[10];
 int i = 0;
 std::cout << "---TAB INT TEST---" << std::endl;
 while (i < 10)
 {
     tab[i] = i + 0.1;
     std::cout << tab[i] << std::endl;
     i++;
 }
 std::cout << "AFTER ITER CALLED" << std::endl;
 iter(tab, 10, add_two<int>);
 iter(tab, 10, foo<int>);

 std::cout << "---NUMBERFLOAT FLOAT TEST---" << std::endl;
 float numberfloat[7];
 for (int j = 0; j < 7; j++)
 {
   numberfloat[j] = j - 42.42f;
   std::cout << numberfloat[j] << std::endl;
 }
  std::cout << "AFTER ITER CALLED" << std::endl;
  iter(numberfloat, 7, add_two<float>);
  iter(numberfloat, 7, foo<float>);

 std::cout << std::endl;
 std::cout << "---TABSTRING STRING TEST---" << std::endl;

 std::string tabString[3];
 tabString[0] = "abc";
 tabString[1] = "xyz";
 tabString[2] = "123";
 i = 0;
 
 while (i < 3)
 {
     std::cout << tabString[i] << std::endl;
     i++;
 }
 std::cout << "AFTER ITER CALLED" << std::endl;
 iter(tabString, 3, add_two<std::string>);
 iter(tabString, 3, foo<std::string>);

 std::cout << std::endl;


 return (0);
}

// class Awesome
// {
  // public:
    // Awesome( void ) : _n( 42 ) { return; }
    // int get( void ) const { return this->_n; }
  // private:
    // int _n;
// };
// 
// static std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
  // o << rhs.get();
  // return o;
// }
// 
// template< typename T >
// void print( T& x )
// {
  // std::cout << x << std::endl;
  // return;
// }
// 
// int main() {
  // int tab[] = { 0, 1, 2, 3, 4 };
  // Awesome tab2[5];
// 
  // iter( tab, 5, print<const int> );
  // iter( tab2, 5, print<Awesome> );
// 
  // return 0;
// }
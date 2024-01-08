#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << std::endl << std::endl;
	Fixed		e;
	Fixed		f(10);
	Fixed		g(2.2f);
	std::cout << "f is " << f.toFloat() << " as float" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	std::cout << "g is " << g.toFloat() << " as float" << std::endl;
	std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	e = g + f;
	std::cout << std::endl << std::endl;
    std::cout << "e = g + f:" << std::endl; 
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;

	e = e + f;
	std::cout << std::endl << std::endl;
    std::cout << "e = e + f:" << std::endl;
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;


	e = e - f;
	std::cout << std::endl << std::endl;
    std::cout << "e = e - f:" << std::endl;
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;

	e = f * f;
	std::cout << std::endl << std::endl;
    std::cout << "e = f * f:" << std::endl;
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;

	e = f / f;
	std::cout << std::endl << std::endl;
    std::cout << "e = f / f:" << std::endl;
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	
    std::cout << std::endl << std::endl;

	std::cout << "10 > 2 = " << (f > g) << std::endl;
	std::cout << "2 > 10 = " << (g > f) << std::endl;

	std::cout << std::endl << std::endl;
	
    std::cout << "10 < 2 = " << (f < g) << std::endl;
	std::cout << "2 < 10 = " << (g < f) << std::endl;

	std::cout << std::endl << std::endl;
	
    std::cout << "10 >= 2 = " << (f >= g) << std::endl;
	std::cout << "2 >= 10 = " << (g >= f) << std::endl;

	std::cout << std::endl << std::endl;
	
    std::cout << "2 >= 10 = " << (g >= f) << std::endl;
	std::cout << "2 <= 10 = " << (g <= f) << std::endl;

	std::cout << std::endl << std::endl;
	
    std::cout << "10 == 2 = " << (f == g) << std::endl;
	std::cout << "10 == 2 = " << (f == g) << std::endl;
	std::cout << "10 == 10 = " << (f == f) << std::endl;

	std::cout << std::endl << std::endl;
	
    std::cout << "10 != 2 = " << (f != g) << std::endl;
	std::cout << "10 != 2 = " << (f != g) << std::endl;
	std::cout << "10 != 10 = " << (f != f) << std::endl;

	std::cout << std::endl << std::endl;
	
    Fixed	w(42.42f);
	std::cout << "w = " << w.toFloat() << std::endl;
	std::cout << "w = " << w.toInt() << std::endl;
	++w;
	std::cout << "w++ = " << w.toFloat() << std::endl;
	std::cout << "w++ = " << w.toInt() << std::endl;
	++w;
	std::cout << "w++ = " << w.toFloat() << std::endl;
	std::cout << "w++ = " << w.toInt() << std::endl;
	w++;
	std::cout << "w++ = " << w.toFloat() << std::endl;
	std::cout << "w++ = " << w.toInt() << std::endl;
	std::cout << w << std::endl;
	std::cout << w++ << std::endl;
	std::cout << w << std::endl;
	std::cout << ++w << std::endl;
	std::cout << w << std::endl;
	std::cout << "w++ = " << w.toFloat() << std::endl;
	std::cout << "w++ = " << w.toInt() << std::endl;

	e = e.min(f, g);
	std::cout << "min " << f << " vs " << g << " = " << e << std::endl;
	e = e.max(f, g);
	std::cout << "max " << f << " vs " << g << " = " << e << std::endl;
	
	const Fixed	aa(-1);
	const Fixed	bb(3.141f);
	const Fixed cc = cc.min(aa, bb);
	std::cout << "min " << aa << " vs " << bb << " = " << cc << std::endl;
	const Fixed dd = dd.max(aa, bb);
	std::cout << "max " << aa << " vs " << bb << " = " << dd << std::endl;

//	std::cout << "test bit shifting: " << (float)(1 << 8) << std::endl;
	
	return (0);
}
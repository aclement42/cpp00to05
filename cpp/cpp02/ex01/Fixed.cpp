#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_value = 0;
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int   Fixed::getRawBits(void) const
{
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = n << this->_bits;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = ((int)roundf(f * (1 << this->_bits)));
}


Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return (*this);
}

int    Fixed::toInt(void) const
{
    int n;

    n = this->_value >> this->_bits;
    return (n);
}

float   Fixed::toFloat() const
{
    float f;

    if (this->_value == INFINITY || this->_value == NAN)
    {
        std::cout << "Float constructor called but value to high to convert; possibility of overflow" << this->_value << std::endl;
        return (0);
    }

    f = (float)this->_value / (float)(1 << this->_bits);
    //if (rhs.toFloat()._value == NAN)
    //{
    //    std::cout << "Float constructor called but value to high to convert; possibility of overflow" << this->_value << std::endl;
    //    return (0);
    //}
return (f);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

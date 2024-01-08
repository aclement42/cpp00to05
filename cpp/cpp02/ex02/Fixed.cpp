#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_value = 0;
    //std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
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
    //std::cout << "Int constructor called" << std::endl;
    this->_value = n << this->_bits;
}

Fixed::Fixed(float const f)
{
    //std::cout << "Float constructor called" << std::endl;
    this->_value = ((int)roundf(f * (1 << this->_bits)));
}


Fixed::Fixed(Fixed const & src)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed & Fixed::operator=( Fixed const & rhs)
{
    //std::cout << "Copy assignement operator called" << std::endl;
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

    f = (float)this->_value / (float)(1 << this->_bits);
    return (f);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

bool    Fixed::operator>(Fixed const & newval) const
{
    if (this->_value > newval.getRawBits())
        return (1);
    return (0);
}

bool    Fixed::operator<(Fixed const & newval) const
{
    if (this->_value < newval.getRawBits())
        return (1);
    return (0);
}

bool    Fixed::operator!=(Fixed const & newval) const
{
    if (this->_value != newval.getRawBits())
        return (1);
    return (0);
}

bool    Fixed::operator==(Fixed const & newval) const
{
    if (this->_value == newval.getRawBits())
        return (1);
    return (0);
}

bool    Fixed::operator>=(Fixed const & newval) const
{
    if (this->_value >= newval.getRawBits())
        return (1);
    return (0);
}

bool    Fixed::operator<=(Fixed const & newval) const
{
    if (this->_value <= newval.getRawBits())
        return (1);
    return (0);
}

Fixed   Fixed::operator+(Fixed const & newval)const
{
    Fixed   ret;

    ret.setRawBits(this->_value + newval.getRawBits());
    return (ret);
}

Fixed   Fixed::operator/(Fixed const & newval)const
{
    Fixed   ret;

    ret.setRawBits((this->_value / newval.getRawBits()) >> this->_bits);
    return (ret);
}

Fixed   Fixed::operator*(Fixed const & newval)const
{
    Fixed   ret;

    ret.setRawBits((this->_value * newval.getRawBits()) >> this->_bits);
    return (ret);
}

Fixed   Fixed::operator-(Fixed const & newval)const
{
    Fixed   ret;

    ret.setRawBits(this->_value - newval.getRawBits());
    return (ret);
}

Fixed   & Fixed::operator++()
{
    this->_value++;
    return (*this);
}

Fixed   & Fixed::operator--()
{
    this->_value--;
    return (*this);
}

Fixed   Fixed::operator++(int num)
{
    (void)num;
    Fixed   newfixed(*this);
    this->_value++;
    return (newfixed);
}

Fixed   Fixed::operator--(int num)
{
    (void)num;
    Fixed   newfixed(*this);
    this->_value--;
    return (newfixed);
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    Fixed   cpy_a(a);
    Fixed   cpy_b(b);

    if (cpy_a > cpy_b)
        return (a);
    else
        return (b);
}

Fixed   const &Fixed::min(Fixed const &a, Fixed const &b)
{
    Fixed   cpy_a(a);
    Fixed   cpy_b(b);

    if (cpy_a < cpy_b)
        return (a);
    else
        return (b);
}
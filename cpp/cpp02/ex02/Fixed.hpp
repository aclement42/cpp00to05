#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int _value;
        int const static    _bits = 8;
    public:
        Fixed();
        Fixed(Fixed const & src);
        Fixed(int const n);
        Fixed(float const f);
        ~Fixed();

        int getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;

        Fixed & operator=( Fixed const & rhs);
        bool    operator>(Fixed const & newval)const;
        bool    operator<(Fixed const & newval)const;
        bool    operator>=(Fixed const & newval)const;
        bool    operator<=(Fixed const & newval)const;
        bool    operator==(Fixed const & newval)const;
        bool    operator!=(Fixed const & newval)const;

        Fixed   operator+(Fixed const & newval)const;    
        Fixed   operator-(Fixed const & newval)const;
        Fixed   operator*(Fixed const & newval)const;
        Fixed   operator/(Fixed const & newval)const;    

        Fixed   operator--(int);
        Fixed & operator++();
        Fixed   operator++(int);
        Fixed & operator--();
        
        Fixed static &min(Fixed &a, Fixed &b);
        Fixed static &max(Fixed &a, Fixed &b);
        Fixed static const  &min(Fixed const &a, Fixed const &b);
        Fixed static const  &max(Fixed const &a, Fixed const &b);
};

std::ostream & operator<<( std::ostream & o, Fixed const & i);

#endif

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
        ~Fixed();
        Fixed & operator=( Fixed const & rhs);
        int getRawBits(void) const;
        void    setRawBits(int const raw);

        Fixed(int const n);
        Fixed(float const f);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i);

#endif
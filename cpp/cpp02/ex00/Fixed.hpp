#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class   Fixed
{
    private:
        int _value;
        int const static    _bits = 8;
    public:
        Fixed();
        Fixed(int val);
        ~Fixed();
        Fixed(Fixed const & src);
        Fixed & operator=( Fixed const & rhs);

        int getRawBits(void) const;
        void    setRawBits(int const raw);
};


#endif
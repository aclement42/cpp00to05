#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScarlarConverter
{
private:
    ScarlarConverter();
    ScarlarConverter(ScarlarConverter const & obj);
    ScarlarConverter & operator=(ScarlarConverter const &);
public:
    ~ScarlarConverter();
    static void * convert(std::string type);
};

#include "ScalarConverter.hpp"

ScarlarConverter::~ScarlarConverter()
{
    std::cout << "default destructor called" << std::endl;
}

ScarlarConverter::ScarlarConverter()
{
    std::cout << "default constructor called" << std::endl;
}

ScarlarConverter::ScarlarConverter(ScarlarConverter const & obj)
{
    *this = obj;
    std::cout << "copy constructor called" << std::endl;
}

ScarlarConverter & ScarlarConverter::operator=(ScarlarConverter const &)
{
    std::cout << "copy assignement operator called" << std::endl;
    return (*this);
}

static void * ScarlarConverter::convert(std::string type)
{
    if (type.empty())
        std::cout << "Error: empty parameter" << std::endl;
    else if (isachar(type) == 1)
        //convertchar(type);
}

bool isachar(std::string type)
{
    int i = 0;
    if (type.length() == 1 && ((type[i] >= 32 && type[i] <= 47) || (type[i] >= 58 && type[i] < 127)))
        return (1);
    else
        return (0);
}

bool isdigit(std::string type)
{
    int i = 0;
    if (type[i] == '-')
        i++;
    while (type && type[i])
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}

bool    isfloat(std::string type)
{
    int i = 0;
    if (type[i] == '-')
        i++;
    while (type[i] != '.')
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else
            return (0);
    }
    if (type[i] == '.')
        i++;
    while (type[i] != '\0')
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}

#endif


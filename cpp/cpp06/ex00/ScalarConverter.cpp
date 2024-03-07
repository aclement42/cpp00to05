
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

void    convertchar(std::string type)
{
    //std::cout << "is a char" << std::endl;
    char c = type.at(0);
    int  nb = static_cast<int>(c);

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;

}

int     keeprecision(std::string type)
{
    int i = 0;
    int precision = 0;
    while (type[i] && type[i] != '.')
        i++;
    while (type[++i])
        precision++;
    return (precision);
}

void    convertdouble(std::string type)
{
    // std::cout << "is an double" << std::endl;
    std::stringstream ss(type);
    long double nb;
    ss >> nb;

    if ((nb >= 0 && nb < 32 )|| nb == 127)
        std::cout << "char: Non displayable" << std::endl;
    else if (nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char:\t'" << static_cast<char>(nb) << "'" << std::endl;
    if (nb < -2147483648 || nb > 2147483647)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int:\t" << static_cast<int>(nb) << std::endl;
   // if (nb == std::numeric_limits<double>::infinity() ||
   //     nb == (-1 * std::numeric_limits<double>::infinity()))
   //     std::cout << "float: inff" << std::endl;
   // else
//    std::cout << "Debug convert doubble" << std::endl;
    std::cout << "float:\t" << std::fixed << std::setprecision(keeprecision(type)) << std::scientific << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double:\t" << std::fixed  << std::setprecision(keeprecision(type)) << std::scientific << static_cast<double>(nb) << std::endl;
    
}

void    convertfloat(std::string type)
{
    std::cout << "is a float" << std::endl;
    std::cout << "type: " << type << std::endl;
    std::stringstream ss(type);
    
        std::cout << "fail: " << ss.fail() << std::endl;
    float   nb;
    ss >> nb;
    std::cout << "nb: " << nb << std::endl;
    long int fInt    = static_cast<int>(nb);
    
    std::cout << fInt << std::endl;
    if ((nb >= 0 && nb < 32 )|| nb == 127)
        std::cout << "char: Non displayable" << std::endl;
    else if (nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char:\t'" << static_cast<char>(nb) << "'" << std::endl;
    if (fInt < -2147483648 || fInt > 2147483647)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int:\t" << fInt << std::endl;
    std::cout << "float:\t" << std::fixed << std::setprecision(keeprecision(type)) << std::scientific << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double:\t" << std::fixed  << std::setprecision(keeprecision(type)) << std::scientific << static_cast<double>(nb) << std::endl;
}

int    convertint(std::string type)
{
   // std::cout << "is an int" << std::endl;
   std::stringstream ss(type);
    long long int nb;

    ss >> nb; 

//atoll(type.c_str());

    if (nb < -2147483648 || nb > 2147483647)
    {
        // std::cout << "Error: -2147483648 < int < 2147483647" << std::endl;
        return (1);
    }
    if ((nb >= 0 && nb < 32) || nb == 127)
        std::cout << "char: Non displayable" << std::endl;
    else if (nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
    return (0);
}

bool isachar(std::string type)
{
    int i = 0;
    if (type.length() == 1 && ((type[i] >= 32 && type[i] <= 47) || (type[i] >= 58 && type[i] < 127)))
        return (1);
    else
        return (0);
}

bool isadigit(std::string type)
{
    int i = 0;
    if (type[i] == '-' || type[i] == '+')
        i++;
    while (type[i])
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}


bool    isadouble(std::string type)
{
    int i = 0;
    if (type[0] == '-' || type[0] == '+')
        i++;
    while (type[i])
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else if (type[i] == '.')
        {
            i++;
            break;
        }
        else
            return (0);
    }
    while (type[i])
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else
            return (0);
    }
    if (type[i - 1] == '.')
        return (0);
    return (1);
}

bool isafloat(std::string type)
{
    int i = 0;
    int size = type.size();
    if (type[i] == '-' || type[i] == '+')
        i++;
    while (type[i])
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else if (type[i] == '.')
        {
            i++;
            break;
        }
        else
            return (0);
    }
    if (type[i] < 48 || type[i] > 57)
        return (0);
    while (i < size -1)
    {
        if (type[i] >= '0' && type[i] <= '9')
            i++;
        else
            return (0);
    }
    if (type[size - 1] != 'f')
        return (0);
    return (1);
}

void    convertnan()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void    convertinfpos()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
}

void    convertinfneg()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

void  ScarlarConverter::convert(std::string type)
{
    if (type.empty())
        std::cout << "Error: empty parameter" << std::endl;
    else if (isachar(type) == 1)
        convertchar(type);
    else if (isadigit(type) == 1)
    {
        if (convertint(type) == 1)
            convertdouble(type);
    }
    else if (isadouble(type) == 1)
        convertdouble(type);
    else if (isafloat(type) == 1)
        convertfloat(type);
    else if (type == "nan")
        convertnan();
    else if (type == "inf" || type == "inff")
        convertinfpos();
    else if (type == "-inf" || type == "-inff")
        convertinfneg();
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}


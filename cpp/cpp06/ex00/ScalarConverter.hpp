#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <string.h>
# include <stdlib.h>
# include <sstream>
# include <iomanip>
# include <limits>


class ScarlarConverter
{
private:
    ScarlarConverter();
    ScarlarConverter(ScarlarConverter const & obj);
    ScarlarConverter & operator=(ScarlarConverter const &);
public:
    ~ScarlarConverter();
    static void  convert(std::string type);
};

#endif


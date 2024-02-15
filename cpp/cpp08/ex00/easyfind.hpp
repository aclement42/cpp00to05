#ifndef EASYFIND_HPP
# define EASYFIND_HPP


# include <iostream>
# include <vector>
# include <algorithm>
class   easyexception
{
    public:
        class   notfind : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Value to find not find in container...");
                }
        };

        class   emptycont : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("please give me something to search in...");
                }
        };
};

#endif
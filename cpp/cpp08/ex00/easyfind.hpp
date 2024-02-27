#ifndef EASYFIND_HPP
# define EASYFIND_HPP


# include <iostream>
# include <vector>
# include <algorithm>
# include <list>
# include <deque>

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


template< typename T>
int    easyfind(T container,int nb)
{
    typename T::iterator it;

    if (container.empty() == true)
        throw easyexception::emptycont();
    it = find(container.begin(), container.end(), nb);
    if (it == container.end())
        throw easyexception::notfind();
    return (*it);
}

#endif
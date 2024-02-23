#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}


PmergeMe::PmergeMe_exceptions::PmergeMe_exceptions(std::string const & str)
{
    this->_errormsg = str;
}

const char* PmergeMe::PmergeMe_exceptions::get_errormsg() const
{
    return ((this->_errormsg).c_str());
}

bool    PmergeMe::verif_digit(std::string const & str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[0] == '+')
            i++;
        if (i != 0 && str[i] == '+')
            return (0);
        if (isdigit(str[i]) == 0)
            return (0);
    }
    return (1);
}

bool    PmergeMe::verif_ui(std::string const &str)
{
    static_cast<void>(str);
    return (1);
}

void    PmergeMe::parse(int ac , char **av)
{
    try
    {
        for (int i = 1; i < ac; i++)
        {
            std::cout << av[i] << std::endl;
            if (verif_digit(av[i]) == 0)
                throw PmergeMe::PmergeMe_exceptions("Error: Bad Input");
            if (verif_ui(av[i]) == 0)
                throw PmergeMe::PmergeMe_exceptions("Error: UINT_MIN <= X <= UINT_MAX");
        }        
        //if (keep_nb_and_verify_ui(str) == 0)
            // throw PmergeMe::PmergeMe_exceptions("Error: ");
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
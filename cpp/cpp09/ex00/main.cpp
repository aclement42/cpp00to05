#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;
    if (ac != 2)
    {
        try
        {
            throw BitcoinExchange::BitcoinExceptions("one arg is needed");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
    }
    else
    {
        btc.verif_extension(av[1]);
    }
    return (0);
}
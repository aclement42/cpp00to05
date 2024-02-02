#include "iter.hpp"

int main()
{
    
    int tab[10];
    int i = 0;
    
    while (i < 10)
    {
        tab[i] = i;
        std::cout << tab[i] << std::endl;
        i++;
    }
    iter(tab, 10, foo<int>);
    
    std::cout << std::endl;

    std::string tabString[3];

    tabString[0] = "lundi";
    tabString[1] = "mardi";
    tabString[2] = "mercredi";

    i = 0;
    
    while (i < 3)
    {
        std::cout << tabString[i] << std::endl;
        i++;
    }
    iter(tabString, 3, foo<std::string>);

    return (0);
}
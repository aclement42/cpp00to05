#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(25);
    vec.push_back(555);
    vec.push_back(-777);
    vec.push_back(8);
    vec.push_back(-42);
    vec.push_back(0);
    
    int value_to_find = 25;
    try
    {
        int foundN = easyfind(vec, value_to_find);
        std::cout << "element found in vec: " << foundN << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
#include "easyfind.hpp"

template< typename T>
void*    easyfind(T container,int nb)
{
    std::vector<int>::iterator it;

    it = find(container.begin(), container.end(), nb);
    if (container.empty() == true)
        throw easyexception::emptycont();
    if (it != container.end())
        std::cout << "element found in vec: " << *it << std::endl;
    else
        throw easyexception::notfind();
    return (0);
}

int main()
{
    std::vector<int> vec;
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(12);
    vec.push_back(555);
    vec.push_back(-777);
    vec.push_back(8);
    vec.push_back(-42);
    vec.push_back(0);

    int value_to_find = 0;
    try
    {
        easyfind(vec, value_to_find);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
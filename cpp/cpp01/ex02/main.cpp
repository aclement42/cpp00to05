#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string*    stringPTR = &string;
    std::string&    stringREF = string;

    std::cout << "adresse de la string en memoire: " << &string << std::endl;
    std::cout << "adresse stockee dans stringPTR: " << stringPTR << std::endl;
    std::cout << "adresse stockee dans stringREF: " << &stringREF << std::endl;

    std::cout << "valeur de la string: " << string << std::endl;
    std::cout << "valeur pointee par stringPTR: " << *stringPTR << std::endl;
    std::cout << "valeur pointee par stringREF: " << stringREF << std::endl;
    return (0);
}
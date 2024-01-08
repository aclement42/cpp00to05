#include <iostream>

int main()
{
    char    buff[512];

    std::cout << "Hello world !" << std::endl;
    // << redirige Hello word dans la sortie standard suivi de \n 
    std::cout << "Input a word: ";
    std::cin >> buff;
    // >> permet de recup une donner depuis l'entree standard
    std::cout << "You entered: [" << buff << "]" << std::endl;
}
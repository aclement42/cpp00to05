#include "ClapTrap.hpp"

// int main()
// {	ClapTrap	Pierre("Pierre");
	// std::cout << std::endl;
// 
	// ClapTrap	Pil;
	// std::cout << std::endl;
// 
	// Pil.attack("Scavvv");
	// std::cout << std::endl;
// 
	// Pierre.attack("Scavvv");
	// Pierre.takeDamage(0);
	// std::cout << std::endl;
// 
	// std::cout << Pierre.getname() << ": AD= " << Pierre.get_AD() << ", HP= " << Pierre.get_HP() << ", EP= " << Pierre.get_EP() << " " << std::endl; 
// 
	// std::cout << std::endl;
// 
	// Pierre.beRepaired(10);
	// Pierre.attack("Scavvv");
// 
	// std::cout << std::endl;
// 
	// std::cout << Pierre.getname() << ": AD= " << Pierre.get_AD() << ", HP= " << Pierre.get_HP() << ", EP= " << Pierre.get_EP() << " " << std::endl; 
// 
	// std::cout << std::endl;
// 
// }

int main( void )
{
    ClapTrap alpha = ClapTrap("alpha");
    ClapTrap beta = ClapTrap("beta");
    ClapTrap random;

    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        beta.attack("alpha");   // beta - 1 EP
        alpha.takeDamage(1);    // alpha - 1 HP
    }                           // beta 7EP et alpha 7 HP
    std::cout << std::endl;

    std::cout << beta.getname() << ": AD= " << beta.get_AD() << ", HP= " << beta.get_HP() << ", EP= " << beta.get_EP() << " " << std::endl; 
    std::cout << alpha.getname() << ": AD= " << alpha.get_AD() << ", HP= " << alpha.get_HP() << ", EP= " << alpha.get_EP() << " " << std::endl; 

    std::cout << std::endl;

    beta.takeDamage(5);
    beta.takeDamage(4);// beta 7EP 1HP et alpha 7HP

    std::cout << std::endl;

    std::cout << beta.getname() << ": AD= " << beta.get_AD() << ", HP= " << beta.get_HP() << ", EP= " << beta.get_EP() << " " << std::endl; 
    std::cout << alpha.getname() << ": AD= " << alpha.get_AD() << ", HP= " << alpha.get_HP() << ", EP= " << alpha.get_EP() << " " << std::endl; 

    std::cout << std::endl;
    for (int i = 0; i < 8; i++)
    {
        alpha.attack("beta");
        beta.attack("alpha");
    } // beta 0EP 1HP et alpha 2EP 7HP
    std::cout << std::endl;

    std::cout << beta.getname() << ": AD= " << beta.get_AD() << ", HP= " << beta.get_HP() << ", EP= " << beta.get_EP() << " " << std::endl; 
    std::cout << alpha.getname() << ": AD= " << alpha.get_AD() << ", HP= " << alpha.get_HP() << ", EP= " << alpha.get_EP() << " " << std::endl; 

    for (int i = 0; i < 3; i++)
        beta.beRepaired(1);
    random = beta;
    random.attack("alpha");
    std::cout << std::endl;

    std::cout << beta.getname() << ": AD= " << beta.get_AD() << ", HP= " << beta.get_HP() << ", EP= " << beta.get_EP() << " " << std::endl; 
    std::cout << alpha.getname() << ": AD= " << alpha.get_AD() << ", HP= " << alpha.get_HP() << ", EP= " << alpha.get_EP() << " " << std::endl; 
    return (0);
}

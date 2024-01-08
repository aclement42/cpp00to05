#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Pierre("Pierre");
	std::cout << std::endl;

	ClapTrap	Pil;
	std::cout << std::endl;

	ScavTrap	Scavvv("Scavvv");
	std::cout << std::endl;

	ScavTrap	Bis(Scavvv);
	std::cout << std::endl;

	ScavTrap	Ter;
	std::cout << std::endl;
	
	Pil.attack("Scavvv");
	Ter.attack("Scavvv");
	std::cout << std::endl;

	Pierre.attack("Scavvv");
	Scavvv.takeDamage(0);
	Scavvv.attack("Pierre");
	Pierre.takeDamage(20);
	Scavvv.guardGate();
	std::cout << std::endl;

	std::cout << Scavvv.getname() << ": AD= " << Scavvv.get_AD() << ", HP= " << Scavvv.get_HP() << ", EP= " << Scavvv.get_EP() << " " << std::endl; 
	std::cout << Pierre.getname() << ": AD= " << Pierre.get_AD() << ", HP= " << Pierre.get_HP() << ", EP= " << Pierre.get_EP() << " " << std::endl; 

	std::cout << std::endl;

	Pierre.beRepaired(10);
	Pierre.attack("Scavvv");

	std::cout << std::endl;

	std::cout << Scavvv.getname() << ": AD= " << Scavvv.get_AD() << ", HP= " << Scavvv.get_HP() << ", EP= " << Scavvv.get_EP() << " " << std::endl; 
	std::cout << Pierre.getname() << ": AD= " << Pierre.get_AD() << ", HP= " << Pierre.get_HP() << ", EP= " << Pierre.get_EP() << " " << std::endl; 

	std::cout << std::endl;

	return (0);
}
// 
// 
// int main()
// {
	// ScavTrap	a;
		// ScavTrap	b("Bob");
	// ClapTrap	c("Clippy");
// 
	// b.takeDamage(3);
	// b.takeDamage(20);
	// b.beRepaired(3);
	// b.attack("Eric");
	// b.attack("Eric");
	// b.attack("Eric");
	// b.beRepaired(6);
	// b.attack("Eric");
	//std::cout << b.(this->_name) << " " << b.this->_EP << std::endl;
	//std::cout << b.(this->_name) << " " << b.this->HP << std::endl;
// 
	// b.guardGate();
// }
//
//#include "ClapTrap.hpp"
//#include "ScavTrap.hpp"
//
//int main(void) {
//
//    ClapTrap Hobbit("Bilbo Baggins");
//    ScavTrap Orc("Azog");
//
//    Hobbit.attack("Orc");
//
//    Orc.guardGate();
//
//    Hobbit.attack("Orc");
//
//    Hobbit.beRepaired(20);
//
//    Orc.attack("Hobbit");
//    Hobbit.takeDamage(20);
//
//    Orc.attack("Hobbit");
//    Hobbit.takeDamage(20);
//
//	std::cout << Hobbit
//
//    return 0;
//}
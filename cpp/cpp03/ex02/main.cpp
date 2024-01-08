#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main(void)
{
	FragTrap	fragTrap("Fraggy");
	ScavTrap	scavTrap("Scavvy");
	
	scavTrap.attack("random human");
	scavTrap.guardGate();
	fragTrap.attack("random alien");
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(50);
	std::cout << scavTrap.getname() << "\x1b[38;5;201m: AD= " << scavTrap.get_AD() << ", HP= " << scavTrap.get_HP() << ", EP= " << scavTrap.get_EP() << " \x1b[0m" << std::endl; 
	std::cout << fragTrap.getname() << ": AD= " << fragTrap.get_AD() << ", HP= " << fragTrap.get_HP() << ", EP= " << fragTrap.get_EP() << " " << std::endl; 
	fragTrap.beRepaired(30);
	fragTrap.takeDamage(80);
	std::cout << scavTrap.getname() << ": AD= " << scavTrap.get_AD() << ", HP= " << scavTrap.get_HP() << ", EP= " << scavTrap.get_EP() << " " << std::endl; 
	std::cout << fragTrap.getname() << ": AD= " << fragTrap.get_AD() << ", HP= " << fragTrap.get_HP() << ", EP= " << fragTrap.get_EP() << " " << std::endl; 
	fragTrap.beRepaired(30);
	std::cout << scavTrap.getname() << ": AD= " << scavTrap.get_AD() << ", HP= " << scavTrap.get_HP() << ", EP= " << scavTrap.get_EP() << " " << std::endl; 
	std::cout << fragTrap.getname() << ": AD= " << fragTrap.get_AD() << ", HP= " << fragTrap.get_HP() << ", EP= " << fragTrap.get_EP() << " " << std::endl; 

	return (0);
}
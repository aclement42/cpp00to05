#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* h = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << h->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    
    std::cout << std::endl;
    
    meta->makeSound();
    j->makeSound();
    i->makeSound();
    h->makeSound();
    k->makeSound();
    
    std::cout << std::endl;

    delete k;
    delete h;
    delete i;
    delete j;
    delete meta;
    
    
    return 0;
}
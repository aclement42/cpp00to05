#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	
    Animal	*tab[10];
    Animal	*tab_copy[10];
	Dog		chien;
	Cat		chat;
    Dog     chienne;
	
    std::cout << std::endl;
    chien.getBrain()->add_idea("Je suis un chien", 1);
    chien.getBrain()->add_idea("Je veux mon os", 77);
    chien.getBrain()->add_idea("ou une croquette", 88);
    chien.getBrain()->add_idea("Joue avec moi", 99);
    chienne = chien;
    chienne.getBrain()->print_idea();

	std::cout << std::endl;
    int j = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": ";
		tab[i] = new Dog();
    	for (j = 0; j < 100; j++)
            ((Dog *)(Animal *)tab[i])->getBrain()->add_idea("wouf", j);
	}
	for (int i = 5; i < 10; i++)
    {
		std::cout << i << ": ";
		tab[i] = new Cat();
    	for (j = 0; j < 100; j++)
          ((Cat *)(Animal *)tab[i])->getBrain()->add_idea("miaouw", j);
    }
	std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Animals[" << i << "]:";
        ((Dog *)(Animal *)tab[i])->getBrain()->print_idea();
        tab[i]->makeSound();
        std::cout << std::endl;
    }
	std::cout << std::endl;
    std::cout << "CREATE A TAB COPY:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            tab_copy[i] = new Dog(*(Dog *)(tab[i]));
        }
        else
        {
            tab_copy[i] = new Cat(*(Cat *)tab[i]);
        }
    }
	for (int i = 0; i < 10; i++)
	{
		delete tab[i];
	}
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Animals_copy[" << i << "]:";
        tab_copy[i]->makeSound();
        ((Dog *)(Animal *)tab_copy[i])->getBrain()->print_idea();
        std::cout << std::endl;
    }
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete tab_copy[i];
	}
	std::cout << std::endl;
	return 0;
}

// Animal: Dog ,type constructor called
// Dog: Default constructor called
// Brain constructor called
// Animal: Cat ,type constructor called
// Cat: Default constructor called
// Brain constructor called
// Animal: Dog ,type constructor called
// Dog: Default constructor called
// Brain constructor called
// 
// Dog: Assignation operator called
// Brain destructor called
// Brain constructor called
// idea 1: Je suis un chien
// idea 77: Je veux mon os
// idea 88: ou une croquette
// idea 99: Joue avec moi
// 
// 0: Animal: Dog ,type constructor called
// Dog: Default constructor called
// Brain constructor called
// 1: Animal: Dog ,type constructor called
// Dog: Default constructor called
// Brain constructor called
// 2: Animal: Dog ,type constructor called
// Dog: Default constructor called
// Brain constructor called
// 3: Animal: Dog ,type constructor called
// Dog: Default constructor called
// Brain constructor called
// 4: Animal: Dog ,type constructor called
// Dog: Default constructor called
// Brain constructor called
// 5: Animal: Cat ,type constructor called
// Cat: Default constructor called
// Brain constructor called
// 6: Animal: Cat ,type constructor called
// Cat: Default constructor called
// Brain constructor called
// 7: Animal: Cat ,type constructor called
// Cat: Default constructor called
// Brain constructor called
// 8: Animal: Cat ,type constructor called
// Cat: Default constructor called
// Brain constructor called
// 9: Animal: Cat ,type constructor called
// Cat: Default constructor called
// Brain constructor called
// 
// Animals[0]:idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// Dog: WAAOOOUUUUFFFFF
// 
// Animals[1]:idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// Dog: WAAOOOUUUUFFFFF
// 
// Animals[2]:idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// Dog: WAAOOOUUUUFFFFF
// 
// Animals[3]:idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// Dog: WAAOOOUUUUFFFFF
// 
// Animals[4]:idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// Dog: WAAOOOUUUUFFFFF
// 
// Animals[5]:idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// Cat: MEEEOOOOWWWWW
// 
// Animals[6]:idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// Cat: MEEEOOOOWWWWW
// 
// Animals[7]:idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// Cat: MEEEOOOOWWWWW
// 
// Animals[8]:idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// Cat: MEEEOOOOWWWWW
// 
// Animals[9]:idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// Cat: MEEEOOOOWWWWW
// 
// 
// CREATE A TAB COPY:
// Animal: Dog, assignation operator called
// Animal: Dog, copy constructor called
// Dog: Copy constructor called
// Brain constructor called
// Animal: Dog, assignation operator called
// Animal: Dog, copy constructor called
// Dog: Copy constructor called
// Brain constructor called
// Animal: Dog, assignation operator called
// Animal: Dog, copy constructor called
// Dog: Copy constructor called
// Brain constructor called
// Animal: Dog, assignation operator called
// Animal: Dog, copy constructor called
// Dog: Copy constructor called
// Brain constructor called
// Animal: Dog, assignation operator called
// Animal: Dog, copy constructor called
// Dog: Copy constructor called
// Brain constructor called
// Animal: Cat, assignation operator called
// Animal: Cat, copy constructor called
// Cat: Copy constructor called
// Brain constructor called
// Animal: Cat, assignation operator called
// Animal: Cat, copy constructor called
// Cat: Copy constructor called
// Brain constructor called
// Animal: Cat, assignation operator called
// Animal: Cat, copy constructor called
// Cat: Copy constructor called
// Brain constructor called
// Animal: Cat, assignation operator called
// Animal: Cat, copy constructor called
// Cat: Copy constructor called
// Brain constructor called
// Animal: Cat, assignation operator called
// Animal: Cat, copy constructor called
// Cat: Copy constructor called
// Brain constructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Animals_copy[0]:Dog: WAAOOOUUUUFFFFF
// idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// 
// Animals_copy[1]:Dog: WAAOOOUUUUFFFFF
// idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// 
// Animals_copy[2]:Dog: WAAOOOUUUUFFFFF
// idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// 
// Animals_copy[3]:Dog: WAAOOOUUUUFFFFF
// idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// 
// Animals_copy[4]:Dog: WAAOOOUUUUFFFFF
// idea 1: wouf
// idea 77: wouf
// idea 88: wouf
// idea 99: wouf
// 
// Animals_copy[5]:Cat: MEEEOOOOWWWWW
// idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// 
// Animals_copy[6]:Cat: MEEEOOOOWWWWW
// idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// 
// Animals_copy[7]:Cat: MEEEOOOOWWWWW
// idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// 
// Animals_copy[8]:Cat: MEEEOOOOWWWWW
// idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// 
// Animals_copy[9]:Cat: MEEEOOOOWWWWW
// idea 1: miaouw
// idea 77: miaouw
// idea 88: miaouw
// idea 99: miaouw
// 
// 
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// 
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
// Brain destructor called
// Cat: Default destructor called
// Animal: Cat, default destructor called
// Brain destructor called
// Dog: Default destructor called
// Animal: Dog, default destructor called
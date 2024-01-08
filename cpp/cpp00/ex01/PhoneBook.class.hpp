#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstdio>

class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);
    void    addContact(Contacts *, PhoneBook *);
    void    display(PhoneBook *);
    Contacts *getCont();
private:
    int nb_cont;
    int index;
    std::string to_print;
    Contacts    cont[8];
};

#endif
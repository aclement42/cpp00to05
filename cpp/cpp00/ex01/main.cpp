#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <cstdlib>

int main(void)
{
    Contacts contact;
    PhoneBook phonebook;
    std::string  command;
    
    while (1)
    {

        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        if (command == "ADD")
        {
            if (contact.add(&contact) == 0)
                continue ;
            phonebook.addContact(&contact, &phonebook);
        }
        else if (command == "SEARCH")
        {
            if (phonebook.getCont()[0].getFn().empty())
            {
                std::cout << "No contact in phonebook yet" << std::endl;
                continue ;
            }
            else
                phonebook.display(&phonebook);
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command, please enter ADD, SEARCH, or EXIT" << std::endl;
    }
    return (0);
}
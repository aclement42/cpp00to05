#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
    nb_cont = 0;
    index = 0;
    to_print = "";
    return;
}

PhoneBook::~PhoneBook(void)
{
}

Contacts    *PhoneBook::getCont()
{
    return (this->cont);
}

void    PhoneBook::display(PhoneBook *phonebook)
{
    int i;

    i = 0;
    while (i < phonebook->index)
    {
        std::cout << "         " << i << "|";
        if (phonebook->cont[i].getFn().size() > 10)
            std::cout << std::right << std::setw(10 - 1) << phonebook->cont[i].getFn().substr(0, 10 - 1) << "." << "|";
        else
            std::cout << std::right << std::setw((int)10) << phonebook->cont[i].getFn() << "|";
        if (phonebook->cont[i].getLn().size() > 10)
            std::cout << std::right << std::setw(10 - 1) << phonebook->cont[i].getLn().substr(0, 10 - 1) << "." << "|";
        else
            std::cout << std::right << std::setw((int)10) << phonebook->cont[i].getLn() << "|";
        if (phonebook->cont[i].getNn().size() > 10)
            std::cout << std::right << std::setw(10 - 1) << phonebook->cont[i].getNn().substr(0, 10 - 1) << "." << "|";
        else
            std::cout << std::right << std::setw((int)10) << phonebook->cont[i].getNn() << "|";
        std::cout << std::endl;
        i++;
    }
    std::cout << "Press the index of the contact you're looking for" << std::endl;
    std::getline(std::cin, phonebook->to_print);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    const char *aa = phonebook->to_print.c_str();
    if (phonebook->to_print.size() == 1 && isdigit(aa[0]))
    {
        std::cout << "nombre de ctc mtn: " << phonebook->index << std::endl;
        if (atoi(aa) < phonebook->index)
        {
            std::cout << "Firstname : " << phonebook->cont[atoi(aa)].getFn() << std::endl;
            std::cout << "Lastname : " << phonebook->cont[atoi(aa)].getLn() << std::endl;
            std::cout << "Nickname : " << phonebook->cont[atoi(aa)].getNn() << std::endl;
            std::cout << "Phone number : " << phonebook->cont[atoi(aa)].getPn() << std::endl;
            std::cout << "Darkest secret : " << phonebook->cont[atoi(aa)].getDs() << std::endl;
        }
        else
            std::cout << "OKK BUT INDEX NOT ATTRIBUT YET" << std::endl;
    }
    else
        std::cout << "an existing index is needed" << std::endl;
}

void    PhoneBook::addContact(Contacts *contact, PhoneBook *phonebook)
{
    if (phonebook->nb_cont > 7)
    {
        phonebook->nb_cont = 0;
    }
    std::cout << "Contact as been saved successfully" << std::endl;
    phonebook->cont[phonebook->nb_cont].setFn(contact->getFn());
    phonebook->cont[phonebook->nb_cont].setLn(contact->getLn());
    phonebook->cont[phonebook->nb_cont].setNn(contact->getNn());
    phonebook->cont[phonebook->nb_cont].setPn(contact->getPn());
    phonebook->cont[phonebook->nb_cont].setDs(contact->getDs());
    std::cout << "[" << phonebook->nb_cont << "]: Fn: " << phonebook->cont[phonebook->nb_cont].getFn() << std::endl;
    std::cout << "[" << phonebook->nb_cont << "]: LN: " << phonebook->cont[phonebook->nb_cont].getLn() << std::endl;
    std::cout << "[" << phonebook->nb_cont << "]: NN: " << phonebook->cont[phonebook->nb_cont].getNn() << std::endl;
    std::cout << "[" << phonebook->nb_cont << "]: PN: " << phonebook->cont[phonebook->nb_cont].getPn() << std::endl;
    std::cout << "[" << phonebook->nb_cont << "]: DS: " << phonebook->cont[phonebook->nb_cont].getDs() << std::endl;
    phonebook->nb_cont++;
    if (phonebook->index < 8)
        phonebook->index++;
    std::cout << "nb_contact dans add : " << phonebook->nb_cont << std::endl;
}
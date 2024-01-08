#include "Contact.class.hpp"

Contacts::Contacts(void)
{
    Firstname = "";
    Lastname = "";
    Nickname = "";
    Phonenumber = "";
    Darkestsecret = "";
    return;
}

Contacts::~Contacts(void)
{
    return;
}

void    Contacts::setFn(std::string Fn)
{
    this->Firstname = Fn;
}

std::string    Contacts::getFn()
{
    return (this->Firstname);
}

void    Contacts::setLn(std::string Ln)
{
    this->Lastname = Ln;
}

std::string    Contacts::getLn()
{
    return (this->Lastname);
}

void    Contacts::setNn(std::string Nn)
{
    this->Nickname = Nn;
}

std::string    Contacts::getNn()
{
    return (this->Nickname);
}

void    Contacts::setPn(std::string Pn)
{
    this->Phonenumber = Pn;
}

std::string   Contacts::getPn()
{
    return (this->Phonenumber);
}

void    Contacts::setDs(std::string Ds)
{
    this->Darkestsecret = Ds;
}

std::string    Contacts::getDs()
{
    return (this->Darkestsecret);
}

bool    Contacts::verif_value(std::string str)
{
    size_t i;
    size_t  size;

    i = 0;
    size = str.size();
    if (size == 0)
    {
        std::cout << "please give me an information to save..." << std::endl;
        return (0);
    }
    while (i < size)
    {
        if (str[i] == 32 || str[i] == '.' || str[i] == '-' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            i++;
        else
        {
            std::cout << "please give me a coherent word" << std::endl;
            return (0);
        }
    }
    return (1);
}

bool    Contacts::verif_value_digit(std::string str)
{
    size_t  i = 0;
    size_t  size;
    size = str.size();
    if (size == 0)
        return (0);
    while (i < size)
    {
        if (str[i] == ' ' || str[i] == '.' || (str[i] >= 48 && str[i] <= 57))
            i++;
        else
        {
            std::cout << "please give me a coherent phone number" << std::endl;
            return (0);
        }

    }
    return (1);
}

bool    Contacts::add(Contacts *contact)
{
    std::cout << "Enter First name: ";
    std::getline(std::cin, contact->Firstname);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    if (contact->verif_value(contact->Firstname) == 0)
        return (0) ;
    std::cout << "Enter Last name: ";
    std::getline(std::cin, contact->Lastname);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    if (contact->verif_value(contact->Lastname) == 0)
        return (0) ;
    std::cout << "Enter Nick name: ";
    std::getline(std::cin, contact->Nickname);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    if (contact->verif_value(contact->Nickname) == 0)
        return (0) ;
    std::cout << "Enter Phone number: ";
    std::getline(std::cin, contact->Phonenumber);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    if (contact->verif_value_digit(contact->Phonenumber) == 0)
         return (0) ;
    std::cout << "Enter Darkest secret: ";
    std::getline(std::cin, contact->Darkestsecret);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    if (contact->verif_value(contact->Darkestsecret) == 0)
        return (0) ;
    return (1);
}
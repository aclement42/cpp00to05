#ifndef CONTACTS_CLASS_H
# define CONTACTS_CLASS_H

# include <string>
# include <iomanip>
# include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

class Contacts
{
    std::string Firstname;
    std::string Lastname;
    std::string Nickname;
    std::string Phonenumber;
    std::string Darkestsecret;
public:
    Contacts(void);
    ~Contacts(void);
    bool    verif_value(std::string str);
    bool    verif_value_digit(std::string str);
    bool    add(Contacts *);
    void    setFn(std::string);
    std::string    getFn();
    void    setLn(std::string);
    std::string    getLn();
    void    setNn(std::string);
    std::string    getNn();
    void    setPn(std::string);
    std::string   getPn();
    void    setDs(std::string);
    std::string    getDs();
};

#endif
//cast lance a l'execution et pas a la compilation --> peut echouer donc doit traiter l'erreur
//ne fonctionne uniquement dans le cas de polymorphisme --> au moins une methode virtuelle

#include <iostream>
#include <typeinfo>
#include <exception>

class       Parent
{
    public:
        virtual ~Parent() {};
};
class       Child1 : public Parent {};
class       Child2 : public Parent {};

int     main()
{
    Child1 a;
    Parent * b = &a; //adress sur parent

    Child1 * c = dynamic_cast<Child1 *>(b); //dynamic_cast vers un pointeur
    if (c == NULL) // si cast imposs
        std::cout << "Conversion is NOT OK" << std::endl;
    else //renvoie de ladress convertit
        std::cout << "Conversion is OK" << std::endl;

    //////////

    try 
    {
        Child2 & d = dynamic_cast<Child2 &>(*b); //dereference mon parent pour que le cast soit coherent 
        // cast mon parent vers une reference de child2
        std::cout << "Conversion is OK" << std::endl;
    }
    catch (std::bad_cast &bc)
    {
        std::cout << "conversion is NOT OK: " << bc.what() << std::endl;
        return (0);
    }

    return (0);
}
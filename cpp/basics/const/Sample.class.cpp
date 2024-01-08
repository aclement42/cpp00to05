#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(float const f) : pi(f), qd(42)
{
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Sample::bar(void) const
{
    std::cout << "this->pi = " << this->pi << std::endl;
    std::cout << "this->qd = " << this->qd << std::endl;
}
//cette fonction membre ne modifiera jamais linst courante
//nul part dans le code de cette fct jassignerais une valeur

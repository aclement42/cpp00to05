#include "Serializer.hpp"

void Data::setData(std::string content)
{
    type = content;
}

std::string Data::getData(void)
{
    return (type);
}

Serializer::Serializer()
{
    std::cout << "default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const & obj)
{
    std::cout << "default copy constructor called" << std::endl;
    *this = obj;
}

Serializer & Serializer::operator=(Serializer const &)
{
    std::cout << "default assign operator constructor called" << std::endl;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "default destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
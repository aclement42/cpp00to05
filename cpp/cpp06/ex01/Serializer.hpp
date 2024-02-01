#pragma once

#include <iostream>
#include <stdint.h>


typedef struct s_Data
{
    uintptr_t n;
    std::string type;
    void    setData(std::string content);
    std::string getData(void);
}               Data;

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const & obj);
        Serializer & operator=(Serializer const & rhs);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

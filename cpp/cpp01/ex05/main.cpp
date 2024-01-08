#include "Harl.hpp"
int main()
{
    Harl harl;

    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");
    harl.complain("debug");
    harl.complain("coucou");
    harl.complain("errorr");
    return (0);
}
#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    try
    {
        // sp.addNumber(8);
        // sp.addNumber(5);
        // sp.addNumber(5);
        sp.addNumber(-78);
        sp.addNumber(-79);
        sp.addNumber(-80);
        sp.addNumber(-81);
        // sp.addNumber(-78);

        // sp.addNumber(1);
        // sp.addNumber(-78);
        // sp.addNumber(-78);
        // sp.addNumber(-42);
        // sp.addNumber(88);
        // sp.addNumber(555);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    // sp.print_span(sp._span);
    try
    {
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
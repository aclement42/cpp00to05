#include "Span.hpp"

Span::Span()
{}

Span::~Span()
{}

Span::Span(Span const & obj)
{
    if (this != &obj)
        *this = obj;
}

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        this->_mysize = rhs._mysize;
        this->_span = rhs._span;
    }
    return (*this);
}

Span::Span(unsigned int N) : _mysize(N)
{
    std::cout << "construction of a Span of " << _mysize << " numbers." << '\n';
}
        
void* Span::addNumber(int nb)
{
    if (this->_mysize == _span.size())
        throw Span::addexception();
    else
        _span.push_back(nb);
    return (0);
}

unsigned int Span::longestSpan()
{
    long int longestSpan = 0;

    if (_span.empty() == true || this->_span.size() == 1)
        throw Span::nodistanceexception();
    else
    {
        std::vector<int> copySpan = _span;
        std::sort(copySpan.begin(), copySpan.end());
        // for (int i = 0;copySpan[i]; i++)
        // {
            // std::cout << copySpan[i] << '\n';
        // }
        longestSpan = copySpan.back() - copySpan.front();
    }
    return (longestSpan);
}

unsigned int Span::shortestSpan()
{

    if (_span.empty() == true || this->_span.size() == 1)
        throw Span::nodistanceexception();
    else
    {
        std::vector<int> copySpan = _span;
        std::sort(copySpan.begin(), copySpan.end());
        long int shortest = copySpan[1] - copySpan[0];
        for (unsigned int i = 1; i + 1 < this->_mysize; i++)
        {
            if (shortest > copySpan[i + 1] - copySpan[i])
                shortest = copySpan[i + 1] - copySpan[i];
        }
        return (shortest);

    }
}

void    Span::print_span( std::vector<int>& span)
{
    std::vector<int> copySpan = span;
    for (int i = 0;copySpan[i]; i++)
    {
        std::cout << copySpan[i] << '\n';
    }
    std::cout << "-----ELEMNTS SORTED-----" << std::endl;
    std::sort(copySpan.begin(),copySpan.end());
    for (int i = 0;copySpan[i]; i++)
    {
        std::cout << copySpan[i] << '\n';
    }
}

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>

class   Span
{
    private:
        Span();
        unsigned int _mysize;
    public:
        std::vector <int> _span;

        Span(Span const & obj);
        Span & operator=(Span const & rhs);
        ~Span();
        Span(unsigned int N);
        void* addNumber(int nb);
        void    print_span(std::vector<int>& span);
        
        
        
        
        unsigned int shortestSpan();
        unsigned int longestSpan();
        class   addexception : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("remplissage impossible!");
                }

        };
        class   nodistanceexception : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("more than 0 or 1 number needed to find a distance!");
                }

        };
};


#endif
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class   Brain
{
    protected:
        std::string     _ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain( Brain const & obj);
        Brain & operator=( Brain const & rhs);
        void    add_idea(std::string str, int index);
        void    print_idea();
        std::string getIdea(int id);
};


#endif
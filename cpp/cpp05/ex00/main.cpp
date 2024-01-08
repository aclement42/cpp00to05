
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "********************INITIALISATION********************" << std::endl;
    Bureaucrat  a;
    Bureaucrat  b("Alvin", 50);
    Bureaucrat  c(b);
    
    std::cout << "********************GRADE THAT WORKS********************" << std::endl;
    /*Default cosntructor*/
    try
    {
        a.setGrade(20);
        a.DecrementGrade();
        a.DecrementGrade();
        a.IncrementGrade();

        std::cout << a;
        // std::cout << a.getName() << ": grade: " << a.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    /*constructor with parameters*/
    try
    {
        b.IncrementGrade();
        b.DecrementGrade();
        b.DecrementGrade();
        b.DecrementGrade();
        std::cout << b;
        //std::cout << b.getName() << ": grade: " << b.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    /*copy constructor*/
    try
    {
        std::cout << c.getGrade() << std::endl;
        c.DecrementGrade();
        std::cout << c;
        //std::cout << c.getName() << ": grade: " << c.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "********************GRADE TOO HIGH*********************" << std::endl;
    try
    {
        a.setGrade(-2345);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        b.setGrade(1);
        b.IncrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "********************GRADE TOO LOW**********************" << std::endl;
    try
    {
        int i = 100;
        while(i > 0)
        {
            c.DecrementGrade();
            i--;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        a.setGrade(150);
        a.DecrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "*********************DESTRUCTION***********************" << std::endl;
}
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\x1b[38;5;221m********************INITIALISATION*********************\x1b[0m" << std::endl;
    Bureaucrat a("Theodore", 123);
    Bureaucrat d("Simon", 2);
    Form  b("F2", 70, 50);
    Form  c("F3", 70, 129);

    std::cout << "\x1b[38;5;221m********************GRADE THAT WORK********************\x1b[0m" << std::endl;
    try
    {
        //std::cout << a.getName() << ": grade: " << a.getGrade() << std::endl;
        std::cout << a;
        //std::cout << "garde signed: " << b.getGradesigned() << " grade Exec: " << b.getGradexec() << std::endl;
        std::cout << b;
        a.signForm(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\x1b[38;5;221m********************GRADE TOO LOW**********************\x1b[0m" << std::endl;
    try
    {
        std::cout << d.getName() << ": grade: " << d.getGrade() << std::endl;
        std::cout << "garde signed: " << c.getGradesigned() << " grade Exec: " << c.getGradexec() << std::endl;
        d.signForm(c);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\x1b[38;5;221m*********************DESTRUCTION***********************\x1b[0m" << std::endl;
}
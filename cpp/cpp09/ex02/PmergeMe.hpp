#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <climits>

class   PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();


        void    parse(int ac, char **av);
        bool    verif_digit(std::string const & str);
        bool    verif_ui(std::string const & str);

        // bool    verify_str(std::string const & str);
        // bool    verify_spaces(std::string const & str);


        class PmergeMe_exceptions : public std::exception
        {
            private:
                std::string _errormsg;
            public:
                PmergeMe_exceptions(std::string const & str);
                const char* get_errormsg() const;
                virtual const char* what() const throw()
                {
                    return (get_errormsg());
                }

                virtual ~PmergeMe_exceptions() throw() {};
        };
};


#endif
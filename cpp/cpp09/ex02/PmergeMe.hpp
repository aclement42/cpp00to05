#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <climits>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>
# include <ctime>

class   PmergeMe
{
    private:
        std::vector<unsigned int> _vector;
        std::deque<unsigned int> _deque;
		// timeval time_start;
		// timeval time_end;
		double time;
    public:
        PmergeMe();
        ~PmergeMe();


        void    parse(int ac, char **av);
        bool    verif_digit(std::string const & str);
        int    verif_ui(std::string const & str);
        template<typename T>
        void    print_arr(T &arr, int i);
        template<typename T>
        void	fordJohnsonSort(T &_arr);
        void    algo();



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
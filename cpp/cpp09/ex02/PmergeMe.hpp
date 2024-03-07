#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <climits>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>
# include <ctime>
# include <set>


class   PmergeMe
{
    private:
        std::vector<unsigned int> _vector;
        std::deque<unsigned int> _deque;
        bool            flagImpair;
        unsigned int    impair;
		double _time;
        PmergeMe(PmergeMe &obj);
        PmergeMe & operator=(PmergeMe const &rhs);
    public:
        PmergeMe();
        ~PmergeMe();


        void    parse(int ac, char **av);
        bool    verif_digit(std::string const & str);
        int    verif_ui(std::string const & str);
        
        template<typename T>
        void    print_arr(T &arr, int i);
        
        void    algo();
        void    launch_vec(std::vector<unsigned int> vec);
        void    launch_deq(std::deque<unsigned int> deq);

        void    FJS_vec(std::vector<std::vector<unsigned int> >&arr, int size);
        void    FJS_deq(std::deque<std::deque<unsigned int> >&arr, int size);
        
        template<typename T>
        void    straggler(T &arr);
        
        void    creating_pair_vec(std::vector<unsigned int> _vec);
        void    creating_pair_deq(std::deque<unsigned int> _deq);

        void    sort_vec(std::vector<std::vector<unsigned int> >&arr, int size);
        void    sort_deq(std::deque<std::deque<unsigned int> >&arr, int size);
        
        void	binarySearchInsertion(std::vector<unsigned int>& main,unsigned int value);
        void	binarySearchInsertion_deq(std::deque<unsigned int>& main,unsigned int value);

        int     jacobsthal(int n);
        std::vector<unsigned int> generateJacobsthalIndices(int size);
        std::deque<unsigned int> generateJacobsthalIndicesdeq(int size);

        std::vector<int>    printf_jcsv(std::vector<unsigned int> jcs);
        std::deque<int>  printf_jcsd(std::deque<unsigned int> jcs);

        
        template<typename T>
        void    printf_array(T &array, int nbofpairs);


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
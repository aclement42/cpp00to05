#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : flagImpair(0), impair(0)
{}

PmergeMe::~PmergeMe()
{}


PmergeMe::PmergeMe_exceptions::PmergeMe_exceptions(std::string const & str)
{
    this->_errormsg = str;
}

const char* PmergeMe::PmergeMe_exceptions::get_errormsg() const
{
    return ((this->_errormsg).c_str());
}

bool    PmergeMe::verif_digit(std::string const & str)
{
    if (str[0] == '+')
    {
        if (str.size() == 1)
            return (0);
        for (size_t i = 1; i < str.length(); i++)
        {
            if (isdigit(str[i]) == 0)
                return (0);
        }
    }
    else
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]) == 0)
                return (0);
        }
    }
    return (1);
}

int    PmergeMe::verif_ui(std::string const & str)
{
    char* end;
    const char* cstr = str.c_str();
    unsigned long long ulVal = strtoul(cstr, &end, 10);

    // std::cout << "Unsigned long long :" << ulVal << std::endl;
    if (ulVal < 0 || ulVal > 4294967295)
        return (0);
    unsigned int uVal = static_cast<unsigned int>(ulVal);
    std::cout << "Unsigned :" << uVal << std::endl;
    try
    {
        if (std::find(this->_deque.begin(), this->_deque.end(), uVal) != this->_deque.end())
            throw PmergeMe::PmergeMe_exceptions("Error: no doublons");
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (-1);
    }
    // std::cout << "UINTMAX :" << UINT_MAX << std::endl;
    this->_deque.push_back(uVal);
    this->_vector.push_back(uVal);
    return (1);
}

template <typename T>
void    PmergeMe::print_arr(T &arr, int i)
{
    if (i == 1)
        std::cout << "Before: ";
    else
        std::cout << "After: ";
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void    PmergeMe::straggler(T &arr)
{
    if ((arr.size() % 2) != 0)
    {
        this->flagImpair = 1;
        this->impair = arr.back();
        arr.pop_back();
        std::cout << this->impair << std::endl;
    }
}

template <typename T>
void    PmergeMe::creating_pair(T &arr)
{
    int nbOfPairs = arr.size() / 2;
    T<T<int>> array;
    // std::vector<std::vector<int>> array

    for (int i = 0; i < nbOfPairs; i++)
    {
        T<int> tmp;

        tmp.push(arr[i]);
        tmp.push(arr[i + 1]);
        array.push(tmp);
    }
}

template <typename T>
void	PmergeMe::fordJohnsonSort(T &arr)
{
    this->straggler(arr);
    this->creating_pair(arr);

}

// template <typename T>
// void	PmergeMe::fordJohnsonSort(T &arr)
// {
//     int n = arr.size();
//     bool flag = true;
    
//     struct timeval time_start, time_end;
//     gettimeofday(&time_start, NULL);
//     // std::clock_t time_start = std::clock(); // Démarre le chronomètre

//     while (flag)
//     {
//         flag = false;
//         int p = -1;
//         for (int i = 0; i < n - 1; ++i)
//         {
//             if (arr[i] > arr[i + 1])
//             {
//                 p = i;
//                 break;
//             }
//         }

//         if (p != -1)
//         {
//             int q = p;
//             for (int i = p + 1; i < n; ++i)
//             {
//                 if (arr[i] < arr[p])
//                 {
//                     q = i;
//                 }
//             }
//             std::swap(arr[p], arr[q]); // Échange les éléments aux indices p et q
//             flag = true;
//         }
//     }

//     gettimeofday(&time_end, NULL);
//     long seconds = time_end.tv_sec - time_start.tv_sec;
//     long microseconds = time_end.tv_usec - time_start.tv_usec;
//     this->time = seconds + microseconds * 1e-6;
//     // std::clock_t time_end = std::clock(); // Arrête le chronomètre
// //  Calcule le temps écoulé et le convertit en secondes
//     // this->time = static_cast<double>(time_end - time_start) / CLOCKS_PER_SEC;
// }

void    PmergeMe::algo()
{
    fordJohnsonSort(this->_vector);
    print_arr(this->_vector, 2);
    std:: cout << "Time to process a range of " << this->_deque.size() << " elements with std::vector : " << this->time << " us" << std::endl;
    fordJohnsonSort(this->_deque);
    std:: cout << "Time to process a range of " << this->_vector.size() << " elements with std::deque : " << this->time << " us" << std::endl;
}

void    PmergeMe::parse(int ac , char **av)
{
    try
    {
        for (int i = 1; i < ac; i++)
        {
            // std::cout << av[i] << std::endl;
            if (verif_digit(av[i]) == 0)
                throw PmergeMe::PmergeMe_exceptions("Error: Bad Input");
            int j = verif_ui(av[i]);
            if (j <= 0)
            {
                if (j == 0)
                    throw PmergeMe::PmergeMe_exceptions("Error: UINT_MIN <= X <= UINT_MAX");
                return ;
            }
        }
        print_arr(this->_deque, 1);
        algo();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
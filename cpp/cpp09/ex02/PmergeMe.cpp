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
    if (ulVal < 0 || ulVal > 2147483647)
        return (0);
    unsigned int uVal = static_cast<unsigned int>(ulVal);
    // std::cout << "Unsigned :" << uVal << std::endl;
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
    else if (i == 2)
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
        // std::cout << "keeping impair value: m" << this->impair << std::endl;
    }
}

template <typename T>
void    PmergeMe::printf_array(T &array, int size)
{
    std::cout << size << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i][0] << ", " << array[i][1] << std::endl;

    }
}

void    PmergeMe::creating_pair_vec(std::vector<unsigned int> _vec)
{
    int nbOfPairs = _vec.size() / 2;
    // mstd::cout << nbOfPairs << std::endl;
    std::vector<std::vector<unsigned int> >array;
    // std::vector<std::vector<int>> array

    for (size_t i = 0; i < _vec.size(); i += 2)
    {
        std::vector<unsigned int>tmp;
        // std::cout << "i: " << i << std::endl;

        if (_vec[i] > _vec[i + 1])
            std::swap(_vec[i], _vec[i + 1]);
        tmp.push_back(_vec[i]);
        tmp.push_back(_vec[i + 1]);
        array.push_back(tmp);
    }
    // std::cout << "---BEFORE VEC----" << std::endl;
    // this->printf_array(array, nbOfPairs);
    this->sort_vec(array, nbOfPairs);
    // std::cout << "---AFTER VEC----" << std::endl;
    // this->printf_array(array, nbOfPairs);
    this->FJS_vec(array, nbOfPairs);
}

void    PmergeMe::creating_pair_deq(std::deque<unsigned int> _deq)
{
    int nbOfPairs = _deq.size() / 2;
    std::deque<std::deque<unsigned int> >array;

    for (size_t i = 0; i < _deq.size(); i += 2)
    {
        std::deque<unsigned int>tmp;

        if (_deq[i] > _deq[i + 1])
            std::swap(_deq[i], _deq[i + 1]);
        tmp.push_back(_deq[i]);
        tmp.push_back(_deq[i + 1]);
        array.push_back(tmp);
    }
    this->sort_deq(array, nbOfPairs);
    this->FJS_deq(array, nbOfPairs);
}

int PmergeMe::jacobsthal(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

// i J   i J   i J    i J 
// 1 3 | 2 5 | 4 11 | 6 21
std::vector<int>  PmergeMe::printf_jcsv(std::vector<unsigned int> jcs)
{
    std::vector<int> seq;

    int i = 1;
    
    int jcb_idx = 3;
    int jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);

    int lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        i++;
    }
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);
    
    lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        i++;
    }
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);

    lastJacobValue = jacob_value;
    std::vector<int>::iterator it;
    while (jcb_idx < (int)jcs.size() - 1)
    {
        while (i < lastJacobValue - 1)
        {
            it = std::find(seq.begin(), seq.end(), i);
            if (it == seq.end())
            {
                seq.push_back(i);
                jcb_idx++;
                jacob_value = jcs[jcb_idx];
                seq.push_back(jacob_value);
                lastJacobValue = jacob_value;
                break ;
            }
            else
                i++;
        }
    }
    while (i < lastJacobValue - 1)
    {
        it = std::find(seq.begin(), seq.end(), i);
        if (it == seq.end())
            seq.push_back(i);
        else
            i++;
    }
    // PmergeMe::print_arr(seq, 1);
    return (seq);
}

std::deque<int>  PmergeMe::printf_jcsd(std::deque<unsigned int> jcs)
{
    std::deque<int> seq;

    int i = 1;
    
    int jcb_idx = 3;
    int jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);

    int lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        i++;
    }
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);
    
    lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        i++;
    }
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);

    lastJacobValue = jacob_value;
    std::deque<int>::iterator it;
    while (jcb_idx < (int)jcs.size() - 1)
    {
        while (i < lastJacobValue - 1)
        {
            it = std::find(seq.begin(), seq.end(), i);
            if (it == seq.end())
            {
                seq.push_back(i);
                jcb_idx++;
                jacob_value = jcs[jcb_idx];
                seq.push_back(jacob_value);
                lastJacobValue = jacob_value;
                break ;
            }
            else
                i++;
        }
    }
    while (i < lastJacobValue - 1)
    {
        it = std::find(seq.begin(), seq.end(), i);
        if (it == seq.end())
            seq.push_back(i);
        else
            i++;
    }
    return (seq);
}

void    PmergeMe::FJS_vec(std::vector<std::vector<unsigned int> >&arr, int size)
{
    std::vector<unsigned int> _sort;
    std::vector<unsigned int> _pend;

    std::vector<bool> inserted(size, false);

    for (int i = 0; i < size; i++)
    {
        _sort.push_back(arr[i][1]);
        _pend.push_back(arr[i][0]);
    }
    arr.clear();
    if (this->_vector.size() < 6)
    {
        for (size_t j = 0; j < _pend.size(); j++)
            binarySearchInsertion(_sort, _pend[j]);
    }
    else
    {
        std::vector<unsigned int> jacobsthalIndices = generateJacobsthalIndices(static_cast<int>(_pend.size()));
        std::vector<int> insertSeq = printf_jcsv(jacobsthalIndices);

        (void) insertSeq;
        _sort.insert(_sort.begin(), _pend[0]);
        for (size_t j = 0; j < _pend.size() + 1; j++)
        {
            size_t idx = insertSeq[j];
            if (idx < _pend.size())
                binarySearchInsertion(_sort, _pend[idx]);
        }

    }
    if (flagImpair== true)
        binarySearchInsertion(_sort, this->impair);
    this->_vector = _sort;
}

std::vector<unsigned int> PmergeMe::generateJacobsthalIndices(int size)
{

    std::vector<unsigned int> indices;
    int i = 0;
    while (true)
    {
        int idx = jacobsthal(i);// % size; // Assure que l'indice est dans la plage
        if (idx < size)
            indices.push_back(idx);
        else
        {
            indices.push_back(idx);
            i++;
            idx = jacobsthal(i);// % size; // Assure que l'indice est dans la plage
            indices.push_back(idx);
            break ;
        }
        i++;
    }

    // std::cout << "Indices: ";
    // for (size_t i = 0; i < indices.size(); ++i) {
        // std::cout << indices[i] << " ";
    // }
    // std::cout << std::endl;
    return indices;
}

std::deque<unsigned int> PmergeMe::generateJacobsthalIndicesdeq(int size)
{

    std::deque<unsigned int> indices;
    int i = 0;
    while (true)
    {
        int idx = jacobsthal(i);
        if (idx < size)
            indices.push_back(idx);
        else
        {
            indices.push_back(idx);
            i++;
            idx = jacobsthal(i);
            indices.push_back(idx);
            break ;
        }
        i++;
    }
    return indices;
}

void	PmergeMe::binarySearchInsertion(std::vector<unsigned int>& main,unsigned int value)
{
	std::vector<unsigned int>::iterator start = main.begin();
	std::vector<unsigned int>::iterator end = main.end();
	std::vector<unsigned int>::iterator mid;
	
	while (start != end)
	{
		mid = start + (std::distance(start, end) / 2);
		if (*mid < value)
			start = mid + 1;
		else
			end = mid;
	}
	main.insert(start, value);
}

void	PmergeMe::binarySearchInsertion_deq(std::deque<unsigned int>& main,unsigned int value)
{
	std::deque<unsigned int>::iterator start = main.begin();
	std::deque<unsigned int>::iterator end = main.end();
	std::deque<unsigned int>::iterator mid;
	
	while (start != end)
	{
		mid = start + (std::distance(start, end) / 2);
		if (*mid < value)
			start = mid + 1;
		else
			end = mid;
	}
	main.insert(start, value);
}

void    PmergeMe::FJS_deq(std::deque<std::deque<unsigned int> >&arr, int size)
{
    std::deque<unsigned int> _sort;
    std::deque<unsigned int> _pend;

    std::deque<bool> inserted(size, false);

    for (int i = 0; i < size; i++)
    {
        _sort.push_back(arr[i][1]);
        _pend.push_back(arr[i][0]);
    }
    arr.clear();
    if (this->_deque.size() < 6)
    {
        for (size_t j = 0; j < _pend.size(); j++)
            binarySearchInsertion_deq(_sort, _pend[j]);
    }
    else
    {
        std::deque<unsigned int> jacobsthalIndices = generateJacobsthalIndicesdeq(static_cast<int>(_pend.size()));
        std::deque<int> insertSeq = printf_jcsd(jacobsthalIndices);

        (void) insertSeq;
        _sort.insert(_sort.begin(), _pend[0]);
        for (size_t j = 0; j < _pend.size() + 1; j++)
        {
            size_t idx = insertSeq[j];
            if (idx < _pend.size())
                binarySearchInsertion_deq(_sort, _pend[idx]);
        }

    }
    if (flagImpair== true)
        binarySearchInsertion_deq(_sort, this->impair);
    this->_deque = _sort;
}

void    PmergeMe::sort_vec(std::vector<std::vector<unsigned int> >&arr, int size)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i][1] > arr[i + 1][1])
            {
                std::swap(arr[i][0], arr[i + 1][0]);
                std::swap(arr[i][1], arr[i + 1][1]);
                swapped = true;
            }
        }
    }
}

void    PmergeMe::sort_deq(std::deque<std::deque<unsigned int> >&arr, int size)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i][1] > arr[i + 1][1])
            {
                std::swap(arr[i][0], arr[i + 1][0]);
                std::swap(arr[i][1], arr[i + 1][1]);
                swapped = true;
            }
        }
    }
}

void	PmergeMe::launch_vec(std::vector<unsigned int> arr)
{
    struct timeval d_time_start, d_time_end;
    gettimeofday(&d_time_start, NULL);

    print_arr(this->_vector, 1);
    std::cout << "size vect before :" << this->_vector.size() << std::endl;
    this->straggler(arr);
    this->creating_pair_vec(arr);
    print_arr(this->_vector, 2);
    std::cout << "size vect after :" << this->_vector.size() << std::endl;

    gettimeofday(&d_time_end, NULL);
	long seconds = d_time_end.tv_sec - d_time_start.tv_sec;
    long microseconds = d_time_end.tv_usec - d_time_start.tv_usec;
    this->_time = seconds + microseconds * 1e-6;
    this->flagImpair = 0;

}   

void	PmergeMe::launch_deq(std::deque<unsigned int> arr)
{
    struct timeval d_time_start, d_time_end;
    gettimeofday(&d_time_start, NULL);
    
    print_arr(this->_deque, 1);
    std::cout << "size deque before :" << this->_deque.size() << std::endl;
    this->straggler(arr);
    this->creating_pair_deq(arr);
    print_arr(this->_deque, 2);
    std::cout << "size deque after :" << this->_deque.size() << std::endl;

    gettimeofday(&d_time_end, NULL);
	long seconds = d_time_end.tv_sec - d_time_start.tv_sec;
    long microseconds = d_time_end.tv_usec - d_time_start.tv_usec;
    this->_time = seconds + microseconds * 1e-6;
}

void    PmergeMe::algo()
{
    std::cout << "------------------------------VECTOR FJMI LAUNCH---------------------------" << std::endl;
    launch_vec(this->_vector);
    std:: cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << this->_time << " us" << std::endl;
    std::cout << "------------------------------DEQUE FJMI LAUNCH---------------------------" << std::endl;
    launch_deq(this->_deque);
    std:: cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : " << this->_time << " us" << std::endl;
}

void    PmergeMe::parse(int ac , char **av)
{
    try
    {
        for (int i = 1; i < ac; i++)
        {
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
        algo();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
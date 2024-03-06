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
    // std::cout << "size: " << arr.size() << std::endl;
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
        std::cout << "keeping impair value: m" << this->impair << std::endl;
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
    // mstd::cout << nbOfPairs << std::endl;
    std::deque<std::deque<unsigned int> >array;
    // std::vector<std::vector<int>> array

    for (size_t i = 0; i < _deq.size(); i += 2)
    {
        std::deque<unsigned int>tmp;
        // std::cout << "i: " << i << std::endl;

        tmp.push_back(_deq[i]);
        tmp.push_back(_deq[i + 1]);
        array.push_back(tmp);
    }
    std::cout << "---BEFORE DEQ----" << std::endl;
    this->printf_array(array, nbOfPairs);
    this->sort_deq(array, nbOfPairs);
    // std::cout << "---AFTER DEQM----" << std::endl;
    // this->printf_array(array, nbOfPairs);
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
std::vector<int>  PmergeMe::printf_jcs(std::vector<unsigned int> jcs)
{
    std::vector<int> seq;

    int i = 1;
    
    int jcb_idx = 3;
    int jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);

    // std::cout << "i: " << i << ", jcb_value:" << jacob_value << std::endl;

    int lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        i++;
    }
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);
    // std::cout << "i: " << i << ", jcb_value:" << jacob_value << std::endl;
    
    lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
      
        i++;
    }
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(i);
    seq.push_back(jacob_value);
    // std::cout << "i: " << i << ", jcb_value:" << jacob_value << std::endl;

    lastJacobValue = jacob_value;
    std::vector<int>::iterator it;
    while (i < lastJacobValue - 1)
    {
        it = std::find(seq.begin(), seq.end(), i);
        if (it == seq.end())
            break ;
        else
            i++;
    }
    seq.push_back(i);
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(jacob_value);

    lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        it = std::find(seq.begin(), seq.end(), i);
        if (it == seq.end())
            break ;
        else
            i++;
    }
    seq.push_back(i);
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(jacob_value);

    lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        it = std::find(seq.begin(), seq.end(), i);
        if (it == seq.end())
            break ;
        else
            i++;
    }
    seq.push_back(i);
    jcb_idx++;
    jacob_value = jcs[jcb_idx];
    seq.push_back(jacob_value);

    lastJacobValue = jacob_value;
    while (i < lastJacobValue - 1)
    {
        it = std::find(seq.begin(), seq.end(), i);
        if (it == seq.end())
            seq.push_back(i);
        else
            i++;
    }

    PmergeMe::print_arr(seq, 1);
    return (seq);
}

void    PmergeMe::FJS_vec(std::vector<std::vector<unsigned int> >&arr, int size)
{
    // std::cout << "FJS VEC: " << std::endl;
    // this->printf_array(arr, size);
    std::vector<unsigned int> _sort;
    std::vector<unsigned int> _pend;

    std::vector<bool> inserted(size, false);

    for (int i = 0; i < size; i++)
    {
        _sort.push_back(arr[i][1]);
        _pend.push_back(arr[i][0]);
    }
    // print_arr(_sort, 1);
    // print_arr(_pend, 2);
    arr.clear();
    std::vector<unsigned int> jacobsthalIndices = generateJacobsthalIndices(static_cast<int>(_pend.size()));
    std::vector<int> insertSeq = printf_jcs(jacobsthalIndices);

    (void) insertSeq;
    // std::cout << "jacobindicesize: " << jacobsthalIndices.size() << std::endl;
    // for (size_t j = 0; j < jacobsthalIndices.size() - 1; j++)
    // {
    //     size_t idx = jacobsthalIndices[j];
    //     std::cout << "jacobindice[i] = idx:  " << idx << std::endl;
    //     if (idx < _pend.size())
    //     {
    //         binarySearchInsertion(_sort, _pend[idx]);
    //         std::cout << "pend[idx] dans sort:  " << _pend[idx] << std::endl;
    //     }
    // }
// tri verif indice recup
    // std::cout << "Indices: ";
    // for (size_t i = 0; i < jacobsthalIndices.size(); ++i) {
        // std::cout << jacobsthalIndices[i] << " ";
    // }
    // std::cout << std::endl;
    // for (size_t j = 0; j < jacobsthalIndices.size(); j++) {
        // size_t idx = jacobsthalIndices[j];
    // std::cout << "la" << std::endl;
        // if (!inserted[idx]) { // Vérifiez si l'élément a déjà été inséré
            // binarySearchInsertion(_sort, _pend[idx]);
            // inserted[idx] = true;
        // }
    // }
   // Insérer tout élément restant de _pend qui n'a pas été inséré en raison de doublons dans les indices
    // for (size_t i = 0; i < inserted.size(); ++i) {
        // if (!inserted[i]) {
            // binarySearchInsertion(_sort, _pend[i]);
        // }
    // }
    // classic tri fonctionne seul:
    if (this->_vector.size() < 4)
    {
        std::cout << "2 ou 3" << std::endl;
        for (size_t j = 0; j < _pend.size(); j++)
            binarySearchInsertion(_sort, _pend[j]);
    }
    else
    {
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
    // for (int i = 0; i < size; ++i) {
        // unsigned int idx = jacobsthal(i);// % size; // Assure que l'indice est dans la plage
        // indices.push_back(idx);
    // }

    // std::vector<unsigned int> tempIndices;
    // std::vector<unsigned int> indices;
    // std::set<unsigned int> seenIndices;

   //Générer les nombres de Jacobsthal et les ajouter à tempIndices
    // for (int i = 0; i < size; ++i) {
        // unsigned int idx = jacobsthal(i) % size; // S'assurer que l'indice est dans la plage
        // if (seenIndices.insert(idx).second) { // Insérer dans set pour vérifier la nouveauté
            // indices.push_back(idx); // Ajouter à indices si nouveau
        // }
    // }

    std::cout << "Indices: ";
    for (size_t i = 0; i < indices.size(); ++i) {
        std::cout << indices[i] << " ";
    }
    std::cout << std::endl;
    return indices;


    // std::vector<unsigned int> indices;
    // if (this->_vector.size() < 6)
    // {
        // for (int i = 0; i < size; i++)
        // {
            // indices.push_back(jacobsthal(i));
        // }
    // }
    // else
    // {
        // for (int i = 0; i <= size; ++i)
            // indices.push_back(jacobsthal(i));
// 
    // }
    // std::cout << "indecs: ";
    // print_arr(indices, 4);
    // std::cout << std::endl;
    // return indices;
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

void    PmergeMe::FJS_deq(std::deque<std::deque<unsigned int> >&arr, int size)
{
    std::cout << "FJS DEQ: " << std::endl;
    this->printf_array(arr, size);
    std::deque<unsigned int> _sort;
    std::deque<unsigned int> _pend;

    for (int i = 0; i < size; i++)
    {
        _sort.push_back(arr[i][1]);
        _pend.push_back(arr[i][0]);
    }
    arr.clear();
    std::cout << "i + 1 sorted: " << std::endl;
    for (size_t i = 0; i < _sort.size(); i++)
    {
        std::cout << _sort.at(i) << std::endl;
    }
    std::cout << "i =0 rest: " << std::endl;
    for (size_t j = 0; j < _pend.size(); j++)
    {
        std::cout << _pend.at(j) << std::endl;
    }
    if (flagImpair)
        std::cout << "impair kept: " << this->impair << std::endl;
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
    print_arr(this->_vector, 1);
    std::cout << " size vect before :" << this->_vector.size() << std::endl;
    this->straggler(arr);
    this->creating_pair_vec(arr);
    print_arr(this->_vector, 2);
    std::cout << " size vect after :" << this->_vector.size() << std::endl;
}   

void	PmergeMe::launch_deq(std::deque<unsigned int> arr)
{
    this->straggler(arr);
    this->creating_pair_deq(arr);
}

void    PmergeMe::algo()
{
    launch_vec(this->_vector);
    // std:: cout << "Time to process a range of " << this->_deque.size() << " elements with std::vector : " << this->time << " us" << std::endl;
    // launch_deq(this->_deque);
    // std:: cout << "Time to process a range of " << this->_vector.size() << " elements with std::deque : " << this->time << " us" << std::endl;
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
        // print_arr(this->_deque, 1);
        algo();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}


BitcoinExchange::BitcoinExceptions::BitcoinExceptions(std::string const & str)
{
    this->_errormsg = str;
}

std::string BitcoinExchange::check_separator(std::string line)
{
    std::string until_pipe;
    char        separator = '|';

    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == separator) {
            return (until_pipe); // Quitter la boucle si '|' est trouvé
        }
        until_pipe += line[i]; // Ajouter le caractère à la sous-chaîne
    }
    return ("NULL");
}

bool BitcoinExchange::IsDigit(std::string date, int y, int pos)
{
    for (int i = 0; i < y; i++)
    {
        if (date[pos] < 48 || date[pos] > 57)
            return (0);
    }
    return (1);
}



bool BitcoinExchange::check_year(std::string date)
{
    // std::cout << "CHECK YEAR" << std::endl;

    if (IsDigit(date, 4, 0) == 0)
        return (0);
    std::string year;
    for (int i = 0; i < 4; i++)
    {
        year += date[i];
    }
    int int_year = atoi(year.c_str());
    if (int_year < 2009 || int_year > 2022)
        return (0);
    // std::cout << "year:" << year << std::endl;
    return (1);
}

bool BitcoinExchange::check_month(std::string date, int pos)
{
    // std::cout << "CHECK MONTH" << std::endl;

    if (IsDigit(date, 2, pos) == 0)
        return (0);
    std::string month;
    for (int i = 0; i < 2; i++)
    {
        month += date[pos];
        pos++;

    }
    int int_month = atoi(month.c_str());
    if (int_month < 01 || int_month > 12)
        return (0);
    // std::cout << "month:" << month << std::endl;
    return (1);
}



bool BitcoinExchange::check_tilde_space(std::string date, int i, char c)
{
    // std::cout << "CHECK TILDE SPACE:" << date[i] << std::endl;
    if (date[i] == c)
        return (1);
    else
        return (0);
}

bool BitcoinExchange::check_day(std::string date, int pos)
{
    // std::cout << "CHECK DAY" << std::endl;

    if (IsDigit(date, 2, pos) == 0)
        return (0);
    std::string day;
    for (int i = 0; i < 2; i++)
    {
        day += date[pos];
        pos++;

    }
    int int_day = atoi(day.c_str());
    if (int_day < 01 || int_day > 31)
        return (0);
    // std::cout << "day:" << day << std::endl;
    return (1);
}

bool BitcoinExchange::check_value(std::string str)
{
    char* endPtr;
    double value = strtod(str.c_str(), &endPtr);

    // Vérifier si la conversion est valide
    if (*endPtr != '\0') {
        return (0); // La chaîne contient des caractères invalides
    }
    
    // Vérifier si le nombre est dans la plage valide [0, 1000]
    if (value < 0 || value > 1000) {
        return (0);
    }

    return (1);
}

std::string BitcoinExchange::keep_value(std::string line, int pos)
{
    std::string value;
    while (line[pos])
    {
        value +=line[pos];
        pos++;
    }
    // std::cout << "val:" << value << std::endl;
    return (value);
}

bool BitcoinExchange::check_line(std::string line)
{
    // std::cout << "line:" << line << "$" << line.length() << std::endl;
    std::string date = check_separator(line);
    // std::cout << "date:" << date << "$" << std::endl;
    if (date == "NULL")
        return (0);
    if (date.length() != 11 || line.length() < 14)
        return (0);
    if (check_year(date) == 0)
        return (std::cout << "please keep a date format as : \'XXXX-MM-DD |\'\n", 0);
    if (check_tilde_space(date, 4, '-') == 0)
        return (std::cout << "please keep a date format as : \'XXXX-MM-DD |\'\n", 0);
    if (check_month(date, 5) == 0)
        return (std::cout << "please keep a date format as : \'XXXX-MM-DD |\'\n", 0);
    if (check_tilde_space(date, 7, '-') == 0)
        return (std::cout << "please keep a date format as : \'XXXX-MM-DD |\'\n", 0);
    if (check_day(date, 8) == 0)
        return (std::cout << "please keep a date format as : \'XXXX-MM-DD |\'\n", 0);
    if (check_tilde_space(date, 10, ' ') == 0)
        return (std::cout << "please keep a date format as : \'XXXX-MM-DD |\'\n", 0);
    if (check_tilde_space(line, 11, '|') == 0)
        return (std::cout << "please keep a date format as : \'XXXX-MM-DD |\'\n", 0);
    if (check_tilde_space(line, 12, ' ') == 0)
        return (0);
    std::string value = keep_value(line, 13);
    // std::cout << date[13] << std::endl;
    if (check_value(value) == 0)
        return (std::cout << "please keep a value format as : \' N\'\n", 0);
    return (1);
}

const char* BitcoinExchange::BitcoinExceptions::get_errormsg() const
{
    return ((this->_errormsg).c_str());
}

void   BitcoinExchange::parse(std::string str)
{
    std::ifstream file(str.c_str());
    try
    {
        if (!file.is_open())
            throw BitcoinExchange::BitcoinExceptions("cann'ot open file");
        else if (file.peek() == std::ifstream::traits_type::eof())
            throw BitcoinExchange::BitcoinExceptions("file is empty");
        else
        {
            std::string line;
            std::getline(file, line);
            if (line != "date | value")
                throw BitcoinExchange::BitcoinExceptions("first line must have date | valeur form");
            int i = 0;
            while (std::getline(file, line))
            {
                if (check_line(line) == 0)
                {
                    std::cout << line << " =>";
                    throw BitcoinExchange::BitcoinExceptions("Error: bad input");
                }
                i++;
            }
            if (i == 0)
                throw BitcoinExchange::BitcoinExceptions("at least one line is needed here to calculate");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    file.close();
    //getdate.csv?? 
}

void    BitcoinExchange::verif_extension(std::string str)
{
    std::string filename = str;
    std::string extension = ".txt";
    try
    {
        if (filename.length() <= extension.length())
            throw BitcoinExchange::BitcoinExceptions("filename isn't appropriate");
        if (filename.compare(filename.length() - extension.length(), extension.length(), extension) != 0)
            throw BitcoinExchange::BitcoinExceptions("filename doesn't finish by .txt");
        else
            parse(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
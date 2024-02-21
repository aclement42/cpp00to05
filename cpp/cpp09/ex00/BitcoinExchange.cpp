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
        if ((line[pos] < 48 || line[pos] > 57) && line[pos] != '.' && line[pos] != '+')
            return ("error");
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
    std::string value = keep_value(line, 13);
    // std::cout << "value: \'" << value << "\'" << std::endl;
    try
    {
        if (date == "NULL")
            throw BitcoinExchange::BitcoinExceptions("Error: there is a pipe mistake in file.txt");
        else if (date.length() != 11 || line.length() < 14)
            throw BitcoinExchange::BitcoinExceptions("Error: there is a pipe position mistake in file.txt");
        else if (check_year(date) == 0)
            throw BitcoinExchange::BitcoinExceptions("Error: keep a year format as : 2008 < \'XXXX\' < 2023");
        else if (check_tilde_space(date, 4, '-') == 0)
            throw BitcoinExchange::BitcoinExceptions("you must have a \'-\' between XXXX and MM");
        else if (check_month(date, 5) == 0)
            throw BitcoinExchange::BitcoinExceptions("Error: keep a month format as : 00 < \'MM\' < 13");
        else if (check_tilde_space(date, 7, '-') == 0)
            throw BitcoinExchange::BitcoinExceptions("you must have a \'-\' between MM and DD");
        else if (check_day(date, 8) == 0)
            throw BitcoinExchange::BitcoinExceptions("Error: keep a day format as : 00 < \'DD\' < 32");
        else if (check_tilde_space(date, 10, ' ') == 0)
            throw BitcoinExchange::BitcoinExceptions("Error: please keep a date format as : \'XXXX-MM-DD |\'");
        else if (check_tilde_space(line, 11, '|') == 0)
            throw BitcoinExchange::BitcoinExceptions("Error: please keep a date format as : \'XXXX-MM-DD |\'");
        else if (check_tilde_space(line, 12, ' ') == 0)
            throw BitcoinExchange::BitcoinExceptions("Error: please keep a value format as : \'| N\'");
        else if (check_value(value) == 0)
            throw BitcoinExchange::BitcoinExceptions("Error: please keep a value format as an int or a float : 0 <= \'N\' <= 1000");
        else
            return (1);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

const char* BitcoinExchange::BitcoinExceptions::get_errormsg() const
{
    return ((this->_errormsg).c_str());
}

void    BitcoinExchange::recup_line_and_launch(std::string line)
{
    this->date_to_find = line.substr(0, 10);
    this->value_to_multi = keep_value(line, 13);
    // std::cout << "str value:" << value_to_multi << std::endl;
    // std::cout << line << std::endl;
    // std::cout << this->date_to_find  << "." << std::endl;
    char* endPtr;
    double value = strtod(value_to_multi.c_str(), &endPtr);
    // std::cout << "double value:" << value << std::endl;
    std::map<std::string, double>::iterator it = _data.find(date_to_find);
    if(it == _data.end()) // 
    {
        std::map<std::string, double>::iterator itPrec = _data.lower_bound(date_to_find);
        
        if(itPrec != _data.begin())
        {
            --itPrec;
            std::cout << date_to_find << " => " << value << " = " << (itPrec->second) * value << "." << std::endl;
        }
        else// Si itPrec est au début, il n'y a pas de clé précédente
            std::cout << "Il n'y a pas de clé précédente la plus proche." << std::endl;
    }
    else
        std::cout << date_to_find << " => " << value << " = " << (it->second) * value << "." << std::endl;
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
                if (check_line(line) != 0)
                    recup_line_and_launch(line);
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
}

void BitcoinExchange::getdate(const std::string& filename)
{
        std::ifstream file(filename.c_str());
        try
        {
            if (!file.is_open())
                throw BitcoinExchange::BitcoinExceptions("Erreur : Impossible d'ouvrir le fichier.csv");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::string line;
        while (std::getline(file, line))// Lire chaque ligne du fichier
        { 
            std::istringstream iss(line);
            std::string date_str, value_str;

            if (std::getline(iss, date_str, ',') && std::getline(iss, value_str, ',')) {
                // Convertir la valeur en float
                float value = atof(value_str.c_str());
                // Stocker la date et sa valeur dans le conteneur
                _data.insert(std::make_pair(date_str, value));
            }
        }
        // printdata();
        file.close();
    }

void BitcoinExchange::printdata() const {
        for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
            std::cout << "Date: " << it->first << ", Valeur: " << it->second << std::endl;
        }
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
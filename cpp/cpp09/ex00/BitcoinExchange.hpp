#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void verif_extension(std::string str);
        void parse(std::string str);
        bool check_line(std::string line);
        std::string check_separator(std::string line);
        bool check_year(std::string date);
        bool IsDigit(std::string date, int y, int pos);
        bool check_tilde_space(std::string date, int i, char c);
        bool check_month(std::string date, int pos);
        bool check_day(std::string date, int pos);
        std::string keep_value(std::string line, int pos);
        bool check_value(std::string str);



        class BitcoinExceptions : public std::exception
        {
            private:
                std::string _errormsg;
            public:
                BitcoinExceptions(std::string const & str);
                const char* get_errormsg() const;
                virtual const char* what() const throw()
                {
                    return (get_errormsg());
                }

                virtual ~BitcoinExceptions() throw() {};
        };
};


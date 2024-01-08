#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using   std::cout;
using   std::cin;
using   std::endl;
using   std::string;
using   std::cerr;

string  replacestring(const string &original, const string &s1, const string &s2)
{
    string result = "";
    size_t  begin = 0;
    size_t  end = 0;

    while ((end = original.find(s1, begin)) < original.length())
    {
        result.append(original, begin, end - begin);
        result.append(s2);
        begin = end + s1.length();
    }
    result.append(original, begin, original.length());
    return (result);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        cerr << "Usage: <filename> <s1> <s2>" << endl;
        return (1);
    }
    string  filename = av[1];
    string  s1 = av[2];
    string  s2 = av[3];
    string  outfilename = filename + ".replace";
    std::ifstream   infile;
    std::ofstream   outfile;
    if (s1.empty())
    {
        cerr << "Usage: s1 needed to be replaced" << endl;
        return (1);
    }
    infile.open(filename.c_str());
    if (infile.peek() == std::ifstream::traits_type::eof()) 
    {
        cerr << "Error: canno't open input file: " << filename << endl;
        return (1);
    }
    std::ostringstream inputstream;
    inputstream << infile.rdbuf();
    string inputcontent = inputstream.str();
    string modifcontent = replacestring(inputcontent, s1, s2);
    outfile.open(outfilename.c_str());
    if (!outfile.is_open())
    {        
        cerr << "Error: canno't open input file: " << outfilename << endl;
        return (1);
    }
    outfile << modifcontent;
    infile.close();
    outfile.close();
    return (0);
}
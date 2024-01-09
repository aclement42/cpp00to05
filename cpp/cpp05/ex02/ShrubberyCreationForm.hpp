#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <fstream>
#include <sstream>

class AForm;

class   ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const & obj);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & obj);

        ShrubberyCreationForm(std::string target);
        void    execute(Bureaucrat const & executor) const;
        void    adding_tree(std::ofstream outfile);

};

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("Unkwown target")
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & obj)
{
    *this = obj;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    this->_target = rhs._target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{

}


void    ShrubberyCreationForm::adding_tree(std::ofstream outfile)
{
    outfile << "                              ./(    .      ,.                              " << std::endl;
    outfile << "                  ,/.   ,/     /*(.  *,   #(*                               " << std::endl;
    outfile << "                    #((#***(   .(/(*##/ .%(/                                " << std::endl;
    outfile << "               *,(/   *#/#(/(* .*/((%#/,##(.       (  *(                    " << std::endl;
    outfile << "                    /#(./((((/(.*/(##%*#%(. ,.  #.,%,                       " << std::endl;
    outfile << "                     ,**#(/(%((/,*/%&%##(.,. *//#/.,/.                      " << std::endl;
    outfile << "        .**((#%%#((#,.*   ,#(%#%(*/#%%(/ **/*//%(*. ..*/*.                  " << std::endl;
    outfile << "                  (#/#%#%#((//(%#///##(/(%#(&(./#.         . ..             " << std::endl;
    outfile << "            .((*//*,*/(#%%###*(/#%%#(((%#(((( ..,##(####(***///,/*          " << std::endl;
    outfile << "     ./*/((*..     ,/(((((/*/####(#####(#(/(##((..,*,,/*.                   " << std::endl;
    outfile << "          *((//(((/((*#/(%*,(###%#((%%(##((((*/&%%%%%%*,*/(*.               " << std::endl;
    outfile << "        ,(,%#/*(*(#**(((((#&&%%(((%%%#%##(&(*/(#((/**/#*.   .((///*.        " << std::endl;
    outfile << "      //#%(((. /###(/(((%&%%&#(//((&%%/((//%%&%/(((%%%%#/,*/(.              " << std::endl;
    outfile << "      *.#,  /#(/(%#(//%&#%((%//(/*#&&&%**/(&(*###*/(%##&%#/(/(              " << std::endl;
    outfile << "          /(#(##&@(#/(#,/*(#&*//(&@&##/(/(%&%#*/(*#%%%&/*(#%,(**(           " << std::endl;
    outfile << "        //*(#%%%((##%%*/##%&&*(/&&&&%#*#/#%#%##*,/,&#(#(%%. ((#.*           " << std::endl;
    outfile << "       ./(##%#(((#(#&#((#((&%//%%&%%(#//*/%%(#((/,,/&&/((/%(#./*(/          " << std::endl;
    outfile << "      ,/(%(*%*(####&%#*#%*%%%/###%%%/#(,/(##%((%%/%##&&//(*## /#..,         " << std::endl;
    outfile << "      /#.*(/%//#%(#%#(/&%(##%(#%####/(//((((##((&&/(/%#/%//*/(, *#          " << std::endl;
    outfile << "         //,/#%/((%//(%&(%/((/&%/##((*/*/((,/((/#&%((*(%#/(/( /.            " << std::endl;
    outfile << "            ( (//#///#%,##,/(#/ *((((/(#*// ****%%%%(( (((.%/#              " << std::endl;
    outfile << "           , (/*//#*(/ .#/ *#,   /(/(&&# /   /( .#%#&   */* *..             " << std::endl;
    outfile << "             ,., ./    *#        ,(*%%%*         *#.%(   .   (              " << std::endl;
    outfile << "              .                  .*/%#%.            *(                      " << std::endl;
    outfile << "                                 ./#(%%,                                    " << std::endl;
    outfile << "                                 .(((##*                                    " << std::endl;
    outfile << "                                 .//((#*                                    " << std::endl;
    outfile << "                                 .((((%*                                    " << std::endl;
    outfile << "                                 ,(*(##/                                    " << std::endl;
    outfile << "                                 ,(//((#                                    " << std::endl;
    outfile << "                                 /((/(##                                    " << std::endl;
    outfile << "                               (####%%&%&#.                                 " << std::endl;
    outfile << "                       ,/*//////((/((((((((////((,                          " << std::endl;
    outfile << "                                                                            " << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > 137)
        throw AForm::ExecuteProblem();
    else if (getIssigned() == 0)
        throw AForm::Isnotsigned();
    else
    {
        std::string outfilename;
        outfilename = this->_target;
        outfilename.append("_shrubbery");
        std::ofstream outfile(outfilename.data());
        try
        {
            outfile.is_open();
            adding_tree(outfile);
        }
        catch (std::exception &e)
        {
            outfile.close();
            throw AForm::FileProblems();
        }
        outfile.close();
    }

}

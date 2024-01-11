
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
        if (!outfile.is_open())
            throw AForm::FileProblems();
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
        outfile.close();
    }

}

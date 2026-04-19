/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:57:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/19 20:11:47 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target)  {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)  {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!this->getfSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->geteGrade())
        throw AForm::GradeTooLowException();
    
    if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException();

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Could not create file" << target << std::endl;
        return;
    }
    file << "                     - - -\n";
    file << "                   -        -  -     --    -\n";
    file << "                -                 -         -  -\n";
    file << "               -                 -                -\n";
    file << "              -                -                --\n";
    file << "               -          -            -              -\n";
    file << "               -            '-,        -               -\n";
    file << "               -              'b      *\n";
    file << "                -              '$    #-                --\n";
    file << "               -    -           $:   #:               -\n";
    file << "             --      -  --      *#  @):        -   - -\n";
    file << "                          -     :@,@):   ,-**:'   -\n";
    file << "              -      -,         :@@*: --**'      -   -\n";
    file << "                       '#o-    -:(@'-@* '  -\n";
    file << "               -  -       'bq,--:,@@*'   ,*      -  -\n";
    file << "                          ,p$q8,:@)'  -p*'      -\n";
    file << "                   -     '  - '@@Pp@@*'    -  -\n";
    file << "                    -  - --    Y7'.'     -  -\n";
    file << "                              :@):.\n";
    file << "                             .:@:'.\n";
    file << "                             .:@:'.\n";
    file << "                             .:@:'.\n";
    file << "                             .:@:'.\n";
    file << "                            .::@:.\n";
    file.close();
}

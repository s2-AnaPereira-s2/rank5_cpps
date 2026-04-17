/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:57:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/17 17:07:20 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target)  {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(target)  {}

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

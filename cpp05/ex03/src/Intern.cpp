/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:57:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/19 19:52:05 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) 
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern(){};

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

struct FormEntry
{
    std::string name;
    AForm* (*create)(const std::string&);
};

AForm* Intern::makeForm(const std::string form, const std::string target)
{
    FormEntry forms[3] = {
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPresidential}
    };

    for (int i = 0; i < 3; ++i)
    {
        if (form == forms[i].name)
        {
            std::cout << "Intern creates " << form << std::endl;
            return forms[i].create(target);
        }
    }
    std::cout << "Intern couldn't create " << form << std::endl;
    return 0;
}

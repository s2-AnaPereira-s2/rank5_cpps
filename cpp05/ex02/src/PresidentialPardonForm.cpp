/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:57:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/19 20:10:19 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), target(target)  {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)  {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!this->getfSigned())
    {
        throw AForm::FormNotSignedException();
    }
    else if (executor.getGrade() > this->geteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    else if (executor.getGrade() < 1)
    {
		throw AForm::GradeTooHighException();
    }
    std::cout << this->target 
        << " has been pardoned by Zaphod Beeblebrox."
        << std::endl;
}

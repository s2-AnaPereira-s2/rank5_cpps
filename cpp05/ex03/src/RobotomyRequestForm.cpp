/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:57:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/18 19:56:41 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), target(target)  {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)  {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!this->getfSigned())
    {
        std::cout << "Robotomy failed" << std::endl;
        throw AForm::FormNotSignedException();
    }
    else if (executor.getGrade() > this->geteGrade())
    {
        std::cout << "Robotomy failed" << std::endl;
        throw AForm::GradeTooLowException();
    }
    std::cout << "..Whirrrrrrrrrrr..Whirrrrrrrrrrr..Whirrrrrrrrrrr..\n"
        << this->target << " has been robotomized successfully 50% of the time."
        << std::endl;
}

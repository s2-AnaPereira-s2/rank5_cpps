/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:57:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/19 20:55:57 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

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
    static bool turn = false;
    
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
    std::cout << "..Whirrrrrrrrrrr..drilling noises..\n" << std::endl;
    if (!turn)
    {
        std::srand(std::time(NULL));
        turn = true;
    }
    if (std::rand() % 2 == 0)
    {
        std::cout << this->target << " has been robotomized successfully." 
            << std::endl;
    }
    else
        std::cout << this->target << " robotomy failed." << std::endl;
}

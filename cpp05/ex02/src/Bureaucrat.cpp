/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:15:20 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/17 12:14:01 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int bGrade) : name(name), bGrade(bGrade)  
{
    if (this->bGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->bGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), bGrade(other.bGrade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->bGrade = other.bGrade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Grade is at highest possible");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Grade is at lowest possible");
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->bGrade;
}

void Bureaucrat::incrementGrade()
{
    int grade;

    grade = getGrade();
    if (grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    else
        this->bGrade -= 1;
}

void Bureaucrat::decrementGrade()
{
    int grade;

    grade = getGrade();
    if (grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    else
        this->bGrade += 1;
} 

void Bureaucrat::signForm(Form& form)
{
    std::string name;
    int grade;

    name = getName();
    grade = getGrade();
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cout << name 
            << " could not sign " 
            << form.getName() 
            << " because " 
            << e.what() 
            << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";  
    return os;
}

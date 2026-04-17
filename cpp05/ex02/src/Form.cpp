/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:15:20 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/17 12:18:21 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, bool fSigned, int sGrade, int eGrade) : name(name), fSigned(fSigned), sGrade(sGrade), eGrade(eGrade)  {}

Form::Form(const Form& other) : name(other.name), fSigned(other.fSigned), sGrade(other.sGrade), eGrade(other.eGrade) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->fSigned = other.fSigned;
        this->sGrade = other.sGrade;
        this->eGrade = other.eGrade;
    }
    return *this;
}

Form::~Form(){}

const char* Form::GradeTooHighException::what() const throw() 
{
    return ("Grade is at highest possible.");
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return ("Grade is lower than required.");
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getfSigned() const
{
    return this->fSigned;
}

int Form::getsGrade() const
{
    return this->sGrade;
}

int Form::geteGrade() const
{
    return this->eGrade;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getsGrade())
        throw Form::GradeTooLowException();
    else
        this->fSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() 
        <<"\nForm is signed: " << form.getfSigned() 
        << "\nGrade required to sign: " << form.getsGrade() 
        << "\nGrade required to execute: " << form.geteGrade();  
    return os;
}

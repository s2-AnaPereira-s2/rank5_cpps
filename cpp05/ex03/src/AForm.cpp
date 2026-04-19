/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:15:20 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/17 17:29:25 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const &name, bool fSigned, int sGrade, int eGrade) : name(name), fSigned(fSigned), sGrade(sGrade), eGrade(eGrade)  
{
    if (this->sGrade < 1 || this->eGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->sGrade > 150 || this->eGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), fSigned(other.fSigned), sGrade(other.sGrade), eGrade(other.eGrade) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->fSigned = other.fSigned;
        this->sGrade = other.sGrade;
        this->eGrade = other.eGrade;
    }
    return *this;
}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return ("Grade is at highest possible.");
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return ("Grade is lower than required.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form must be signed.");
}

const char* AForm::FormAlreadySignedException::what() const throw() 
{
    return ("Form is already signed.");
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getfSigned() const
{
    return this->fSigned;
}

int AForm::getsGrade() const
{
    return this->sGrade;
}

int AForm::geteGrade() const
{
    return this->eGrade;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getsGrade())
        throw GradeTooLowException();
    else
        this->fSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    std::string fstatus;

    if (form.getfSigned() == 0)
        fstatus = "No";
    else if (form.getfSigned() == 1)
        fstatus = "Yes";
    os << "\nForm: " << form.getName() 
        << "\nForm is signed: " << fstatus 
        << "\nGrade required to sign: " << form.getsGrade() 
        << "\nGrade required to execute: " << form.geteGrade()
        << std::endl; 
    return os;
}

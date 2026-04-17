/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:07:47 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/17 17:29:42 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        std::string const name; 
        bool fSigned;
        int sGrade;
        int eGrade;
   
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        AForm(std::string const &name, bool fSigned, int sGrade, int eGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        void beSigned(Bureaucrat& bureaucrat);
        std::string getName() const;
        bool getfSigned() const;
        int getsGrade() const;
        int geteGrade() const;
        virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
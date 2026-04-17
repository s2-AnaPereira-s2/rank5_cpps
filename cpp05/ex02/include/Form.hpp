/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:07:47 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/17 12:18:15 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
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
        Form(std::string name, bool fSigned,int sGrade, int eGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        void beSigned(Bureaucrat& bureaucrat);
        std::string getName() const;
        bool getfSigned() const;
        int getsGrade() const;
        int geteGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
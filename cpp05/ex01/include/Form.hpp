/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:07:47 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/16 18:52:23 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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

        void beSigned(std::string name);
        std::string getName() const;
        bool Form::getfSigned() const;
        int Form::getsGrade() const;
        int Form::geteGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
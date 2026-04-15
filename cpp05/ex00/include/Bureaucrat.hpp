/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:07:47 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/15 18:48:51 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT.HPP
#define BUREAUCRAT.HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        std::string const name; 
        int grade;

        class GradeTooHighException : public std::exception
        {
            public:
                ;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                ;
        };
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        void updateGrade(std::string name, int grade);
        std::string getName();
        int getGrade();
};

#endif
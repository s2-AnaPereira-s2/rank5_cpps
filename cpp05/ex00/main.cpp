/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:58:45 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/16 18:03:56 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Create a normal Bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 50);
        std::cout << b1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "=== Test 1: Create a Bureaucrat above highest grade ===" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 0);
        std::cout << b1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "=== Test 1: Create a Bureaucrat below lowest grade ===" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 151);
        std::cout << b1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Increment grade (should work) ===" << std::endl;
    try
    {
        Bureaucrat b2("Bob", 2);
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Increment at grade 1 (should throw GradeTooHighException) ===" << std::endl;
    try
    {
        Bureaucrat b3("Charlie", 1);
        std::cout << b3 << std::endl;
        b3.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Decrement at grade 150 (should throw GradeTooLowException) ===" << std::endl;
    try
    {
        Bureaucrat b4("Diana", 150);
        std::cout << b4 << std::endl;
        b4.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
    try
    {
        Bureaucrat b5("Eve", 75);
        Bureaucrat b6 = b5;
        std::cout << b5 << std::endl;
        std::cout << b6 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
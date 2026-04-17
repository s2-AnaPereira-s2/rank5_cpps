/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:58:52 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/17 11:49:30 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "===== BUREAUCRAT & FORM TESTS =====" << std::endl << std::endl;

    try
    {
        std::cout << "--- Test 1: Creating valid Bureaucrat and Form ---" << std::endl;
        Bureaucrat b1("Alice", 50);
        Form f1("TaxForm", false, 40, 30);
        
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    try
    {
        std::cout << "--- Test 2: Bureaucrat with invalid high grade ---" << std::endl;
        Bureaucrat b2("Bob", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    try
    {
        std::cout << "--- Test 3: Bureaucrat with invalid low grade ---" << std::endl;
        Bureaucrat b3("Charlie", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    try
    {
        std::cout << "--- Test 4: Signing a Form ---" << std::endl;
        Bureaucrat b4("Diana", 35);
        Form f2("PermitForm", false, 40, 30);
        
        std::cout << "Before signing: " << f2.getfSigned() << std::endl;
        b4.signForm(f2);
        std::cout << "After signing: " << f2.getfSigned() << std::endl << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    try
    {
        std::cout << "--- Test 5: Grade too low to sign ---" << std::endl;
        Bureaucrat b5("Eve", 50);
        Form f3("ExecutiveForm", false, 30, 20);
        
        b5.signForm(f3);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    try
    {
        std::cout << "--- Test 6: Incrementing and Decrementing Grade ---" << std::endl;
        Bureaucrat b6("Frank", 75);
        std::cout << "Initial: " << b6.getGrade() << std::endl;
        b6.incrementGrade();
        std::cout << "After increment: " << b6.getGrade() << std::endl;
        b6.decrementGrade();
        std::cout << "After decrement: " << b6.getGrade() << std::endl << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl << std::endl;
    }

    std::cout << "===== TESTS COMPLETED =====" << std::endl;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:58:56 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/19 18:13:40 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void testShrubbery()
{
    std::cout << "=== ShrubberyCreationForm test ===\n";

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 150);
    ShrubberyCreationForm form("garden");

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;
    std::cout << form << std::endl;

    std::cout << "\n--- Try signing with low grade ---\n";
    try
    {
        worker.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Sign with high grade ---\n";
    try
    {
        boss.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Try execute with low grade ---\n";
    try
    {
        worker.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Execute with high grade ---\n";
    try
    {
        boss.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nCheck file: garden_shrubbery\n";
}

static void testRobotomy()
{
    std::cout << "\n=== RobotomyRequestForm test ===\n";

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 150);
    Bureaucrat mid("Mid", 70);
    RobotomyRequestForm form("marvin");

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;
    std::cout << mid << std::endl;
    std::cout << form << std::endl;

    std::cout << "\n--- Try execute unsigned form ---\n";
    try
    {
        boss.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Try signing with low grade ---\n";
    try
    {
        worker.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Sign with valid grade ---\n";
    try
    {
        mid.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Try execute with insufficient grade ---\n";
    try
    {
        mid.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Execute with high grade ---\n";
    try
    {
        boss.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

static void testPresidential()
{
    std::cout << "\n=== PresidentialPardonForm test ===\n";

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 150);
    Bureaucrat mid("Mid", 70);
    PresidentialPardonForm form("Arthur Dent");

    std::cout << boss << std::endl;
    std::cout << worker << std::endl;
    std::cout << mid << std::endl;
    std::cout << form << std::endl;

    std::cout << "\n--- Try execute unsigned form ---\n";
    try
    {
        boss.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Try signing with low grade ---\n";
    try
    {
        worker.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Sign with valid grade ---\n";
    try
    {
        mid.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Try execute with insufficient grade ---\n";
    try
    {
        mid.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Execute with high grade ---\n";
    try
    {
        boss.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    try
    {
        testShrubbery();
        testRobotomy();
        testPresidential();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}
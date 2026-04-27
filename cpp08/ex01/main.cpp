/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:20:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 22:46:31 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "\n==== Test 1: Basic functionality ====" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        
        std::cout << "Numbers: 6 3 17 9 11\n" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   
        
        std::cout << "\n==== Test 2: Exception - not enough numbers ====" << std::endl;
        Span sp2 = Span(5);
        sp2.addNumber(1);
        try
        {
            sp2.shortestSpan();
        }
        catch (std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        try
        {
            sp2.longestSpan();
        }
        catch (std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }


        std::cout << "\n==== Test 3: Exception - storage full ====" << std::endl;
        try
        {
            sp.addNumber(42);
        }
        catch (std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n==== Test 4: Large test with 10,000 numbers ====" << std::endl;
        Span sp3 = Span(10000);
        for (unsigned int i = 0; i < 10000; i++)
            sp3.addNumber(i);
        std::cout << "Shortest span (10k): " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span (10k): " << sp3.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
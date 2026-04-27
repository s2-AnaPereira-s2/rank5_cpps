/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:20:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 17:11:10 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    std::cout << "===== Testing with VECTOR =====" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(5);
        v.push_back(10);
        v.push_back(42);
        v.push_back(100);

        std::cout << "\nTest 1: Find existing value (42)" << std::endl;
        try 
        {
            easyFind(v, 42);
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest 2: Find first occurrence (5)" << std::endl;
        try 
        {
            easyFind(v, 5);
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest 3: Value not found (999)" << std::endl;
        try 
        {
            easyFind(v, 999);
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n===== Testing with LIST =====" << std::endl;
    {
        std::list<int> l;
        l.push_back(2);
        l.push_back(8);
        l.push_back(15);
        l.push_back(32);

        std::cout << "\nTest 4: Find in list (15)" << std::endl;
        try 
        {
            easyFind(l, 15);
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest 5: Value not in list (200)" << std::endl;
        try 
        {
            easyFind(l, 200);
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n===== Testing with DEQUE =====" << std::endl;
    {
        std::deque<int> d;
        d.push_back(3);
        d.push_back(7);
        d.push_back(11);
        d.push_back(19);

        std::cout << "\nTest 6: Find in deque (11)" << std::endl;
        try 
        {
            easyFind(d, 11);
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest 7: Value not in deque (50)" << std::endl;
        try 
        {
            easyFind(d, 50);
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    return (0);
}

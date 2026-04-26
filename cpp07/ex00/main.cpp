/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:18:27 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 00:20:05 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
    int a = 2;
    int b = 3;
    std::cout << "Before swap: " << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: " << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    
    std::string c = "Ana";
    std::string d = "Keillin";
    std::cout << "Before swap: " << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: " << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    
    return 0;
}
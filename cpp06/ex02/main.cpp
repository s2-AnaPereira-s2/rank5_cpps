/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/04/24 00:22:20 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    srand(time(NULL));
    
    std::cout << "=== Testing with pointers ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        std::cout << "Generated object " << i + 1 << " is: ";
        identify(obj);
        delete obj;
    }
    
    std::cout << "\n=== Testing with references ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        std::cout << "Generated object " << i + 1 << " is: ";
        identify(*obj);
        delete obj;
    }
    
    return (0);
}

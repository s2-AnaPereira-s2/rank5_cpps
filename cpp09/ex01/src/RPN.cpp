/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/04/30 18:07:23 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : numbers() {}
        
RPN::RPN(const RPN &other) : numbers(other.numbers) {}

RPN& RPN::operator=(const RPN &other) 
{
    if (this != &other) 
    {
        numbers = other.numbers;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::RPN_calc(std::string expression)
{
    for (int i = 0; expression[i]; i++)
    {
        if (isdigit(expression[i]))
        {
            numbers.push(expression[i]);
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*')
        {
            int n1 = numbers.top();
            numbers.pop();
            int n2 = numbers.top();
            
        }
        
    }
    
}


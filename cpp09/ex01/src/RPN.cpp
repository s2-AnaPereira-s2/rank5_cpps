/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/04/30 23:03:34 by ana              ###   ########.fr       */
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
        if (!isdigit(expression[i]))
        {
            std::cerr << "Error: invalid expression" << std::endl;
            return;
        }
        if (isspace(expression[i]))
        {
            continue;
        }
        else if (isdigit(expression[i]))
        {
            numbers.push(expression[i] - '0');
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*')
        {
            int n1 = numbers.top();
            numbers.pop();
            int n2 = numbers.top();
            numbers.pop();
            switch (expression[i])
            {
                case '+':
                    numbers.push(n2 + n1);
                    break;
                case '-':
                    numbers.push(n2 - n1);
                    break;
                case '*':
                    numbers.push(n2 * n1);
                    break;
                case '/':
                    numbers.push(n2 / n1);
                    break;
            }
            
        }
        else if (expression[i] != '+' || expression[i] != '-' || expression[i] != '/' || expression[i] != '*')
        {
            std::cerr << "Error: invalid expression" << std::endl;
            return;
        }
        
    }
    if (numbers.size() != 1)
    {
        std::cerr << "Error: invalid expression" << std::endl;
        return;
    }
    std::cout << numbers.top() << std::endl;
}


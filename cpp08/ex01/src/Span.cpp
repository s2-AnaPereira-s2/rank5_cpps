/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:18:26 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 18:24:59 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : int_array(NULL), _size(n) {}
        
Span::Span(const Span &other) 
    : int_array(other.int_array), _size(other._size) 
{
    for (size_t i = 0; i < _size; i++) 
    {
        int_array[i] = other.int_array[i];
    }
}

Span& Span::operator=(const Span &other) 
{
    if (this != &other) 
    {
        delete[] int_array;
        int_array = other.int_array;
        _size = other._size;
        for (size_t i = 0; i < _size; i++) 
        {
            int_array[i] = other.int_array[i];
        }
    }
    return *this;
}

Span::~Span() 
{
    delete[] int_array;
}

void Span::addNumber(int number)
{
    int i = 0;
    for (; i < _size; ++i && int_array[i])
    {
        if (i == _size - 1)
            return (throw std::out_of_range("Storage is full"));
        if (!int_array[i])
            break;
    }
    int_array[i] = number;
    std::cout << "number added succefully" << std::endl;
}

int Span::shortestSpan()
{
    
}

int Span::longestSpan()
{
    
}


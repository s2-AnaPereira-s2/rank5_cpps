/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:18:26 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 22:29:14 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : int_array(new int[n]), _size(n), count(0) {}
        
Span::Span(const Span &other) 
    : int_array(new int[other._size]), _size(other._size), count(other.count)
{
    for (unsigned int i = 0; i < _size; i++) 
    {
        int_array[i] = other.int_array[i];
    }
}

Span& Span::operator=(const Span &other) 
{
    if (this != &other) 
    {
        delete[] int_array;
        int_array = new int[other._size];
        _size = other._size;
        count = other.count;
        for (unsigned int i = 0; i < _size; i++) 
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
    if (count >= _size)
        throw std::out_of_range("Storage is full");
    int_array[count++] = number;
}

int Span::shortestSpan()
{
    if (count < 2)
        throw std::out_of_range("No span can be found");
    
    int span = INT_MAX;
    unsigned int i = 0;
    while (i < count - 1)
    {
        unsigned int y = i + 1;
        for (; y < count; y++)
        {
            int diff = abs(int_array[i] - int_array[y]);
            if (span > diff)
                span = diff;
        }
        i++;
    }
    return span;
}

int Span::longestSpan()
{
    if (count < 2)
        throw std::out_of_range("No span can be found");
    
    int* min_ptr = std::min_element(int_array, int_array + count);
    int min = *min_ptr;
    int* max_ptr = std::max_element(int_array, int_array + count);
    int max = *max_ptr;
    
    int span = max - min;
    return span;
}


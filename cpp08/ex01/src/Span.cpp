/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:18:26 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/28 12:14:51 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : vec(), _size(n) {}
        
Span::Span(const Span &other) : vec(other.vec), _size(other._size) {}

Span& Span::operator=(const Span &other) 
{
    if (this != &other) 
    {
        vec = other.vec;
        _size = other._size;
        
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (vec.size() >= _size)
        throw std::out_of_range("Storage is full");
    vec.push_back(number);
}

int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw std::out_of_range("No span can be found");

    int span = INT_MAX;
    size_t i = 0;
    while (i < vec.size() - 1)
    {
        size_t y = i + 1;
        for (; y < vec.size(); y++)
        {
            int diff = abs(vec[i] - vec[y]);
            if (span > diff)
                span = diff;
        }
        i++;
    }
    return span;
}

int Span::longestSpan()
{
    if (vec.size() < 2)
        throw std::out_of_range("No span can be found");
    
    std::vector<int> sorted = vec;
    std::sort(sorted.begin(), sorted.end());
    
    int span = sorted[sorted.size() - 1] - sorted[0];
    
    return span;
}


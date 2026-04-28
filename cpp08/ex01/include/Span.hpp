/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:17:51 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/28 12:45:05 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int _size;
        
    public:
        Span(unsigned int _size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

        template<typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            size_t range_size = std::distance(begin, end);
            if (vec.size() + range_size > _size)
                throw std::out_of_range("Range bigger than storage available");
            vec.insert(vec.end(), begin, end);
        }
};

#endif
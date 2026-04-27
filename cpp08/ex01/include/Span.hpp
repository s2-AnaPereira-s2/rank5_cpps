/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:17:51 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 23:02:46 by ana              ###   ########.fr       */
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
        int *int_array;
        unsigned int _size;
        unsigned int count;
        
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
            for (Iterator it = begin; it != end; ++it)
                addNumber(*it);
        }
};

#endif
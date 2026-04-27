/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:17:51 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 11:13:28 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <cstdlib>

template <typename T>
class Array {
    private:
        T *data;
        size_t _size;
    
    public:
        Array() : data(NULL), _size(0) {}
        
        Array(unsigned int n) : data(new T[n]), _size(n) {}
        
        Array(const Array &other) 
            : data(new T[other._size]), _size(other._size) 
        {
            for (size_t i = 0; i < _size; i++) 
            {
                data[i] = other.data[i];
            }
        }

        Array& operator=(const Array &other) 
        {
            if (this != &other) 
            {
                delete[] data;
                data = new T[other._size];
                _size = other._size;
                for (size_t i = 0; i < _size; i++) 
                {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }
        
        ~Array() 
        {
            delete[] data;
        }

        T& operator[](size_t index) 
        {
            if (index >= _size) 
            {
                throw std::out_of_range("Exception: Out of bounds access try");
            }
            return data[index];
        }
        
        size_t size() const 
        {
            return _size;
        }
        
};

#endif
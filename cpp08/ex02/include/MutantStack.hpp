/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:17:51 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 23:39:29 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
    
        public:
            MutantStack() : std::stack<T>() {}
            MutantStack(const MutantStack &other) : std::stack<T>(other) {}
            MutantStack& operator=(const MutantStack &other)
            {
                if (this != &other)
                    std::stack<T>::operator=(other);
                return *this;
            }
            ~MutantStack() {}
            
            typedef typename std::stack<T>::container_type::iterator iterator;
            iterator begin()
            {
                return this->c.begin();
            }
            
            iterator end()
            {
                return this->c.end();
            }
            
            typedef typename std::stack<T>::container_type::const_iterator const_iterator;
            const_iterator begin() const
            {
                return this->c.begin();
            }
            
            const_iterator end() const
            {
                return this->c.end();
            }
};

#endif
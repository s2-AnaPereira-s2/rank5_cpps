/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:17:51 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 17:06:08 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <cstddef>
#include <cstdlib>

template <typename T>
void easyFind(T& container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        if (*it == value)
        {
            std::cout << "Value found" << std::endl;
            return;
        }
    }
    throw std::out_of_range("Value not found in the container");
}



#endif
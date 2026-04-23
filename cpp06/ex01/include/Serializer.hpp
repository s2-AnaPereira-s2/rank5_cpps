/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:17:51 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/23 23:58:23 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include <string>

struct Data
{
    int id;
    std::string name;
};


class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
        ~Serializer();
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif
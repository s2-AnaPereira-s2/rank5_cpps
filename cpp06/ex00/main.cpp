/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:10:55 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/23 18:53:23 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main (int argc, char **argv) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

/*
    "a",
    "\n",
    "42",
    "7",
    "42.5f",
    "42.5",
    "42.0f",
    "42.0",
    "nan",
    "nanf",
    "+inf",
    "-inff",
    "2147483648",
    "hello",
    "9"
*/
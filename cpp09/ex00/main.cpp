/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:20:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/30 13:33:43 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2)
        return ((std::cout << "Invalid number of argument" << std::endl), 1);
    
    BitcoinExchange db;
    db.create_db();
    db.input_parse(argv[1]);
    
    return 0;
}

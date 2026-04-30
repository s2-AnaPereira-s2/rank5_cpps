/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:20:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/29 21:12:49 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main() 
{
    /*if (argc != 2)
        return ((std::cout << "Invalid number of argument" << std::endl), 1);*/
    
    BitcoinExchange db;
    db.create_db();
    db.displayPrices(); //checking db
    
    
    
    return 0;
}

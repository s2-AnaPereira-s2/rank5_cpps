/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/04/29 16:10:24 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>


BitcoinExchange::BitcoinExchange() : prices() {}
        
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : prices(other.prices) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    if (this != &other) 
    {
        prices = other.prices;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::addPrices(const std::string& date, double price)
{
    std::string nd = date + " | ";
    prices.insert(std::make_pair(nd, price));
}

void BitcoinExchange::create_db(std::string filename)
{
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return;
    }
    
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        double price = std::atof(line.substr(pos + 1).c_str());
    
        addPrices(date, price);
    }
    file.close();
}

void BitcoinExchange::displayPrices() const
{
    typedef std::map<std::string, double>::const_iterator MapIterator;
    for (MapIterator it = prices.begin(); it != prices.end(); ++it) {
        std::cout << it->first << it->second << "\n";
    }
}
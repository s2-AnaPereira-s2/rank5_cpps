/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinShow.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/04/29 22:12:24 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int date_check(std::string date)
{
    int sc = 0;
    for (int i = 0; date[i]; i++)
    {
        if (date[i] == '-')
            sc++;
    }
    if (sc != 2)
        return 0;
    int i = 0;
    for (; date[i]; i++);
    if (i != 10)
        return 0;
    std::string year;
    size_t pos = date.find('-');
    
    return 1;
}

void input_parse(std::string input)
{
    std::ifstream file(input.c_str());
    
    if (!file.is_open()) 
    {
        std::cerr << "Error: Cannot open " << input << "\n";
        return;
    }
    
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
            std::cout << "Error: bad input missing separator" << std::endl;
        std::string date = line.substr(0, pos);
        double value = std::atof(line.substr(pos + 1).c_str());
        
        if (!date_check(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return;
        }
        if (!value_check(value))
            return;
        
    }
    file.close();
}

void findnshow(std::map<std::string, double> prices, std::string date, double price)
{
    if (prices.at())
}


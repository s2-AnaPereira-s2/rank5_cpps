/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinShow.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/04/30 11:38:29 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int date_check(std::string date)
{
    if (date.length() != 10)
        return 0;
    int year, month, day;
    if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
        return 0;
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return 0;
    return 1;
}

static int value_check(double value)
{
    if (value < 0)
        return (std::cout << "Error: negative value", 0);
    return 1;
}

void findnshow(const std::map<std::string, double>& prices, std::string date, double price)
{
    if (prices.find(date) == prices.end())
        
}

static int input_check(std::string input, const std::map<std::string, double>& prices)
{
    std::ifstream file(input.c_str());
    
    if (!file.is_open()) 
    {
        std::cerr << "Error: Cannot open " << input << "\n";
        return 0;
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
            return 0;
        }
        if (!value_check(value))
            return 0;
        findnshow(prices, date, value);
    }
    file.close();
    return 1;
}



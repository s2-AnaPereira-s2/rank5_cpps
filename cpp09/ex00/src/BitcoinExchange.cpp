/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:00:00 by ana               #+#    #+#             */
/*   Updated: 2026/04/30 16:28:25 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
    prices.insert(std::make_pair(date, price));
}

void BitcoinExchange::create_db()
{
    std::string filename = "data.csv";
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
    
        this->addPrices(date, price);
    }
    file.close();
}

static bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int date_check(std::string date)
{
    if (date.length() != 10)
        return 0;
    int year, month, day;
    if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
        return 0;
    if(is_leap_year(year) && month == 2 && day > 29)
        return 0;
    if(month == 2 && day > 28)
        return 0;
    if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && (day < 01 || day > 30))
        return 0;
    if ( day < 01 || day > 31)
        return 0;
    return 1;
}

static int value_check(double value)
{
    if (value < 0)
        return (std::cerr << "Error: not a positive number" << std::endl, 0);
    if (value > 1000)
        return (std::cerr << "Error: value too large" << std::endl, 0);
    return 1;
}

static double get_closest_price(const std::map<std::string, double>& prices, std::string date)
{
    std::map<std::string, double>::const_iterator it = prices.lower_bound(date);
    if (it == prices.end()) 
    {
        it--;
    }
    else if (it->first != date && it != prices.begin())
    {
        it--;
    }
    return it->second;
}

void findnshow(const std::map<std::string, double>& prices, std::string date, double value)
{
    if (prices.find(date) == prices.end())
    {
        
        double price = get_closest_price(prices, date);
        double total = value * price;
        std::cout << date << " => " << value << " = " << total << std::endl;
        return;
    }
    double price = prices.at(date);
    double total = value * price;
    std::cout << date << " => " << value << " = " << total << std::endl;
}

void BitcoinExchange::input_parse(const std::string input)
{
    std::ifstream file(input.c_str());
    
    if (!file.is_open()) 
    {
        std::cerr << "Error: Cannot open " << input << "\n";
        return;
    }
    
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        std::string date = line.substr(0, pos - 1);
        double value = std::atof(line.substr(pos + 2).c_str());
        if (!date_check(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!value_check(value))
            continue;
        findnshow(prices, date, value);
    }
    file.close();
}

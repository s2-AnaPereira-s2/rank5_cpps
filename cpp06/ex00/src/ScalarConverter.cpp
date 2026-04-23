/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:18:27 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/23 18:37:44 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static void pseudoLit_convert(const std::string& pType, const std::string& literal)
{
    if (pType == "fpl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }
    if (pType == "dpl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal + "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
}

static void charLit_convert(const std::string& literal)
{
    double value = static_cast<double>(literal[0]);

    if (!std::isprint(static_cast<unsigned char>(literal[0])))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << literal[0] << std::endl;
    std::cout << "int: " << static_cast<int>(value)<< std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    return;

}

static void intLit_convert(const std::string& literal)
{
    char* end = NULL;
    double value = std::strtod(literal.c_str(), &end);

    if (value > INT_MAX || value < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int intValue = static_cast<int>(value);
        
        if (intValue < 0 || intValue > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<unsigned char>(intValue)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(intValue) << std::endl;
        std::cout << "int: " << intValue << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    return;
}

static void floatLit_convert(const std::string& literal)
{
    char* end = NULL;
    double value = std::strtod(literal.c_str(), &end);
    
    if (value > INT_MAX || value < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int intValue = static_cast<int>(value);
        
        if (intValue < 0 || intValue > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<unsigned char>(intValue)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(intValue) << std::endl;
        std::cout << "int: " << intValue << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    return;
}

static void doubleLit_convert(const std::string& literal)
{
    char* end = NULL;
    double value = std::strtod(literal.c_str(), &end);

    if (value > INT_MAX || value < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int intValue = static_cast<int>(value);
        
        if (intValue < 0 || intValue > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<unsigned char>(intValue)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(intValue) << std::endl;
        std::cout << "int: " << intValue << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    return;
}

int ScalarConverter::convert(const std::string& literal)
{
    const bool charLit = isCharLiteral(literal);
    const bool intLit = isIntLiteral(literal);
    const bool floatLit = isFloatLiteral(literal);
    const bool doubleLit = isDoubleLiteral(literal);
    const std::string pseudoLit = isPseudoLiteral(literal);

    if (pseudoLit != "none")
        return (pseudoLit_convert(pseudoLit, literal), 0);
    if (charLit)
        return (charLit_convert(literal), 0);
    if (intLit)
        return (intLit_convert(literal), 0);
    if (floatLit)
        return (floatLit_convert(literal), 0);
    if (doubleLit)
        return (doubleLit_convert(literal), 0);
        
    std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
    return 1;
}


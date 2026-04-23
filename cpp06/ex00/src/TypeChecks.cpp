/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeChecks.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:18:38 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/23 18:18:46 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string isPseudoLiteral(const std::string arg)
{
    const std::string fPseudoLiterals[8] = {"nanf", "inff", "-inff", "+inff"};
    const std::string dPseudoLiterals[8] = {"nan", "inf", "-inf", "+inf"};
    
    for (size_t i = 0; i < 4; ++i)
    {
        if (arg == fPseudoLiterals[i])
            return "fpl";
        if (arg == dPseudoLiterals[i])
            return "dpl";
    }
    return "none";
}

bool isCharLiteral(const std::string& arg)
{
    int argLen = arg.length();
    if (argLen == 1
        && std::isprint(static_cast<unsigned char>(arg[0]))
        && !std::isdigit(static_cast<unsigned char>(arg[0])))
        return true;
    return false;
}

bool isIntLiteral(const std::string& arg)
{
    size_t i = 0;

    if (arg.empty())
        return false;
    if (arg[0] == '+' || arg[0] == '-')
        i = 1;
    if (i >= arg.length())
        return false;
    for (; i < arg.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(arg[i])))
            return false;
    }
    return true;
}

bool isFloatLiteral(const std::string& arg)
{
    size_t i = 0;
    int dot = 0;
    int digits = 0;

    if (arg.length() < 2 || arg[arg.length() - 1] != 'f')
        return false;

    if (arg[0] == '+' || arg[0] == '-')
        i = 1;
    while (i < arg.length() - 1)
    {
        if (arg[i] == '.')
        {
            dot++;
            i++;
        }
        else if (!std::isdigit(static_cast<unsigned char>(arg[i])))
            return false;
        else
        {
            i++;
            digits++;
        }
    }
    if (dot == 1 && digits != 0)
        return true;
    return false;
}

bool isDoubleLiteral(const std::string& arg)
{
    size_t i = 0;
    int dot = 0;
    int digits = 0;

    if (arg.empty())
        return false;

    if (arg[0] == '+' || arg[0] == '-')
        i = 1;
    
    while (i < arg.length())
    {
        if (arg[i] == '.')
        {
            dot++;
            i++;
        }
        else if (!std::isdigit(static_cast<unsigned char>(arg[i])))
            return false;
        else
        {
            i++;
            digits++;
        }
    }
    if (dot == 1 && digits != 0)
        return true;
    return false;
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeChecks.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:18:01 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/23 18:18:04 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECHECKS_HPP
#define TYPECHECKS_HPP

#include <fstream>
#include <string>
#include <iostream>

std::string isPseudoLiteral(const std::string arg);
bool isCharLiteral(const std::string& arg);
bool isIntLiteral(const std::string& arg);
bool isFloatLiteral(const std::string& arg);
bool isDoubleLiteral(const std::string& arg);


#endif
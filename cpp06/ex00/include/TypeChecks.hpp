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
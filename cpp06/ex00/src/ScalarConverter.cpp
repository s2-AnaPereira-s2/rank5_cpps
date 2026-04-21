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

void ScalarConverter::convert(const std::string& literal)
{

}

/*
    Acceptable inputs:
        char literal: in this subject is basically one printable non-digit character (example: a).
        int: optional sign + digits.
        float: decimal with trailing f (example: 42.0f, -4.2f) + pseudo literals nanf, +inff, -inff.
        double: decimal without trailing f (example: 42.0, -4.2) + pseudo literals nan, +inf, -inf.
*/


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include "TypeChecks.hpp"


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string& literal);

};


#endif
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

    std::cout << "char: " << std::endl;
    std::cout << "int: " << std::endl;
    std::cout << "float: " <<  << std::endl;
    std::cout << "double: " <<  << std::endl;
    return;
}

static void floatLit_convert(const std::string& literal)
{
    std::cout << "char: " << std::endl;
    std::cout << "int: " << std::endl;
    std::cout << "float: " <<  << std::endl;
    std::cout << "double: " <<  << std::endl;
    return;
}

static void doubleLit_convert(const std::string& literal)
{
    std::cout << "char: " << std::endl;
    std::cout << "int: " << std::endl;
    std::cout << "float: " <<  << std::endl;
    std::cout << "double: " <<  << std::endl;
    return;
}

void ScalarConverter::convert(const std::string& literal)
{
    const bool charLit = isCharLiteral(literal);
    const bool intLit = isIntLiteral(literal);
    const bool floatLit = isFloatLiteral(literal);
    const bool doubleLit = isDoubleLiteral(literal);
    const std::string pseudoLit = isPseudoLiteral(literal);

    if (pseudoLit != "none")
    {
        pseudoLit_convert(pseudoLit, literal);
        return;
    }
    if (charLit)
    {
        charLit_convert(literal);
        return;
    }
    if (intLit)
    {
        intLit_convert(literal);
        return;
    }
    if (floatLit)
    {
        floatLit_convert(literal);
        return;
    }
    if (doubleLit)
    {
        doubleLit_convert(literal);
        return;
    }
}

/*
    Acceptable inputs:
        char literal: in this subject is basically one printable non-digit character (example: a).
        int: optional sign + digits.
        float: decimal with trailing f (example: 42.0f, -4.2f) + pseudo literals nanf, +inff, -inff.
        double: decimal without trailing f (example: 42.0, -4.2) + pseudo literals nan, +inf, -inf.
*/


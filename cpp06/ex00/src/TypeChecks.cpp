#include "ScalarConverter.hpp"
#include <cctype>

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
    bool dot = false;

    if (arg == "nanf" || arg == "+inff" || arg == "-inff")
        return true;
    if (arg.length() < 2 || arg[arg.length() - 1] != 'f')
        return false;

    if (arg[0] == '+' || arg[0] == '-')
        i = 1;

    for (; i < arg.length() - 1; ++i)
    {
        if (arg[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(arg[i])))
            return false;
    }
    return dot;
}

bool isDoubleLiteral(const std::string& arg)
{
    size_t i = 0;
    bool dotSeen = false;

    if (arg == "nan" || arg == "+inf" || arg == "-inf")
        return true;
    if (arg.empty())
        return false;

    if (arg[0] == '+' || arg[0] == '-')
        i = 1;

    for (; i < arg.length(); ++i)
    {
        if (arg[i] == '.')
        {
            if (dotSeen)
                return false;
            dotSeen = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(arg[i])))
            return false;
    }
    return dotSeen;
}



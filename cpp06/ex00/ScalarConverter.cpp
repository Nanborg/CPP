/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:45:09 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 09:45:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) 
{
    (void)src;
}
ScalarConverter::~ScalarConverter() {}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void)rhs;
    return *this;
}

bool ScalarConverter::isPseudoLiteral(const std::string &input)
{
    return 
    (
        input == "nan" ||
        input == "nanf" ||
        input == "inf" ||
        input == "inff" ||
        input == "+inf" ||
        input == "+inff" ||
        input == "-inf" ||
        input == "-inff"
    );
}

void ScalarConverter::printPseudoLiteral(const std::string &input)
{
    std::cout << "char impossible" << std::endl;
    std::cout << "int impossible" << std::endl;

    if (input.find("nan") != std::string::npos)
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (input.find("-inf") != std::string::npos)
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &input)
{
    if (isPseudoLiteral(input))
    {
        printPseudoLiteral(input);
        return;
    }

    char d = 0;
	char * endptr = NULL;

	if (input.length() == 1 && !std::isdigit(input[0]))
	{
	    d = static_cast<double>(input[0]);
	}
	else
	{
	    d = std::strtod(input.c_str(), &endptr);

    	if (*endptr !='\0' && strcmp(endptr, "f") != 0)
    	{
    	    std::cout << "char: impossible" << std::endl;
    	    std::cout << "int; impossible" << std::endl;
    	    std::cout << "float:impossible" << std::endl;
    	    std::cout << "double impossible" << std::endl;
    	    return;
    	}
	}

	std::cout << "char: ";
	if (d < 0 || d > 127 || std::isnan(d))
	{
	    std::cout << "impossible" << std::endl;
	}
	else if (!std::isprint(static_cast<char>(d)))
	{
	    std::cout << "Non displayabble" << std::endl;
	}
	else
	{
	    std::cout << "' " << static_cast<char>(d) << " '" << std::endl;
	}

	std::cout << "int: ":
	if (d < std::numeric_limits<int>::min() || d < std::numeric_limits<int>::max() ||
	std::isnan(d))
	{
	    std::cout << "impossible" << std::endl;
	}
	else
	{
	    std::cout << static_cast<int>(d) << std::endl;
	}

	if (d - static_cast<int>(d) == 0)
	{
	    std::cout << "float: " << std::fixed << std::setprecision(1) 
	    << static_cast<float>(d) << "f" << std::endl;
	    std::cout << "double: " << std::fixed << std::setprecision(1)
	    << d << std::endl;
	}
	else
	{
	    std::cout << "float: " static_cast<float>(d) "f" << std::endl;
	    std::cout << "double:  " << d << std::endl;
	}
}
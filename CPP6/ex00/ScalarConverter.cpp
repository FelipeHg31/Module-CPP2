/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:48:44 by juan-her          #+#    #+#             */
/*   Updated: 2026/08/02 16:06:51 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

static bool is_literal(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: imposible\nint: imposible\nfloat: nanf\ndouble: nan" << std::endl;
		return (true);
	}
	else if (literal == "-inff" || literal == "-inf")
	{
		std::cout << "char: imposible\nint: imposible\nfloat: -inff\ndouble: -inf" << std::endl;
		return (true);
	}
	else if (literal == "+inff" || literal == "+inf")
	{
		std::cout << "char: imposible\nint: imposible\nfloat: +inff\ndouble: +inf" << std::endl;
		return (true);
	}
	else if (literal == "inff" || literal == "inf")
	{
		std::cout << "char: imposible\nint: imposible\nfloat: inff\ndouble: inf" << std::endl;
		return (true);
	}
	return (false);
}

static bool is_valid(const std::string& literal, double* d)
{
	char* end;
	double value;

	value = std::strtod(literal.c_str(), &end);
	if (*end && *end != 'f')
	{
		std::cout << "char: imposible\nint: imposible\nfloat: nanf\ndouble: nan" << std::endl;
		return (false);
	}
	*d = value;
	return (true);
}

static bool is_nan(double value)
{
	return (value != value);
}

static bool is_inf(double value)
{
	return (value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity());
}

static void print_char(double value)
{
	std::cout << "char: ";
	if (is_nan(value) || is_inf(value))
		std::cout << "imposible" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "imposible" << std::endl;
	else if (value < 32 || value == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void print_int(double value)
{
	std::cout << "int: ";
	if (is_nan(value) || is_inf(value))
		std::cout << "imposible" << std::endl;
	else if (value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "imposible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void print_float(double value)
{
	std::cout << "float: ";
	if (is_nan(value))
		std::cout << "nanf" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inff" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inff" << std::endl;
	else
	{
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	}
}

static void print_double(double value)
{
	std::cout << "double: ";
	if (is_nan(value))
		std::cout << "nan" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inf" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(2) << value << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	double	value;

	if (is_literal(literal))
		return ;
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else if (!is_valid(literal, &value))
		return ;
	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}

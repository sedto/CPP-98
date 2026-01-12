/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibsejra <dibsejra@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:30:05 by dibsejra          #+#    #+#             */
/*   Updated: 2026/01/12 12:30:06 by dibsejra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;

	if (i >= literal.length())
		return false;

	for (; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return false;

	std::string withoutF = literal.substr(0, literal.length() - 1);
	size_t dotCount = 0;
	size_t i = 0;

	if (withoutF[0] == '+' || withoutF[0] == '-')
		i++;

	for (; i < withoutF.length(); i++)
	{
		if (withoutF[i] == '.')
			dotCount++;
		else if (!isdigit(withoutF[i]))
			return false;
	}
	return (dotCount == 1);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t dotCount = 0;
	size_t i = 0;

	if (literal[0] == '+' || literal[0] == '-')
		i++;

	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
			dotCount++;
		else if (!isdigit(literal[i]))
			return false;
	}
	return (dotCount == 1);
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	return (literal == "nan" || literal == "nanf" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff");
}

void ScalarConverter::convertFromChar(const std::string& literal)
{
	char c = literal[1];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& literal)
{
	long l = std::atol(literal.c_str());

	if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	int i = static_cast<int>(l);

	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& literal)
{
	float f = std::atof(literal.c_str());

	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (f < 32 || f >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f);
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& literal)
{
	double d = std::atof(literal.c_str());

	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (d < 32 || d >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d);
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertPseudoLiteral(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nanf" || literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inff" || literal == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inff" || literal == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isPseudoLiteral(literal))
		convertPseudoLiteral(literal);
	else if (isChar(literal))
		convertFromChar(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
		std::cout << "Error: Invalid literal" << std::endl;
}

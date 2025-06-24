/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:10:28 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/22 08:22:28 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::~ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &ScalarConverter)
{
	if (this == &ScalarConverter)
	{
		std::cerr << "Error: self-copy attempted during construction" << std::endl;
		return;
	}
	*this = ScalarConverter;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ScalarConverter)
{
	if (this == &ScalarConverter)
		return (*this);
	return (*this);
}

void ScalarConverter::convert(std::string number)
{
	char *end;
	errno = 0;
	int neg = 1;

	if (number == "inff" || number == "+inff" || number == "-inff" || number == "nanf" || number == "+nanf" || number == "-nanf")
	{
		if (number.front() == '+')
			number = number.substr(1);
		std::cout << RED << "char: impossible" << RESET << std::endl;
		std::cout << RED << "int: impossible" << RESET << std::endl;
		std::cout << "float: " << number << std::endl;
		std::cout << "double: " << number.substr(0, number.size() - neg) << std::endl;
		return;
	}

	if (number.back() == 'f' && number.find('.') != std::string::npos && number != "inf" && number != "-inf" && number != "+inf")
		number.pop_back();
	
	// Convert to char
	long charVal = std::strtol(number.c_str(), &end, 10);
	if (*end == '\0' && charVal >= std::numeric_limits<char>::min() && charVal <= std::numeric_limits<char>::max())
	{
		char c = static_cast<char>(charVal);
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << ORANGE << "char: Non displayable" << RESET << std::endl;
	}
	else if (number.length() == 1 && std::isprint(number[0]))
		std::cout << "char: '" << number[0] << "'" << std::endl;
	else
	{
		float floatVal = std::strtof(number.c_str(), &end);
		if (*end == '\0' && errno == 0)
		{
			charVal = static_cast<long>(floatVal);
			if (charVal >= std::numeric_limits<char>::min() && charVal <= std::numeric_limits<char>::max())
			{
				char c = static_cast<char>(charVal);
				if (std::isprint(c))
					std::cout << "char: '" << c << "'" << std::endl;
				else
					std::cout << ORANGE << "char: Non displayable" << RESET << std::endl;
			}
			else
				std::cout << RED << "char: impossible" << RESET << std::endl;
		}
		else
			std::cout << RED << "char: impossible" << RESET << std::endl;
	}

	// Convert to int
	long intVal = std::strtol(number.c_str(), &end, 10);
	if (*end != '\0')
	{
		float floatVal = std::strtof(number.c_str(), &end);
		if (*end == '\0' && errno == 0)
		{
			intVal = static_cast<long>(floatVal);
			if (intVal >= std::numeric_limits<int>::min() && intVal <= std::numeric_limits<int>::max())
				std::cout << "int: " << static_cast<int>(intVal) << std::endl;
			else
				std::cout << RED << "int: impossible" << RESET << std::endl;
		}
		else
			std::cout << RED << "int: impossible" << RESET << std::endl;
	}
	else
	{
		if (errno == 0 && intVal >= std::numeric_limits<int>::min() && intVal <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(intVal) << std::endl;
		else
			std::cout << RED << "int: impossible" << RESET << std::endl;
	}

	// Convert to float
	errno = 0;
	float floatVal = std::strtof(number.c_str(), &end);
	if (*end == '\0' && errno == 0)
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
	else
		std::cout << RED << "float: impossible" << RESET << std::endl;

	// Convert to double
	errno = 0;
	double doubleVal = std::strtod(number.c_str(), &end);
	if (*end == '\0' && errno == 0)
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
	else
		std::cout << RED << "double: impossible" << RESET << std::endl;
}

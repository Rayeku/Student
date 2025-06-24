/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:27:16 by rayeku            #+#    #+#             */
/*   Updated: 2024/09/29 03:19:07 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

// Include(s)
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>

class ScalarConverter
{
private:
	// Constructor(s)
	ScalarConverter();
	ScalarConverter(const ScalarConverter &ScalarConverter);

	// Deconstructor(s)
	~ScalarConverter();
	
	// Copy assignation overload
	ScalarConverter &operator=(const ScalarConverter &ScalarConverter);

public:
	// Method(s)
	static void convert(std::string number);
};

#endif
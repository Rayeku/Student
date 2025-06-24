/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:27:16 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/29 17:44:23 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

// Include(s)
#include <iostream>
#include <string>
#include <cstdint>
#include <ctime>
#include <set>

class Base
{
	
public:
	// Deconstructor(s)
	virtual ~Base();

	// Method(s)
	static Base *generate(void);
	static void identify(Base *p);
	static void identify(Base &p);
};

#endif
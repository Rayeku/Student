/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:27:16 by rayeku            #+#    #+#             */
/*   Updated: 2024/09/29 03:19:07 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

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

typedef struct s_data
{
	std::string name;
	int abougrai;
	char deadWood;
	double test;

} Data;

class Serializer
{
private:
	// Constructor(s)
	Serializer();
	Serializer(const Serializer &Serializer);

	// Deconstructor(s)
	~Serializer();

	// Copy assignation overload
	Serializer &operator=(const Serializer &Serializer);

public:
	// Method(s)
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
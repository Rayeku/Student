/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:10:28 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/21 08:35:34 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}
Serializer::~Serializer()
{
}
Serializer::Serializer(const Serializer &Serializer)
{
	if (this == &Serializer)
	{
		std::cerr << "Error: self-copy attempted during construction" << std::endl;
		return;
	}
	std::cout << "Serializer Copy constructor called" << std::endl;
	*this = Serializer;
}

Serializer &Serializer::operator=(const Serializer &Serializer)
{
	if (this == &Serializer)
		return (*this);
	return (*this);
}
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
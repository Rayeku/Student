/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:54:23 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/21 10:34:23 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongAnimal Type";
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string name)
{
	std::cout << "WrongAnimal Name constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = WrongAnimal;
};
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	this->_type = WrongAnimal._type;
	return (*this);
};

void WrongAnimal::makeSound() const
{
	std::cout << ITALIC << BROWN;
	std::cout << "~ WrongAnimal sound ~" << RESET << std::endl;
}
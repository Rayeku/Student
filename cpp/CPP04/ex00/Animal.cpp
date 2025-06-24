/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:33 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/21 10:33:38 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Random")
{
	std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(std::string name) : _type(name)
{
	std::cout << "Animal Name constructor called" << std::endl;
}

Animal::Animal(const Animal &Animal)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = Animal;
};
Animal::~Animal()
{
	std::cout << "Animal Deconstructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &Animal)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	this->_type = Animal._type;
	return (*this);
};

void Animal::makeSound() const
{
	std::cout << ITALIC << GREEN;
	std::cout << "~ brouhaha ~" << RESET << std::endl;
}

std::string Animal::getType() const
{
	std::cout << ORANGE;
	return (BOLD + this->_type + RESET);
}

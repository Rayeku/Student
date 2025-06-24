/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:26 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/21 10:34:54 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog Type";
	std::cout << "Dog Default constructor called" << std::endl;
}
Dog::Dog(std::string name)
{
	std::cout << "Dog Name constructor called" << std::endl;
}
Dog::Dog(const Dog &Dog)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = Dog;
};
Dog::~Dog()
{
	std::cout << "Dog Deconstructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &Dog)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	this->_type = Dog._type;
	return (*this);
};

void Dog::makeSound() const
{
	std::cout << ITALIC << RED;
	std::cout << "~ Woof Woof ~" << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:14:34 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/21 10:34:02 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() 
{
	this->_type = "Cat Type";
	std::cout << "Cat Default constructor called" << std::endl;
}
Cat::Cat(std::string name) 
{
	std::cout << "Cat Name constructor called" << std::endl;
}
Cat::Cat(const Cat &Cat)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = Cat;
};
Cat::~Cat()
{
	std::cout << "Cat Deconstructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &Cat)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	this->_type = Cat._type;
	return (*this);
};

void Cat::makeSound() const
{
	std::cout << ITALIC << BLUE;
	std::cout << "~ Meow Meow ~" <<  RESET << std::endl;
}

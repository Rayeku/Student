/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:14:34 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/24 00:23:08 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_type = "Cat Type";
	_brain = new Brain();
	if (!_brain)
		std::cerr << "Brain default constuctor Failed" << std::endl;
}
Cat::Cat(std::string name)
{
	std::cout << "Cat Name constructor called" << std::endl;
	_brain = new Brain();
	if (!_brain)
		std::cerr << "Brain default constuctor Failed" << std::endl;
}
Cat::Cat(const Cat &Cat)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	if (this == &Cat)
	{
		std::cerr << "Error: self-copy attempted during construction" << std::endl;
		this->_brain = nullptr;
	}
	else
		*this = Cat;
};
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Deconstructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &Cat)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &Cat)
		return (*this);
	this->_type = Cat._type;
	if (!Cat._brain)
		std::cout << "Brain copy assignment impossible" << std::endl;
	else
	{
		this->_brain = new Brain();
		if (!this->_brain)
			std::cout << "Brain default constructor failed" << std::endl;
		else
			this->_brain->copyIdeas(*(Cat._brain));
	}
	return (*this);
};

void Cat::makeSound() const
{
	std::cout << ITALIC << BLUE;
	std::cout << "~ Meow Meow ~" << RESET << std::endl;
}

void Cat::printBrain() const
{
	this->_brain->printIdeas();
}

void Cat::changeBrain(std::string newIdea) const
{
	this->_brain->changeIdeas(newIdea);
}

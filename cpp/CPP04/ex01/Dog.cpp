/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:26 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/24 00:24:23 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog Type";
	_brain = new Brain();
	if (!_brain)
		std::cerr << "Brain default constuctor Failed" << std::endl;
}
Dog::Dog(std::string name)
{
	std::cout << "Dog Name constructor called" << std::endl;
	_brain = new Brain();
	if (!_brain)
		std::cerr << "Brain default constuctor Failed" << std::endl;
}
Dog::Dog(const Dog &Dog)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	if (this == &Dog)
	{
		std::cerr << "Error: self-copy attempted during construction" << std::endl;
		this->_brain = nullptr;
	}
	else
		*this = Dog;
};
Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Deconstructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &Dog)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this == &Dog)
		return (*this);
	this->_type = Dog._type;
	if (!Dog._brain)
		std::cout << "Brain copy assignment impossible" << std::endl;
	else
	{
		this->_brain = new Brain();
		if (!this->_brain)
			std::cout << "Brain default constructor failed" << std::endl;
		else
			this->_brain->copyIdeas(*(Dog._brain));
	}
	return (*this);
};

void Dog::makeSound() const
{
	std::cout << ITALIC << RED;
	std::cout << "~ Woof Woof ~" << RESET << std::endl;
}

void Dog::printBrain() const
{
	this->_brain->printIdeas();
}

void Dog::changeBrain(std::string newIdea) const
{
	this->_brain->changeIdeas(newIdea);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:49:16 by rayeku            #+#    #+#             */
/*   Updated: 2024/09/24 00:03:46 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

# define SLEEPING "... Sleeping ..."
# define EATING "... Eating ..."

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			_ideas[i] = SLEEPING;
		else
			_ideas[i] = EATING;
	}
}
Brain::Brain(const Brain &Brain)
{
	if (this == &Brain)
	{
		std::cerr << "Error: self-copy attempted during construction" << std::endl;
		return;
	}
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = Brain;
}
Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}
Brain &Brain::operator=(const Brain &Brain)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &Brain)
		return (*this);
	for (int i = 0; i < 100; i++)
			this->_ideas[i] = Brain._ideas[i];
	return (*this);
};

void Brain::copyIdeas(Brain &Brain)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = Brain._ideas[i];
}

void Brain::printIdeas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->_ideas[i] << std::endl;
}

void Brain::changeIdeas(std::string newIdea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = newIdea;
}
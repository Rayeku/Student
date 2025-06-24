/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:57:52 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/21 10:34:38 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat Type";
	std::cout << "WrongCat Default constructor called" << std::endl;
}
WrongCat::WrongCat(std::string name)
{
	std::cout << "WrongCat Name constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &WrongCat)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = WrongCat;
};
WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	this->_type = WrongCat._type;
	return (*this);
};

void WrongCat::makeSound() const
{
	std::cout << ITALIC << BROWN;
	std::cout << "~ WrongCat sound ~" << RESET << std::endl;
}
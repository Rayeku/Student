/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:34 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:22:15 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
};

Weapon::Weapon(std::string type) : _type("Default")
{
	this->_type = type;
};

Weapon::~Weapon(void)
{
	return ;
};

void Weapon::setType(std::string newType)
{
	this->_type = newType;

	return ;
};

const std::string Weapon::getType()
{
	std::string &typeRef = _type;
	
	return (typeRef);
};

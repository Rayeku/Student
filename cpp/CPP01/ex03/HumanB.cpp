/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:26:26 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:21:45 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) : _name("HumanB")
{
	return ;
};

HumanB::HumanB(std::string name, Weapon &weapon) : _name("HumanB")
{
	this->_name = name;
	this->_weapon = &weapon;

	return ;
};

HumanB::HumanB(std::string name) : _name("HumanB")
{
	this->_name = name;

	return ;
};

HumanB::~HumanB(void)
{
	return ;
};

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;

	return ;
};
void HumanB::attack(void)
{
	std::cout << ORANGE_DARK << _name << ATTACK << RED BOLD  << _weapon->getType() << RESET << std::endl;

	return ;
};

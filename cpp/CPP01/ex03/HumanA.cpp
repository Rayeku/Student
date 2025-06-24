/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:25:55 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:21:05 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name("HumanA"), _weapon(weapon)
{
	this->_name = name;
	this->_weapon = weapon;

	return ;
};

HumanA::~HumanA(void)
{
	return ;
};

void HumanA::attack(void)
{
	std::cout << ORANGE_DARK << _name << ATTACK << RED BOLD << _weapon.getType() << RESET << std::endl;

	return ;
};

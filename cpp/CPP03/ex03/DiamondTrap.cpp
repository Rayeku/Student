/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:54:37 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:23:53 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = "Default";
	ClapTrap::_name = "Default_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_baseLife = 100;
	return ;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name += "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_baseLife = 100;
	return ;
}
DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = DiamondTrap;
	return ;
};
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
	return ;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name  = DiamondTrap._name;
	this->_hitPoints  = DiamondTrap._hitPoints;
	this->_energyPoints  = DiamondTrap._energyPoints;
	this->_attackDamage  = DiamondTrap._attackDamage;
	this->_baseLife = DiamondTrap._baseLife;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	if (this->isDead(this->_hitPoints) || !this->hasEnergy(this->_energyPoints))
		return ;
	std::cout << SCAVTRAP << ORANGE << ClapTrap::_name << RESET;
	std::cout << ATTACKS << BLUE << target << RESET;
	std::cout << " causing " << RED << this->_attackDamage << RESET;
	std::cout << DAMAGE << std::endl;
	this->_energyPoints--;
}
void DiamondTrap::whoAmI()
{
	if (this->isDead(this->_hitPoints)) 
		return;
		
	std::cout << DIAMONDTRAP << ORANGE << this->_name << RESET;
	std::cout << " and ";
	std::cout << ORANGE << ClapTrap::_name << RESET;
	std::cout << " is who i am." << std::endl;
}



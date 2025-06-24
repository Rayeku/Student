/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:54:40 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:21:25 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_baseLife = 100;
	
	return;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_baseLife = 100;
	
	return;
}
ScavTrap::ScavTrap(const ScavTrap &ScavTrap)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = ScavTrap;
	return ;
};
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name  = ScavTrap._name;
	this->_hitPoints  = ScavTrap._hitPoints;
	this->_energyPoints  = ScavTrap._energyPoints;
	this->_attackDamage  = ScavTrap._attackDamage;
	this->_baseLife = ScavTrap._baseLife;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->isDead(this->_hitPoints) || !this->hasEnergy(this->_energyPoints)) 
		return;
	std::cout << SCAVTRAP << ORANGE << this->_name << RESET;
	std::cout << ATTACKS << BLUE << target << RESET;
	std::cout << " causing " << RED << this->_attackDamage << RESET;
	std::cout << DAMAGE << std::endl;
	this->_energyPoints--;
}
void	ScavTrap::guardGate(void)
{
	if (this->isDead(this->_hitPoints)) 
		return;
	std::cout << SCAVTRAP << ORANGE << this->_name << RESET;
	std::cout << " is now on" << RED << " Gate keeper mode" << RESET << ".\n";
}
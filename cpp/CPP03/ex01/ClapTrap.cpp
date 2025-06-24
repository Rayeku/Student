/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:25:08 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 18:38:15 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->_baseLife = _hitPoints;
	this->_name = "Default";
	return ;
}
ClapTrap::ClapTrap(std::string name) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
	this->_name = name;
	this->_baseLife = _hitPoints;
	if (this->_name.empty())
		this->_name = "No name";
	return ;
}
ClapTrap::ClapTrap(const ClapTrap &ClapTrap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = ClapTrap;
	return ;
};
ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_name = ClapTrap._name;
	this->_hitPoints = ClapTrap._hitPoints;
	this->_energyPoints = ClapTrap._energyPoints;
	this->_attackDamage = ClapTrap._attackDamage;
	this->_baseLife = ClapTrap._baseLife;
	return (*this);
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}
void ClapTrap::attack(const std::string &target)
{
	if (this->isDead(this->_hitPoints) || !this->hasEnergy(this->_energyPoints)) 
		return;
	std::cout << CLAPTRAP << ORANGE << this->_name << RESET;
	std::cout << ATTACKS << BLUE << target << RESET;
	std::cout << " causing " << RED << this->_attackDamage << RESET;
	std::cout << DAMAGE << std::endl;
	this->_energyPoints--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->isDead(this->_hitPoints)) 
		return;
	std::cout << CLAPTRAP << ORANGE << this->_name << RESET;
	std::cout << TAKES << RED << amount << RESET;
	std::cout << HEALTH << std::endl;
	if (amount > INTMAX)
		amount = INTMAX;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << CLAPTRAP << ORANGE << this->_name << RESET;
		std::cout << DIED << std::endl;
	}
	return ;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isDead(this->_hitPoints) || !this->hasEnergy(this->_energyPoints)) 
		return;
	std::cout << CLAPTRAP << ORANGE << this->_name << RESET;
	std::cout << REPAIR << GREEN << amount << RESET;
	std::cout << HEALTH << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
	if (this->_hitPoints > _baseLife)
		this->_hitPoints = _baseLife;
	return ;
}
bool ClapTrap::isDead(int health)
{
	if (health <= 0)
	{
		std::cout << CLAPTRAP << ORANGE << this->_name << RESET;
		std::cout << DEAD << std::endl;	
		return (true);
	}
	return (false);
}
bool ClapTrap::hasEnergy(int energy)
{
	if (energy < 1)
	{
		std::cout << CLAPTRAP << ORANGE << this->_name << RESET;
		std::cout << ENERGY << std::endl;
		return (false);
	}
	return (true);
}

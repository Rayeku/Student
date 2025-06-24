/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:45:53 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:22:45 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_baseLife = 100;
	return ;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_baseLife = 100;
	return ;
}
FragTrap::FragTrap(const FragTrap &FragTrap)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = FragTrap;
	return ;
};
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return ;
}
FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = FragTrap._name;
	this->_hitPoints = FragTrap._hitPoints;
	this->_energyPoints = FragTrap._energyPoints;
	this->_attackDamage = FragTrap._attackDamage;
	this->_baseLife = FragTrap._baseLife;
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (this->isDead(this->_hitPoints) || !this->hasEnergy(this->_energyPoints))
		return ;
	std::cout << FRAGTRAP << ORANGE << this->_name << RESET;
	std::cout << ATTACKS << BLUE << target << RESET;
	std::cout << " causing " << RED << this->_attackDamage << RESET;
	std::cout << DAMAGE << std::endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->isDead(this->_hitPoints)) 
		return;
	std::cout << FRAGTRAP << ORANGE << this->_name << RESET;
	std::cout << GREEN << " High five" << RESET << " bros ?!" << std::endl;
}
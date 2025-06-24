/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:13:42 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/16 13:43:17 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define RED "\033[31m"
# define CYAN "\033[36m"
# define BLUE "\033[34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define ITALIC "\033[3m"
# define ORANGE "\033[33m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define BLUE_DARK "\033[34m"
# define ORANGE_DARK "\033[38;5;202m"
# define MAGENTA_LIGHT "\033[38;5;205m"

# define CLAPTRAP "ClapTrap " RESET
# define ATTACKS " attacks " RESET
# define REPAIR " repairs itself, gaining " RESET
# define DAMAGE " points of damage!" RESET
# define TAKES " takes damage, losing " RESET
# define ENERGY " has not enough energy points to deal damage." RESET
# define HEALTH " health points!" RESET

# define DEAD " is unfortunately dead and can't do anything." RESET
# define DIED " is dead." RESET

# define INTMAX 2147483647

class ClapTrap
{
  protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	int _baseLife;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &ClapTrap);
	ClapTrap(const ClapTrap &ClapTrap);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	bool isDead(int health);
	bool hasEnergy(int energy);
};

#endif
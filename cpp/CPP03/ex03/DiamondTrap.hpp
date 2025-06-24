/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:48:48 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:22:26 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define DIAMONDTRAP "DiamondTrap " RESET

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
  private:
	std::string _name;

  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &DiamondTrap);
	DiamondTrap(const DiamondTrap &DiamondTrap);

	void attack(const std::string &target);
	void whoAmI();
};

#endif
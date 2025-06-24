/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:53:04 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:21:54 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

# define SCAVTRAP "ScavTrap " RESET

class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &ScavTrap);
	ScavTrap(const ScavTrap &ScavTrap);
	
	void attack(const std::string &target);
	void guardGate();
};
#endif
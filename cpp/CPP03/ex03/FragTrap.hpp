/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:45:40 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:22:04 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

# define FRAGTRAP "FragTrap " RESET

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap &operator=(const FragTrap &FragTrap);
	FragTrap(const FragTrap &FragTrap);

	void attack(const std::string &target);
	void highFivesGuys(void);
};

#endif
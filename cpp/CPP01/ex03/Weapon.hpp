/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:40:32 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:22:00 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

# define RED "\033[31m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define YELLOW "\033[33m"
# define ORANGE_DARK "\033[38;5;202m"

# define ATTACK YELLOW BOLD " attacks with their " RESET

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	void setType(std::string newType);
	const std::string getType();
};

#endif
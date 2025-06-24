/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:24:48 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:20:12 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
  private:
	std::string _name;
	Weapon *_weapon;

  public:
	HumanB();
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack();
};
#endif

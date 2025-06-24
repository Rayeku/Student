/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:24:43 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:19:49 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
  private:
	std::string _name;
	Weapon &_weapon;

  public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};
#endif

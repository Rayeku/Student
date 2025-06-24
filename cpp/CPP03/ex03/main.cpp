/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:32:08 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:32:11 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(int ac, char **av)
{
	DiamondTrap Thenwood("DeadWood");

	Thenwood.attack("el Sugar");
	Thenwood.takeDamage(50);
	Thenwood.beRepaired(50);
	Thenwood.highFivesGuys();
	Thenwood.guardGate();
	Thenwood.whoAmI();
	Thenwood.takeDamage(100);
	Thenwood.whoAmI();

	return (0);
}
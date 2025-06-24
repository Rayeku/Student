/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:31:38 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:31:39 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(int ac, char **av)
{
	FragTrap Thenwood("DeadWood");

	Thenwood.attack("el Sugar");
	Thenwood.takeDamage(50);
	Thenwood.beRepaired(50);
	Thenwood.highFivesGuys();
	Thenwood.takeDamage(100);
	Thenwood.highFivesGuys();
	Thenwood.beRepaired(100);

	return (0);
}
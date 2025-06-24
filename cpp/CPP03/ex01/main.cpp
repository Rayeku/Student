/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:31:08 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:31:09 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(int ac, char **av)
{
	ScavTrap Abougrai("DeaDwood");
	
	Abougrai.attack("Lilith");
	Abougrai.takeDamage(90);
	Abougrai.beRepaired(10);
	Abougrai.guardGate();
	Abougrai.takeDamage(90);
	Abougrai.guardGate();
	return (0);
}
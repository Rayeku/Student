/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:13:49 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/17 19:27:15 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(int ac, char **av)
{
	/* ClapTrap A;
	ClapTrap B("Zer0");
	ClapTrap C("Lilith");
	ClapTrap D("Double Anarchy"); */
	ClapTrap Abougrai("Shanoa");

	Abougrai.attack("Random");
	Abougrai.takeDamage(8);
	Abougrai.beRepaired(10);
	Abougrai.takeDamage(10);
	return (0);
}
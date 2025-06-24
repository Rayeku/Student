/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:09:11 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/09 15:04:26 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Z1;
	Zombie	*Z2;


	Z1 = newZombie("Travis");
	Z2 = newZombie("Scottie");
	Z1->announce();
	Z2->announce();
	randomChump("Tess");
	randomChump("Henry");

	delete	Z1;
	delete	Z2;

	return (0);
}

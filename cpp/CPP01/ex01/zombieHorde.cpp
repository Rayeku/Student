/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:36:48 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 12:28:27 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	if (N > 500000)
		(std::cout << "Too Many Zombie, calma calma" << std::endl, exit(1));
	if (N > 0)
		horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (N > 0 ? horde : NULL);
}

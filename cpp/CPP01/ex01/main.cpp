/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:09:11 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 12:28:46 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string name = "Lenny";
	int		N = name.length();
	Zombie	*Jhonny = zombieHorde(N , name);

	for (int i = 0; i < N; i++)
	{
		std::cout << RED << "Zombie N°"  << i + 1 << " " RESET;
		Jhonny->announce();
	}
	delete[] Jhonny;
	return (0);
}

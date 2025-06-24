/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:24 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/24 13:44:44 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* int main(void)
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete i;

	delete j; // should not create a leak
	return (0);
} */
/* int	main(void)
{
	const Animal	*j[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			j[i] = new Cat();
		else
			j[i] = new Dog();
	}
	for (int i = 0; i < 6; i++)
		delete j[i];
	return (0);
} */
/* int main(void)
{
	Dog test;
	test.changeBrain("test");
	Dog tmp = test;
	tmp.printBrain();
	test.changeBrain("1");
	test.printBrain();
} */
int main(void)
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();


	delete i;
	delete j; // should not create a leak
	return (0);
}

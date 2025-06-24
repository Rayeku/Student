/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:24 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/24 02:50:57 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

int main()
{
	// Animal capart;
	// Animal capart("test");
	Animal *cat = new Cat();
	Animal *dog = new Dog();

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;

	return (0);
}
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

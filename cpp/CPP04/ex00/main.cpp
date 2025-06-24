/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:24 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/21 10:37:29 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

int main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
	// const Animal *l = new WrongAnimal();
	// const Animal *k = new WrongCat();
	// std::cout << l->getType() << " " << std::endl;
	// std::cout << k->getType() << " " << std::endl;
	// k->makeSound();
	// l->makeSound();
	// delete l;
	// delete k;
	return (0);
}



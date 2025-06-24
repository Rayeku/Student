/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:19:19 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/21 10:09:02 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data Capart;
	Data *Copy;
	uintptr_t test;
	
	Capart.name = "Data";
	Capart.abougrai = 100;
	Capart.deadWood = 'D';
	Capart.test = 4.4;

	std::cout << ORANGE << "string name : " << RESET << Capart.name << std::endl;
	std::cout << BROWN << "char deadWood: " << RESET << Capart.deadWood <<std::endl;
	std::cout << CYAN << "int abougrai: " << RESET << Capart.abougrai << std::endl;
	std::cout << MAGENTA << "double test: " << RESET << Capart.test << std::endl << std::endl; 
	
	test = Serializer::serialize(&Capart);
	Copy = Serializer::deserialize(test);
	
	std::cout << ORANGE << "string name : " << RESET << Copy->name << std::endl;
	std::cout << BROWN << "char deadWood: " << RESET << Copy->deadWood <<std::endl;
	std::cout << CYAN << "int abougrai: " << RESET << Copy->abougrai << std::endl;
	std::cout << MAGENTA << "double test: " << RESET << Copy->test << std::endl << std::endl; 
	
	Copy->name = "ABC";
	Copy->abougrai =  0;
	Copy->deadWood = 'A';
	Copy->test = 9.9;

	std::cout << ORANGE << "string name : " << RESET << Copy->name << std::endl;
	std::cout << BROWN << "char deadWood: " << RESET << Copy->deadWood <<std::endl;
	std::cout << CYAN << "int abougrai: " << RESET << Copy->abougrai << std::endl;
	std::cout << MAGENTA << "double test: " << RESET << Copy->test << std::endl << std::endl; 

	return (0);
}

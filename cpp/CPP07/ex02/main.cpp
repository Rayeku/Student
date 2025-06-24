/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:19:19 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/29 13:55:54 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	try
	{
		Array<int> array1(5);
		for (unsigned int i = 0; i < 5; i++)
			array1[i] = 42;
		std::cout << "Size of array1: " << BROWN << array1.size() << RESET << std::endl;
		// array1.printElem(); // prints all elems
		// std::cout << array1[100] << std::endl; // exeception

		// Array<std::string> array3(4);
		// array3[0] = "Sky";
		// array3[1] = "Is";
		// array3[2] = "The";
		// array3[3] = "Limit";
		// std::cout << array3[0] << std::endl;
		// std::cout << array3[1] << std::endl;
		// std::cout << array3[2] << std::endl;
		// std::cout << array3[3] << std::endl;
		// std::cout << array3[4] << std::endl; // exeception

		// const Array<std::string> array2(3);
		// std::cout << array2[0] << std::endl;
		// std::cout << array2[1] << std::endl;
		// std::cout << array2[2] << std::endl;
		// std::cout << array2[3] << std::endl; // exeception
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl; 
	}
	return (0);
}

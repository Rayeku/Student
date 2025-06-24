/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:19:19 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/23 07:09:03 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(int &x)
{
	std::cout << ORANGE << x << RESET << std::endl;
}
void printString(std::string &x)
{
	std::cout << BROWN << x << RESET << std::endl;
}

int main()
{
	int test[] = {0, 1, 2, 3, 4};
	::iter(test, 5, printInt);
	
	int test2[] = {42, 42, 42, 42, 42};
	::iter(test2, 5, printInt);

	std::string string[] = {"abougrai", "thenwood", "DeadWood", "gchenot", "legrandloup"};
	::iter(string, 5, printString);

	double capart[] = {2.1, 4.2, 4.0, 0.2};
	::iter(capart, 4, printElem);
	
	return 0;
}

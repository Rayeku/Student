/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:31:32 by abougrai          #+#    #+#             */
/*   Updated: 2024/11/26 11:07:27 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		// Bureaucrat Low("Low", 151);
		// Bureaucrat High("High", 0);
		Bureaucrat A;
		std::cout << A;
		Bureaucrat C("Deadge", 1);
		std::cout << C;
		for (int i = 0; i < 99; i++)
			C.decrementeGrade();
		std::cout << C;
		for (int i = 0; i < 50; i++)
			C.incrementGrade();
		std::cout << C;
		// for (int i = 0; i < 52; i++)
		// 	C.incrementGrade();
		// for (int i = 0; i < 1000; i++)
		// 	C.decrementeGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}


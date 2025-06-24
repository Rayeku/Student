/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:31:32 by abougrai          #+#    #+#             */
/*   Updated: 2024/11/28 10:04:02 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat A("Abougrai", 1);
		Bureaucrat B("DeadWood", 150);
		
		Form C("Trash", 150, 150);
		std::cout << C;
		
		C.beSigned(A);
		// C.beSigned(B);
		std::cout << C;

		Form D("Banger", 1, 75);
		std::cout << D;
		
		D.beSigned(A);
		// D.beSigned(B);
		std::cout << D;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

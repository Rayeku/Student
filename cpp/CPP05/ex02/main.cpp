/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:31:32 by abougrai          #+#    #+#             */
/*   Updated: 2024/11/26 14:33:48 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		// AForm test;
		
		Bureaucrat Abougrai("Abougrai", 1);
		Bureaucrat Cbougrai("Cbougrai", 150);
		PresidentialPardonForm 	A;
		RobotomyRequestForm		B;
		ShrubberyCreationForm	C;

		A.beSigned(Abougrai);
		A.execute(Abougrai);
		
		B.beSigned(Abougrai);
		B.execute(Abougrai);
		
		C.beSigned(Abougrai);
		C.execute(Abougrai);
		
		// A.beSigned(Cbougrai);
		// A.execute(Cbougrai);

		// A.beSigned(Abougrai);
		// Cbougrai.executeForm(A);
		// Abougrai.executeForm(A);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

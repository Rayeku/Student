/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:31:32 by abougrai          #+#    #+#             */
/*   Updated: 2024/11/26 14:41:16 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat Abougrai("Abougrai", 1);
		Bureaucrat Cbougrai("Cbougrai", 150);
		Intern intern;
		
		AForm *test1 = intern.makeForm("RobotomyRequestForm", "DeadWood");
		AForm *test2 = intern.makeForm("PresidentialPardonForm", "DeadWood");
		AForm *test3 = intern.makeForm("ShrubberyCreationForm", "DeadWood");

		// std::cout << *test1;
		// std::cout << *test2;
		// std::cout << *test3;
		
		// delete (intern.makeForm("ShrubberyCreationForm","DeadWood"));
		// delete (intern.makeForm("test","Hello"));
		
		test1->beSigned(Abougrai);
		test1->execute(Abougrai);
		
		test2->beSigned(Abougrai);
		test2->execute(Abougrai);
		
		test3->beSigned(Abougrai);
		test3->execute(Abougrai);

		delete test1;
		delete test2;
		delete test3;
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

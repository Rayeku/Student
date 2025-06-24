/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:10:23 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/16 23:17:22 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


class Intern
{

	public:
	// Constructor(s)
		Intern();
		Intern(const Intern &src);

	// Deconstructor(s)
		~Intern();

	// Overloaded Operators
		Intern &operator=(const Intern &src);

	//Method(s)
		AForm *makeForm(const std::string form, const std::string target);

};

#endif
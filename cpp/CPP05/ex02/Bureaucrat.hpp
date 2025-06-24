/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:32:02 by abougrai          #+#    #+#             */
/*   Updated: 2024/11/26 13:16:24 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

// Include(s)
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	// Constructor(s)
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &Bureaucrat);

	// Deconstructor(s)
	~Bureaucrat();

	// Exception(s)
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "GradeTooHighException thrown";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "GradeTooLowException thrown";
		}
	};
	
	class SelfCopyInit : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Self-copy attempted during construction";
		}
	};
	
	// Copy assignation overload
	Bureaucrat &operator=(const Bureaucrat &Bureaucrat);

	// Getter(s)
	std::string getName() const;
	int getGrade() const;

	// Method(s)
	void decrementeGrade();
	void incrementGrade();
	
	void signAForm(const AForm &F) const;
	void statusForm(AForm const &form) const;
	void executeForm(AForm const &form) const;

};

// Overload operator(s)
std::ostream &operator<<(std::ostream &o, Bureaucrat &B);

#endif
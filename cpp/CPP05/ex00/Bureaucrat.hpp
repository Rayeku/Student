/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:32:02 by abougrai          #+#    #+#             */
/*   Updated: 2024/10/16 23:17:22 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RESET "\033[0m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

// Include(s)
#include <iostream>
#include <string>
#include <exception>

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
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Grade is too low!";
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
};

// Overload operator(s)
std::ostream &operator<<(std::ostream &o, Bureaucrat &B);

#endif
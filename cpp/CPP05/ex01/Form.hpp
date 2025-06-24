/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:27:16 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/26 12:18:21 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
    bool _signed;
    const int _gradeSign;
    const int _gradeExec;

public:
	// Constructor(s)
	Form();
	Form(std::string name, int toSigned, int toExecute);
	Form(const Form &Form);

	// Deconstructor(s)
	~Form();

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
	Form &operator=(const Form &Form);

	// Getter(s)
	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;
	
	// Method(s)
	void beSigned(const Bureaucrat &B);
};

// Overload operator(s)
std::ostream &operator<<(std::ostream &o, Form &F);

#endif
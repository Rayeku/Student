/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:27:16 by rayeku            #+#    #+#             */
/*   Updated: 2024/09/29 03:19:07 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
    bool _signed;
    const int _gradeSign;
    const int _gradeExec;

public:
	// Constructor(s)
	AForm();
	AForm(std::string name, int toSigned, int toExecute);
	AForm(const AForm &AForm);

	// Deconstructor(s)
	virtual ~AForm();

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

	class FormIsNotSignedException : public std::exception
	{
	public:
		const char *what() const noexcept override
		{
			return "Form not signed exception thrown";
		}
	};
	
	// Copy assignation overload
	AForm &operator=(const AForm &AForm);

	// Getter(s)
	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;

	// Setter(s)
	void setSignedTrue(); 
	
	// Method(s)
	virtual void beSigned(const Bureaucrat &B) = 0;
	virtual void exec(Bureaucrat const &executor) const = 0;
	void execute(Bureaucrat const &executor) const;
};

// Overload operator(s)
std::ostream &operator<<(std::ostream &o, AForm &F);

#endif
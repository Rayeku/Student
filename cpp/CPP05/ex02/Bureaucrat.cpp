/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:37:30 by abougrai          #+#    #+#             */
/*   Updated: 2024/11/26 13:22:28 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DeadWood"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	(grade < 1) ? throw Bureaucrat::GradeTooHighException() :
	(grade > 150) ? throw Bureaucrat::GradeTooLowException() :
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name("_copy")
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	(this == &copy) ? throw Bureaucrat::SelfCopyInit() : 
	*this = copy;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_grade = copy._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 0) 
		throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrementeGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::signAForm(const AForm &F) const
{
	if (this->getGrade() > F.getGradeSign()) 
	{
		std::cout << ITALIC << ORANGE << this->getName() << RESET;
		std::cout << " couldn't signed " << BOLD << BROWN << F.getName() << RESET;
		std::cout << " because " << RED << "grade is too low" << RESET << std::endl;
	}
	else
	{
		std::cout << ITALIC << ORANGE << this->getName() << RESET;
		std::cout << " signed " << BOLD << BROWN << F.getName() << RESET << std::endl;	
	}
}

void Bureaucrat::statusForm(AForm const &form) const
{
	if (form.getSigned() == false)
	{
		std::cout << ITALIC << ORANGE << this->getName() << RESET;
		std::cout << " couldn't execute " << BOLD << BROWN << form.getName() << RESET;
		std::cout << " because " << RED << "form not signed" << RESET << std::endl;
	}
	else if (this->_grade > form.getGradeExec())
	{
		std::cout << ITALIC << ORANGE << this->getName() << RESET;
		std::cout << " couldn't execute " << BOLD << BROWN << form.getName() << RESET;
		std::cout << " because " << RED << "grade is too low" << RESET << std::endl;
	}
	else
	{
		std::cout << ITALIC << ORANGE << this->getName() << RESET;
		std::cout << " executed " << BOLD << BROWN << form.getName() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	form.execute(*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &B)
{
	o << "Bureaucrat : " << ITALIC << ORANGE << B.getName() << RESET;
	o << " Grade : " << BOLD << BROWN << B.getGrade() << RESET << std::endl;
	return (o);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:31:59 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/26 14:30:12 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	(this == &copy) ? throw ShrubberyCreationForm::SelfCopyInit() : 
	*this = copy;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor called" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_target = copy._target;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &B)
{
	B.signAForm(*this);
	(B.getGrade() > this->getGradeSign()) ? throw AForm::GradeTooLowException() :
	this->setSignedTrue();
}

void ShrubberyCreationForm::exec(Bureaucrat const &executor) const
{
	std::ofstream	outfile;
	
	outfile.open((this->_target + "_shrubbery").c_str());
	if (outfile.fail())
	{
		std::cout << "Could not open output file" << std::endl;
		return ;
	}
	outfile << TREE;
	outfile.close();
	std::cout << ORANGE << executor.getName() << RESET << " successfully created a shrubbery" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm &F)
{
	o << std::endl;
	o << "ShrubberyCreationForm name : " << BOLD << BROWN << F.getName() << RESET << std::endl;
	o << "Is signed : " << CYAN << F.getSigned() << RESET << std::endl;
	o << "GradeSign : " << CYAN << F.getGradeSign() << RESET << std::endl;
	o << "GradeExec : " << CYAN << F.getGradeExec() << RESET << std::endl;
	o << "Target : " << CYAN << F.getTarget() << RESET << std::endl;
	return (o);
}
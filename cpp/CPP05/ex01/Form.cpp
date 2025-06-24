/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:42:51 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/26 12:58:58 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :  _name("Contract"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}
Form::Form(std::string name, int toSigned, int toExecute) : _name(name), _gradeSign(toSigned), _gradeExec(toExecute)
{
	std::cout << "Form constructor called" << std::endl;
	((toSigned > 150 || toExecute > 150)) ? throw Form::GradeTooLowException() :
	((toSigned < 0 || toExecute < 0)) ? throw Form::GradeTooHighException() :
	this->_signed = false;
}
Form::Form(const Form &copy) : _name("_copy"), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "Form Copy constructor called" << std::endl;
	(this == &copy) ? throw Form::SelfCopyInit() :
	*this = copy;
}
Form::~Form()
{
	std::cout << "Form Deconstructor called" << std::endl;
}
Form &Form::operator=(const Form &copy)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_signed = copy._signed;
   	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);	
}

bool Form::getSigned() const
{
	return (this->_signed);
}
	
int Form::getGradeSign() const
{
	return (this->_gradeSign);	
}

int Form::getGradeExec() const
{
	return (this->_gradeExec);
}

void Form::beSigned(const Bureaucrat &B)
{
	 B.signForm(*this);
	(B.getGrade() > this->getGradeSign()) ? throw Form::GradeTooLowException() :
	this->_signed = true;	
}

std::ostream	&operator<<(std::ostream &o, Form &F)
{
	o << std::endl;
	o << "Form name : " << BOLD << BROWN << F.getName() << RESET << std::endl;
	o << "Is signed : " << CYAN << F.getSigned() << RESET << std::endl;
	o << "GradeSign : " << CYAN << F.getGradeSign() << RESET << std::endl;
	o << "GradeExec : " << CYAN << F.getGradeExec() << RESET << std::endl;
	return (o);
}
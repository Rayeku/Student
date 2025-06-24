/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:42:51 by rayeku            #+#    #+#             */
/*   Updated: 2024/09/29 03:20:33 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :  _name("Contract"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}
AForm::AForm(std::string name, int toSigned, int toExecute) : _name(name), _gradeSign(toSigned), _gradeExec(toExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	((toSigned > 150 || toExecute > 150)) ? throw AForm::GradeTooLowException() :
	((toSigned < 0 || toExecute < 0)) ? throw AForm::GradeTooHighException() :
	this->_signed = false;
}
AForm::AForm(const AForm &copy) : _name("_copy"), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "AForm Copy constructor called" << std::endl;
	(this == &copy) ? throw AForm::SelfCopyInit() :
	*this = copy;
}
AForm::~AForm()
{
	std::cout << "AForm Deconstructor called" << std::endl;
}
AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_signed = copy._signed;
   	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);	
}

bool AForm::getSigned() const
{
	return (this->_signed);
}
	
int AForm::getGradeSign() const
{
	return (this->_gradeSign);	
}

int AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

void AForm::setSignedTrue()
{
	this->_signed = true;
}
void AForm::beSigned(const Bureaucrat &B)
{
	B.signAForm(*this);
	(B.getGrade() > this->getGradeSign()) ? throw AForm::GradeTooLowException() :
	this->setSignedTrue();
}
void AForm::execute(Bureaucrat const &executor) const
{
	(this->_signed == false) ? throw (AForm::FormIsNotSignedException()) :
	executor.statusForm(*this),
	(executor.getGrade() > this->_gradeSign) ? throw (AForm::GradeTooLowException()) :
	this->exec(executor);
}

std::ostream	&operator<<(std::ostream &o, AForm &F)
{
	o << std::endl;
	o << "AForm name : " << BOLD << BROWN << F.getName() << RESET << std::endl;
	o << "Is signed : " << CYAN << F.getSigned() << RESET << std::endl;
	o << "GradeSign : " << CYAN << F.getGradeSign() << RESET << std::endl;
	o << "GradeExec : " << CYAN << F.getGradeExec() << RESET << std::endl;
	return (o);
}
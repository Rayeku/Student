/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:41:14 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/26 14:30:30 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	(this == &copy) ? throw PresidentialPardonForm::SelfCopyInit() : 
	*this = copy;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Deconstructor called" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_target = copy._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::beSigned(const Bureaucrat &B)
{
	B.signAForm(*this);
	(B.getGrade() > this->getGradeSign()) ? throw AForm::GradeTooLowException() :
	this->setSignedTrue();
}

void PresidentialPardonForm::exec(Bureaucrat const &executor) const
{
	std::cout << ORANGE << this->_target << RESET << ITALIC << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm &F)
{
	o << std::endl;
	o << "ShrubberyCreationForm name : " << BOLD << BROWN << F.getName() << RESET << std::endl;
	o << "Is signed : " << CYAN << F.getSigned() << RESET << std::endl;
	o << "GradeSign : " << CYAN << F.getGradeSign() << RESET << std::endl;
	o << "GradeExec : " << CYAN << F.getGradeExec() << RESET << std::endl;
	o << "Target : " << CYAN << F.getTarget() << RESET << std::endl;
	return (o);
}
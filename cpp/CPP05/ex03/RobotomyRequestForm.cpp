/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:44:50 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/26 14:30:35 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 25, 5), _target(target)
{
	std::cout << "RobotomyRequestForm Target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	(this == &copy) ? throw RobotomyRequestForm::SelfCopyInit() : 
	*this = copy;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Deconstructor called" << std::endl;
}
std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_target = copy._target;
	return (*this);
}

void RobotomyRequestForm::beSigned(const Bureaucrat &B)
{
	B.signAForm(*this);
	(B.getGrade() > this->getGradeSign()) ? throw AForm::GradeTooLowException() :
	this->setSignedTrue();
}
void RobotomyRequestForm::exec(Bureaucrat const &executor) const
{
 	srand(static_cast<unsigned>(time(0)));
    int randomValue = rand() % 2;
	std::cout << ORANGE << this->_target << RESET;
	(randomValue ? std::cout << FAILED : std::cout << SUCCESS );
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm &F)
{
	o << std::endl;
	o << "ShrubberyCreationForm name : " << BOLD << BROWN << F.getName() << RESET << std::endl;
	o << "Is signed : " << CYAN << F.getSigned() << RESET << std::endl;
	o << "GradeSign : " << CYAN << F.getGradeSign() << RESET << std::endl;
	o << "GradeExec : " << CYAN << F.getGradeExec() << RESET << std::endl;
	o << "Target : " << CYAN << F.getTarget() << RESET << std::endl;
	return (o);
}
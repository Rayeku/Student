/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:27:11 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/16 23:17:22 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#define SUCCESS ITALIC " has been robotomized successfully\n" RESET
#define FAILED ITALIC " robotomized has failed\n" RESET

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
private:
        std::string _target;
public:
	// Constructor(s)
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
	RobotomyRequestForm(std::string target);

	// Deconstructor(s)
	~RobotomyRequestForm();
	
	// Copy assignation overload
	RobotomyRequestForm &operator=(const RobotomyRequestForm &RobotomyRequestForm);

	// Getter(s)
	std::string getTarget() const;
	
	// Method(s)
	virtual void beSigned(const Bureaucrat &B);
	virtual void exec(Bureaucrat const &executor) const;

};

// Overload operator(s)
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm &F);

#endif
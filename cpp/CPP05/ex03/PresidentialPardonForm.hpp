/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:24:34 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/16 23:17:22 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
private:
        std::string _target;
public:
	// Constructor(s)
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm);
	PresidentialPardonForm(std::string target);

	// Deconstructor(s)
	~PresidentialPardonForm();
	
	// Copy assignation overload
	PresidentialPardonForm &operator=(const PresidentialPardonForm &PresidentialPardonForm);

	// Getter(s)
	std::string getTarget() const;
	
	// Method(s)
	virtual void beSigned(const Bureaucrat &B);
	virtual void exec(Bureaucrat const &executor) const;

};

// Overload operator(s)
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm &F);

#endif
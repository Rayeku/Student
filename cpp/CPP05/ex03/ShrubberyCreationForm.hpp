/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:41:04 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/16 23:17:22 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

#define TREE "        ⅄ ⅄ ⅄      \n\
      ⅄ ⅄   ⅄ ⅄      \n\
    ⅄ ⅄     @ ⅄ ⅄    \n\
  ⅄ ⅄    @      ⅄ ⅄   \n\
⅄ ⅄   @           ⅄ ⅄ \n\
Y Y       @   @   Y Y \n\
  Y Y   @       Y Y \n\
    Y Y       Y Y \n\
      Y Y   Y Y \n\
        Y Y Y \n\
        |   | \n\
        |   | \n\
        |   | \n\
        |   | \n\
        |   | \n"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
private:
        std::string _target;
public:
	// Constructor(s)
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm);
  ShrubberyCreationForm(std::string target);

	// Deconstructor(s)
	~ShrubberyCreationForm();

	// Copy assignation overload
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ShrubberyCreationForm);

	// Getter(s)
	std::string getTarget() const;
	
	// Method(s)
	virtual void beSigned(const Bureaucrat &B);
	virtual void exec(Bureaucrat const &executor) const;
};

// Overload operator(s)
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm &F);

#endif
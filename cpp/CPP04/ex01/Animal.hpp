/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:14:06 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/23 23:54:36 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define RED "\033[31m"
# define CYAN "\033[36m"
# define BLUE "\033[34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define ITALIC "\033[3m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define BLUE_DARK "\033[34m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"
# define MAGENTA_LIGHT "\033[38;5;205m"

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(std::string name);
	virtual ~Animal();
	Animal &operator=(const Animal &Animal);
	Animal(const Animal &Animal);
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
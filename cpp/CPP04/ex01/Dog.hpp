/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:21 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/24 00:19:15 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Cat.hpp"

class Dog : virtual public Animal
{
  private:
	Brain *_brain;

  public:
	Dog();
	Dog(std::string name);
	~Dog();
	Dog &operator=(const Dog &Dog);
	Dog(const Dog &Dog);
	void makeSound() const;
	void printBrain() const;
	void changeBrain(std::string newIdea) const;
};

#endif
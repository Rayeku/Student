/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:29 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/23 22:57:15 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : virtual public Animal
{
  private:
	Brain *_brain;

  public:
	Cat();
	Cat(std::string name);
	~Cat();
	Cat &operator=(const Cat &Cat);
	Cat(const Cat &Cat);
	void makeSound() const;
	void printBrain() const;
	void changeBrain(std::string newIdea) const;
};

#endif
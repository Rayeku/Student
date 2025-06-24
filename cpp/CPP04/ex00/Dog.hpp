/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:21 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/19 18:21:08 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Cat.hpp"

class Dog : virtual public Animal
{
  public:
	Dog();
	Dog(std::string name);
	~Dog();
	Dog &operator=(const Dog &Dog);
	Dog(const Dog &Dog);
	void makeSound() const;
};

#endif
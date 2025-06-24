/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:42:07 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/21 14:31:36 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Dog.hpp"

class WrongAnimal : public Animal
{
  public:
	WrongAnimal();
	WrongAnimal(std::string name);
	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &WrongAnimal);
	WrongAnimal(const WrongAnimal &WrongAnimal);
	void makeSound() const;
};

#endif
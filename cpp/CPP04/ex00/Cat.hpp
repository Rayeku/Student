/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:15:29 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/19 18:21:34 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : virtual public Animal
{
  public:
	Cat();
	Cat(std::string name);
	~Cat();
	Cat &operator=(const Cat &Cat);
	Cat(const Cat &Cat);
	void makeSound() const;
};

#endif
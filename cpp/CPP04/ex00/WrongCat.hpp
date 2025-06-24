/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:42:31 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/19 18:22:38 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public Animal
{

  public:
	WrongCat();
	WrongCat(std::string name);
	~WrongCat();
	WrongCat &operator=(const WrongCat &WrongCat);
	WrongCat(const WrongCat &WrongCat);
	void makeSound() const;
};

#endif
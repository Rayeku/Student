/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:07:41 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:18:41 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("")
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << MAGENTA << this->_name << RESET << " " << RED << DESTROY << RESET << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << MAGENTA << _name << RESET ": " << ORANGE << BRAIN << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:33:45 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/12 05:22:56 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
};
Harl::~Harl()
{
	return ;
};
void Harl::complain(std::string level)
{
	Functions functions[] = {&Harl::debug, &Harl::info, &Harl::warning,&Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	std::cout << INVALID << std::endl;
};
void Harl::debug(void)
{
	std::cout << DEBUG << std::endl;
};
void Harl::info(void)
{
	std::cout << INFO << std::endl;
};
void Harl::warning(void)
{
	std::cout << WARNING << std::endl;
};
void Harl::error(void)
{
	std::cout << ERROR << std::endl;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:33:45 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/10 15:37:24 by abougrai         ###   ########.fr       */
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

void Harl::debug(void)
{
	std::cout << YELLOW << "[ DEBUG ]" << std::endl << DEBUG << std::endl << std::endl;
};
void Harl::info(void)
{
	std::cout << DARK_YELLOW << "[ INFO ]" << std::endl << INFO << std::endl << std::endl;
};
void Harl::warning(void)
{
	std::cout << DARK_ORANGE << "[ WARNING ]" << std::endl << WARNING << std::endl << std::endl;
};
void Harl::error(void)
{
	std::cout << RED << "[ ERROR ]" << std::endl << ERROR << std::endl << std::endl;
};
int Harl::Blabla(void)
{
	std::cout << ITALIC << BLABLA << std::endl;
	return (0);
};
int	Harl::DoThings(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			if (this->complain(i))
				return (0);
	this->complain(-1);
	return (0);
}
int Harl::complain(int i)
{
	Functions functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	switch (i)
	{
	case 0:
		(this->*functions[i++])();
	case 1:
		(this->*functions[i++])();
	case 2:
		(this->*functions[i++])();
	case 3:
		(this->*functions[i])();
		return (true);
	default:
		std::cout << NOTFOUND << std::endl;
		break ;
	}
	return (true);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:02:16 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/01 11:58:21 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	Phone;

	std::string cmd = "";
	Phone.Init();
	while (true)
	{
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			Phone.Add_Contact();
		else if (cmd == "SEARCH")
			Phone.Search_Contact();
		else if (cmd == "EXIT")
		{
			std::cout << RIP << std::endl;
			break ;
		}
		else if (std::cin.eof())
			break ;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:02:23 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/01 12:47:17 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	numbContact = 0;
	index = 0;
	totalContact = 1;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}
bool	IsAllDigit(std::string number)
{
	if (!number[0])
		return (false);
	for (int i = 0; number[i]; i++)
		if (!isdigit(number[i]))
			return (false);
	return (true);
}

bool	IsThereDigit(std::string names)
{
	for (int i = 0; names[i]; i++)
		if (isdigit(names[i]))
			return (true);
	return (false);
}

bool	CheckIndex(std::string index)
{
	if (index.length() != 1)
		return (false);
	if (index <= "0" || index >= "9")
		return (false);
	return (true);
}

void PhoneBook::Init()
{
	std::cout << WELCOME << std::endl;
	std::cout << AVAILABLE << std::endl;
	std::cout << ADD << std::endl;
	std::cout << SEARCH << std::endl;
	std::cout << EXIT << std::endl;
	std::cout << COMMAND << std::endl;
}

void PhoneBook::DisplayInformation()
{
	std::cout << INFO0 << CYAN << index << RESET << std::endl;
	std::cout << INFO1 << CYAN << contacts[index
		- 1].firstName << RESET << std::endl;
	std::cout << INFO2 << CYAN << contacts[index
		- 1].lastName << RESET << std::endl;
	std::cout << INFO3 << CYAN << contacts[index
		- 1].nickName << RESET << std::endl;
	std::cout << INFO4 << CYAN << contacts[index
		- 1].number << RESET << std::endl;
	std::cout << INFO5 << CYAN << contacts[index
		- 1].secret << RESET << std::endl;
}

void PhoneBook::DisplayContact()
{
	for (int i = 0; i < totalContact; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << (contacts[i].firstName.length() > 10 ? contacts[i].firstName.substr(0,
				9) + "." : contacts[i].firstName) << "|";
		std::cout << std::setw(10) << std::right << (contacts[i].lastName.length() > 10 ? contacts[i].lastName.substr(0,
				9) + "." : contacts[i].lastName) << "|";
		std::cout << std::setw(10) << std::right << (contacts[i].nickName.length() > 10 ? contacts[i].nickName.substr(0,
				9) + "." : contacts[i].nickName) << "|" << std::endl;
		std::cout << BLANK << std::endl;
	}
	std::cout << FLOOR << std::endl;
}
void PhoneBook::DisplayRepo()
{
	if (std::cin.eof())
		exit(0);
	std::cout << CEILING << std::endl;
	std::cout << BORDER << std::endl;
	std::cout << BLANK << std::endl;
}

void PhoneBook::AddContact(const Contact &newContact)
{
	if (numbContact != 0 && numbContact != 8 && totalContact != 8)
		totalContact++;
	numbContact = numbContact % 8;
	contacts[numbContact++] = newContact;
	std::cout << ADDSUCESS << std::endl;
}

void PhoneBook::Add_Contact()
{
	Contact	newContact;

	std::cout << F_NAME << std::endl;
	{
		while (true)
		{
			std::getline(std::cin, newContact.firstName);
			if (!newContact.firstName.empty()
				&& !IsThereDigit(newContact.firstName))
				break ;
			else if (std::cin.eof())
				return (std::cin.clear(), newContact.~Contact(), exit(0));
		}
	}
	std::cout << L_NAME << std::endl;
	{
		while (true)
		{
			std::getline(std::cin, newContact.lastName);
			if (!newContact.lastName.empty()
				&& !IsThereDigit(newContact.lastName))
				break ;
			else if (std::cin.eof())
				return (std::cin.clear(), newContact.~Contact(), exit(0));
		}
	}
	std::cout << N_NAME << std::endl;
	{
		while (true)
		{
			std::getline(std::cin, newContact.nickName);
			if (!newContact.nickName.empty())
				break ;
			else if (std::cin.eof())
				return (std::cin.clear(), newContact.~Contact(), exit(0));
		}
	}
	std::cout << NUMBER << std::endl;
	{
		while (true)
		{
			std::getline(std::cin, newContact.number);
			if (!newContact.number.empty())
			{
				if (newContact.number.length() == 10
					&& IsAllDigit(newContact.number))
					break ;
			}
			else if (std::cin.eof())
				return (std::cin.clear(), newContact.~Contact(), exit(0));
		}
	}
	std::cout << SECRET << std::endl;
	{
		while (true)
		{
			std::getline(std::cin, newContact.secret);
			if (!newContact.secret.empty())
				break ;
			else if (std::cin.eof())
				return (std::cin.clear(), newContact.~Contact(), exit(0));
		}
	}
	if (std::cin.eof())
		return (std::cin.clear(), newContact.~Contact(), exit(0));
	this->AddContact(newContact);
	std::cout << COMMAND << std::endl;
}

void PhoneBook::Search_Contact()
{
	std::string index = "";
	if (!numbContact && totalContact != 8)
	{
		std::cout << NOCONTACT << std::endl;
		std::cout << COMMAND << std::endl;
		return ;
	}
	else
	{
		DisplayRepo();
		DisplayContact();
		std::cout << INDEX << std::endl;
		while (true)
		{
			getline(std::cin, index);
			if (!index.empty() && CheckIndex(index) && IsAllDigit(index))
			{
				this->index = index[0] - 48;
				if (this->index <= totalContact)
				{
					DisplayInformation();
					break ;
				}
			}
			else if (std::cin.eof())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
					'\n');
				this->~PhoneBook();
				return ;
			}
		}
	}
	std::cout << COMMAND << std::endl;
}

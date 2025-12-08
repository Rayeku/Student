/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:02:23 by abougrai          #+#    #+#             */
/*   Updated: 2025/12/08 11:05:25 by rayeku           ###   ########.fr       */
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

bool IsAllDigit(const std::string &number)
{
    if (number.empty())
        return false;
    for (size_t i = 0; i < number.length(); i++)
        if (!isdigit(number[i]))
            return false;
    return true;
}

bool IsThereDigit(const std::string &names)
{
    for (size_t i = 0; i < names.length(); i++)
        if (isdigit(names[i]))
            return true;
    return false;
}

bool CheckIndex(const std::string &index)
{
    if (index.length() != 1)
        return false;
    if (index <= "0" || index >= "9")
        return false;
    return true;
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
    const Contact &c = contacts[index - 1];
    std::cout << INFO0 << CYAN << index << RESET << std::endl;
    std::cout << INFO1 << CYAN << c.getFirstName() << RESET << std::endl;
    std::cout << INFO2 << CYAN << c.getLastName() << RESET << std::endl;
    std::cout << INFO3 << CYAN << c.getNickName() << RESET << std::endl;
    std::cout << INFO4 << CYAN << c.getNumber() << RESET << std::endl;
    std::cout << INFO5 << CYAN << c.getSecret() << RESET << std::endl;
}

void PhoneBook::DisplayContact()
{
    for (int i = 0; i < totalContact; i++)
    {
        const Contact &c = contacts[i];
        std::cout << "|";
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        std::cout << std::setw(10) << std::right
                  << (c.getFirstName().length() > 10 ? c.getFirstName().substr(0, 9) + "." : c.getFirstName()) << "|";
        std::cout << std::setw(10) << std::right
                  << (c.getLastName().length() > 10 ? c.getLastName().substr(0, 9) + "." : c.getLastName()) << "|";
        std::cout << std::setw(10) << std::right
                  << (c.getNickName().length() > 10 ? c.getNickName().substr(0, 9) + "." : c.getNickName()) << "|"
                  << std::endl;
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
    Contact newContact;

    std::cout << F_NAME << std::endl;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty() && !IsThereDigit(input))
        {
            newContact.setFirstName(input);
            break;
        }
        else if (std::cin.eof())
            return (std::cin.clear(), exit(0));
    }

    std::cout << L_NAME << std::endl;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty() && !IsThereDigit(input))
        {
            newContact.setLastName(input);
            break;
        }
        else if (std::cin.eof())
            return (std::cin.clear(), exit(0));
    }

    std::cout << N_NAME << std::endl;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty())
        {
            newContact.setNickName(input);
            break;
        }
        else if (std::cin.eof())
            return (std::cin.clear(), exit(0));
    }

    std::cout << NUMBER << std::endl;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty() && input.length() == 10 && IsAllDigit(input))
        {
            newContact.setNumber(input);
            break;
        }
        else if (std::cin.eof())
            return (std::cin.clear(), exit(0));
    }

    std::cout << SECRET << std::endl;
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty())
        {
            newContact.setSecret(input);
            break;
        }
        else if (std::cin.eof())
            return (std::cin.clear(), exit(0));
    }

    this->AddContact(newContact);
    std::cout << COMMAND << std::endl;
}

void PhoneBook::Search_Contact()
{
    std::string idx = "";
    if (!numbContact && totalContact != 8)
    {
        std::cout << NOCONTACT << std::endl;
        std::cout << COMMAND << std::endl;
        return;
    }
    else
    {
        DisplayRepo();
        DisplayContact();
        std::cout << INDEX << std::endl;
        while (true)
        {
            std::getline(std::cin, idx);
            if (!idx.empty() && CheckIndex(idx) && IsAllDigit(idx))
            {
                this->index = idx[0] - '0';
                if (this->index <= totalContact)
                {
                    DisplayInformation();
                    break;
                }
            }
            else if (std::cin.eof())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
        }
    }
    std::cout << COMMAND << std::endl;
}

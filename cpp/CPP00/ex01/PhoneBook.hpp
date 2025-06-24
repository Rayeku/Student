/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:02:26 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/01 11:58:12 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

# define RED "\033[31m"
# define CYAN "\033[36m"
# define BLUE "\033[34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define ITALIC "\033[3m"
# define ORANGE "\033[33m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define BLUE_DARK "\033[34m"
# define ORANGE_DARK "\033[38;5;202m"
# define MAGENTA_LIGHT "\033[38;5;205m"

// Init
# define WELCOME GREEN BOLD "Welcome Welcome Welcome" RESET
# define COMMAND CYAN BOLD "Enter a command" RESET

# define AVAILABLE CYAN BOLD "Command available:" RESET
# define ADD GREEN BOLD "ADD :" ORANGE_DARK " Gives you the ability to add a new contact" RESET
# define SEARCH YELLOW BOLD "SEARCH :" ORANGE_DARK " Display the phonebook and display a specific contact by his index" RESET
# define EXIT RED BOLD "EXIT :" ORANGE_DARK " Makes you quit the program and contacts are lost forever" RESET

// Add
# define F_NAME YELLOW BOLD "Enter first name" RESET
# define L_NAME YELLOW BOLD "Enter last name" RESET
# define N_NAME YELLOW BOLD "Enter nickname" RESET
# define NUMBER YELLOW BOLD "Enter phone number" RESET
# define SECRET YELLOW BOLD "Enter your darkest secret" RESET
# define ADDSUCESS GREEN BOLD "Contact successfully added" RESET

// Search
# define NOCONTACT RED BOLD "No contact registered" RESET
# define INDEX CYAN BOLD "Enter an index" RESET

# define INFO0 ORANGE_DARK BOLD "Contact N°" RESET
# define INFO1 ORANGE_DARK BOLD "First Name 	: " RESET
# define INFO2 ORANGE_DARK BOLD "Last Name 	: " RESET
# define INFO3 ORANGE_DARK BOLD "Nickname 	: " RESET
# define INFO4 ORANGE_DARK BOLD "Phone Number 	: " RESET
# define INFO5 ORANGE_DARK BOLD "Darkest Secret 	: " RESET

# define CEILING MAGENTA_LIGHT BOLD "—————————————————————————————————————————————" RESET
# define BORDER BLUE_DARK BOLD "|     index|first name| last name|  nickname|" RESET
# define BLANK MAGENTA_LIGHT BOLD "|----------|----------|----------|----------|" RESET
# define FLOOR MAGENTA_LIGHT BOLD "—————————————————————————————————————————————" RESET

// Exit
# define RIP RED "RIP THE REAP" RESET

class PhoneBook
{
  private:
	Contact contacts[8];

  public:
	int numbContact;
	int totalContact;
	int index;
	void Init(void);
	void AddContact(const Contact &newContact);
	void DisplayRepo();
	void DisplayContact();
	void DisplayInformation();
	void Search_Contact();
	void Add_Contact();

	PhoneBook(void);
	~PhoneBook(void);
};

#endif
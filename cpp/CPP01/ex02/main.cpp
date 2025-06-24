/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:59:33 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/11 07:02:08 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define ADRESSSTR1 CYAN BOLD "Adress str 	 : " RESET 
#define ADRESSSTR2 CYAN BOLD "Adress stringPTR : " RESET 
#define ADRESSSTR3 CYAN BOLD "Adress stringREF : " RESET 

#define VALUESTR1 CYAN BOLD "Value str 	: " RESET 
#define VALUESTR2 CYAN BOLD "Value stringPTR : " RESET 
#define VALUESTR3 CYAN BOLD "Value stringREF : " RESET 

# define RED "\033[31m"
# define BOLD "\033[1m"
# define CYAN "\033[36m"
# define RESET "\033[0m"
# define MAGENTA "\033[35m"

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << ADRESSSTR1 << MAGENTA << &str << RESET << std::endl;
	std::cout << ADRESSSTR2 << MAGENTA << stringPTR << RESET << std::endl;
	std::cout << ADRESSSTR3 << MAGENTA << &stringREF << RESET << std::endl << std::endl;
	
	std::cout << VALUESTR1 << MAGENTA << str << RESET << std::endl;
	std::cout << VALUESTR2 << MAGENTA << *stringPTR << RESET << std::endl;
	std::cout << VALUESTR3 << MAGENTA << stringREF << RESET << std::endl;
	return (0);
}

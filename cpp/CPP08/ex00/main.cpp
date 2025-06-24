/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:19:19 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/26 15:21:51 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	try {	
		std::vector<int> capart;

		capart.push_back(10);
		capart.push_back(42);
		capart.push_back(56);
		capart.push_back(72);
		capart.push_back(90);

		easyfind(capart, 90);			// occurence found
		// easyfind(capart, 9999999); 	// exception No occurence found
		// easyfind(capart, 1000000); 	// execption No occurence found
	}
	catch (const std::logic_error &e) {
		std::cerr << RED "Exeception caught : " RESET << e.what() << std::endl;
	}

	try {
		std::array<int, 5> arr = {1,2,3,4,5};
		easyfind(arr, 2); 	// occurence found
		easyfind(arr, 42); 	// exception No occurence found
	}
	catch (const std::logic_error &e) {
		std::cerr << RED "Exeception caught : " RESET << e.what() << std::endl;
	}

	return (0);
}
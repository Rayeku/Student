/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:53:06 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/31 08:32:51 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) { std::cerr << RED ITALIC << "Error: " RESET << WRONGARG << std::endl; return (1); }
	try {
		BitcoinExchange	btc;
		btc.handleData(av[1]);
	}
	catch(const std::exception& e) {
		std::cerr << RED ITALIC << "Error: " RESET << e.what() << std::endl;
		return (1); 
	}
	return (0);
}
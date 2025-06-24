/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:38:57 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/29 07:46:02 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) { std::cerr << WrongArg << Usage << Exp; return (1); }
	else {
		try {
			RPN	rpn(av[1]);
        }
        catch(const std::exception& e) {
			std::cerr << RED ITALIC << "Error : " << e.what();
			return (1); 
            }
        }
	return (0);
}
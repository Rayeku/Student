/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:12:08 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/14 18:08:41 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// if (a < b)
	// 	std::cout << "a est plus petit que b" << std::endl;
	// if (a > b)
	// 	std::cout << "a est plus grand que b" << std::endl;
	// if (a != b)
	// 	std::cout << "a est different de b" << std::endl;
	// if (a <= b)
	// 	std::cout << "a est plus petit ou egal b" << std::endl;
	// if (a >= b)
	// 	std::cout << "a est plus grand ou egal b" << std::endl;
	// if (a == b)
	// 	std::cout << "a est egal a b" << std::endl;
	
	Fixed c(9);
	Fixed d(1);
	std::cout << c / 0 << std::endl;
	return (0);
}
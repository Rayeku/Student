/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:19:19 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/28 15:45:09 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"


// main from subject
// int main() {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
	
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int main() {
	try {
		Span Capart(300);
	
		Capart.addNumber(500);
		Capart.addNumber(300);
		Capart.addNumber(200);
		Capart.addNumber(100);
		std::cout << BROWN << "Longest : " << CYAN << Capart.longestSpan() << RESET << std::endl;
		std::cout << BROWN << "Shortest : " << CYAN << Capart.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED "Exception caught : " << e.what() << '\n';
	}
	std::cout << std::endl;
	
	
	try {
		Span Capart(2);
		
		Capart.addNumber(42);
		std::cout << Capart.longestSpan() << RESET << std::endl; // exception : Span needs at least two elements
		// std::cout << Capart.shortestSpan() << RESET << std::endl; // exception : Span needs at least two elements
	}
	catch(const std::exception& e) {
		std::cerr << RED "Exception caught : " << e.what() << '\n';
	}
	std::cout << std::endl;
	

	try {
		Span Capart(20000);
		Capart.fillSpan();
		
		std::cout << BROWN << "Longest : " << CYAN << Capart.longestSpan() << RESET << std::endl;
		std::cout << BROWN << "Shortest : " << CYAN << Capart.shortestSpan() << RESET << std::endl;
		Capart.addNumber(20); // exeception : Span is full
	}
	catch(const std::exception& e) {
		std::cerr << RED "Exception caught : " << e.what() << '\n';
	}
}
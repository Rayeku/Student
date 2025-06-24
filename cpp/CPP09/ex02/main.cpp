/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 07:31:05 by rayeku            #+#    #+#             */
/*   Updated: 2025/04/03 08:08:44 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) { std::cerr << WrongArg; return (1); }

	std::vector<int> inputVec;
	std::deque<int> inputDeque;

	for (int i = 1; i < ac; i++)
	{
		try
		{
			std::string argument = av[i];
			if (PmergeMe::isNumber(argument)) {
				int num = std::atoi(argument.c_str());
				inputVec.push_back(num);
				inputDeque.push_back(num);
			}
		}
		catch (const std::invalid_argument &e) { std::cerr << ErrorArg; return (1); }
	}
	PmergeMe pmerge(inputVec);
	pmerge.finalPrint();
	return (0);
}

// shuf -i 1-1000 -n 3000 | paste -sd " " 
// shuf -i 1-1000 -n 3000 | awk '{printf "%s ", $0}'

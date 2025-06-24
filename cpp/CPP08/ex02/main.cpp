/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:19:19 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/28 15:54:48 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
} */

int main ()
{
	MutantStack<int> capart;

	capart.push(21);
	capart.push(42);
	capart.push(63);
	
	MutantStack<int>::iterator it = capart.begin();
	MutantStack<int>::iterator ite = capart.end();
	
	std::cout << BOLD BROWN "Mutant size : "  << ORANGE << capart.size() << RESET << std::endl;
	std::cout << BOLD BROWN "Mutant First elem throught iterator : "  << ORANGE << *it << RESET << std::endl;
	// std::cout << BOLD BROWN "Mutant First elem throught top() method : "  << ORANGE << capart.top() << RESET << std::endl; // cause LIFO
	std::cout << BOLD BROWN "Mutant Last elem throught iterator : "  << ORANGE << *--ite	<< RESET << std::endl;
	++ite;
	
	for (int i = 1; it != ite; it++) {
		std::cout << ITALIC CYAN "Mutant Elem N°" << i++ << " : " << ORANGE << *it << RESET << std::endl;
	}
	
	std::cout << std::endl;
	
	
	std::vector<int> test;
	test.push_back(21);
	test.push_back(42);
	test.push_back(63);

	for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it) {
    std::cout << ITALIC CYAN "Vector Elem N°" << (it - test.begin() + 1) << " : " << ORANGE << *it << RESET << std::endl;
	}
	
	std::cout << std::endl;
	
	
	std::list<int> list(capart.begin(), capart.end());
	int i = 1;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
    std::cout << ITALIC CYAN "List Elem N°" << i++ << " : " << ORANGE << *it << RESET << std::endl;
	}
}
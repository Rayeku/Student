/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:21:24 by rayeku            #+#    #+#             */
/*   Updated: 2026/02/08 23:14:43 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

int main() {
	try {
		Bank bank = Bank();
		cout << bank << endl;
		
		size_t ID0 = bank.addCustomer(100);
		size_t ID1 = bank.addCustomer(400);
		size_t ID2 = bank.addCustomer(1000);
		size_t ID3 = bank.addCustomer(700);
		size_t ID4 = bank.addCustomer(500000);
		
		std::cout << bank << std::endl;

		Account *A = bank[ID0];
		Account *B = bank[ID1];
		Account *C = bank[ID2];
		Account *D = bank[ID3];
		Account *E = bank[ID4];
		
		cout << "From main " << *(A) << endl;
		cout << "From main " << *(B) << endl;
		cout << "From main " << *(C) << endl;
		cout << "From main " << *(D) << endl;
		cout << "From main " << *(E) << endl << endl;

		std::cout << bank << std::endl;
		
		bank.depositCustomer(ID0, 200);
		bank.loanCustomer(ID1, 20);
		bank.withdrawalCustomer(ID4, 400000);
		
		std::cout << bank;
	}
	catch (const std::exception &e) {
		std::cerr << BOLD "Error : " << RESET;
		std::cerr << e.what() << '\n';
	}
	return (0);
}
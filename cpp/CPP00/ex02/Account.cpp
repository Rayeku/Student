/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 06:10:53 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/13 07:35:09 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iterator>
#include <utility>

#define RED "\033[31m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define ITALIC "\033[3m"
#define BROWN "\033[38;2;139;69;19m"
#define ORANGE_DARK "\033[38;5;202m"
#define PURPLE "\033[38;2;25;25;112m"
#define DARK_BLUE2 "\033[38;2;0;0;139m"
#define BLUE_TURQUOISE "\033[38;2;64;224;208m"

#define INDEX BOLD BLUE_TURQUOISE "index" RESET ":"
#define CREATED BOLD GREEN "created" RESET
#define CLOSED BOLD RED "closed" RESET

#define REFUSED BOLD RED "refused" RESET
#define WITHDRAW BOLD PURPLE "withdrawal" RESET ":"
#define NBWITHDRAW BOLD PURPLE "nb_withdrawals" RESET ":"

#define AMOUNT BOLD PURPLE "amount" RESET ":"
#define P_AMOUT BOLD PURPLE "p_amount" RESET ":"
#define DEPOS BOLD PURPLE "deposits" RESET ":"
#define DEPO BOLD DARK_BLUE2 "deposit" RESET ":"
#define NBDEPO BOLD PURPLE "nb_deposits" RESET ":"

#define TOTAL3 BOLD BROWN "deposits" RESET ":"
#define TOTAL2 BOLD BROWN "total" RESET ":"
#define TOTAL1 BOLD BROWN "accounts" RESET ":"
#define TOTAL4 BOLD BROWN "withdrawals" RESET ":"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	return ;
};
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++; _totalAmount += initial_deposit;
	_amount = initial_deposit; _nbDeposits = 0; _nbWithdrawals = 0;
	_displayTimestamp();
	this->_amount = initial_deposit;
	std::cout << INDEX << ORANGE_DARK << BOLD << this->_accountIndex << RESET << ";";
	std::cout << AMOUNT << ORANGE_DARK << this->_amount << RESET << ";";
	std::cout << CREATED << std::endl;
};
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << INDEX << ORANGE_DARK << BOLD << this->_accountIndex << RESET << ";";
	std::cout << AMOUNT << ORANGE_DARK << this->_amount << RESET << ";";
	std::cout << CLOSED << std::endl;
	return ;
};
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
};
int Account::getTotalAmount(void)
{
	return (_totalAmount);
};
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
};
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
};
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << TOTAL1 << CYAN << BOLD << getNbAccounts() << RESET << ";";
	std::cout << TOTAL2 << CYAN << BOLD << getTotalAmount() << RESET << ";";
	std::cout << TOTAL3 << CYAN << BOLD << getNbDeposits() << RESET << ";";
	std::cout << TOTAL4 << CYAN << BOLD << getNbWithdrawals() << RESET << std::endl;
	return ;
};
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << INDEX << ORANGE_DARK << BOLD << this->_accountIndex << RESET << ";";
	std::cout << P_AMOUT << RED << this->_amount << RESET << ";";
	std::cout << DEPO << GREEN << deposit << RESET << ";";
	std::cout << AMOUNT << GREEN << this->_amount + deposit << RESET << ";";
	std::cout << NBDEPO << GREEN << ++this->_nbDeposits << RESET << std::endl;
	_totalAmount += deposit; this->_amount += deposit; _totalNbDeposits++;
};
bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount >= withdrawal)
	{
		_displayTimestamp();
		std::cout << INDEX << ORANGE_DARK << BOLD << this->_accountIndex << RESET << ";";
		std::cout << P_AMOUT << GREEN << this->_amount << RESET << ";";
		std::cout << WITHDRAW << RED << withdrawal << RESET << ";";
		std::cout << AMOUNT << RED << this->_amount - withdrawal << RESET << ";";
		std::cout << NBWITHDRAW << RED << ++this->_nbWithdrawals << RESET << std::endl;
		this->_amount -= withdrawal; _totalAmount -= withdrawal; _totalNbWithdrawals++;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << INDEX << ORANGE_DARK << BOLD << this->_accountIndex << RESET << ";";
		std::cout << P_AMOUT << GREEN << this->_amount << RESET << ";";
		std::cout << WITHDRAW << REFUSED << std::endl;
		return (false);
	}
	return (true);
};
int Account::checkAmount(void) const
{
	return (this->_amount);
};
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << INDEX << ORANGE_DARK << BOLD << this->_accountIndex << RESET << ";";
	std::cout << AMOUNT << ORANGE_DARK << this->_amount << RESET << ";";
	std::cout << DEPOS << GREEN << this->_nbDeposits << RESET << ";";
	std::cout << NBWITHDRAW << RED << this->_nbWithdrawals << RESET << std::endl;
};
void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);

	std::cout << ITALIC << "[";
	std::cout << CYAN;
	std::cout << (now->tm_year + 1900);
	std::cout << BROWN;

	if (now->tm_mon < 10)
		std::cout << 0;
	std::cout << now->tm_mon;
	std::cout << PURPLE;

	if (now->tm_mday < 10)
		std::cout << 0;
	std::cout << now->tm_mday;
	std::cout << RESET;
	std::cout << "_";
	std::cout << CYAN;

	if (now->tm_hour < 10)
		std::cout << 0;
	std::cout << now->tm_hour;
	std::cout << BROWN;

	if (now->tm_min < 10)
		std::cout << 0;
	std::cout << now->tm_min;
	std::cout << PURPLE;

	if (now->tm_sec < 10)
		std::cout << 0;
	std::cout << now->tm_sec;
	std::cout << RESET << ITALIC;
	std::cout << "] " << RESET;
};

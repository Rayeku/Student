/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:24:48 by rayeku            #+#    #+#             */
/*   Updated: 2026/02/08 21:46:44 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

// Include(s)
# include <iostream>

// Define(s)
# define BROWN "\033[38;5;94m"
# define RESET "\033[0m"

class Account
{
	private:
		size_t _id;
		double _value;

	public:
		size_t getId(void) const;
		double getValue(void) const;

	friend class Bank;
};

std::ostream& operator<<(std::ostream& os, const Account& account);

#endif
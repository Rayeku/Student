/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:41:25 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/28 15:52:02 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <vector>

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {};
		~MutantStack(void) {};

		MutantStack &operator=(MutantStack const &src) {
			if (this != src) {
				std::stack<T>::operator=(src);}
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator	begin(void) { return (std::stack<T>::c.begin()); }
		iterator	end(void) { return (std::stack<T>::c.end()); }
		const_iterator	begin(void) const { return (std::stack<T>::c.begin()); }
		const_iterator	end(void) const { return (std::stack<T>::c.end()); }
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:16:26 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/22 10:35:06 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

// Include(s)
#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t len, void (*func)(T &))
{
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}
template <typename T>
void printElem(T &x)
{
	std::cout << CYAN << x << RESET << std::endl;
}
#endif
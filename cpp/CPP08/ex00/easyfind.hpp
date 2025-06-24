/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:42:42 by rayeku            #+#    #+#             */
/*   Updated: 2025/01/30 01:39:44 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <list>
#include <vector>
#include <array>

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
typename T::iterator easyfind(T &ctr, int n)
{
    typename T::iterator found = std::find(ctr.begin(), ctr.end(), n);
    if (found != ctr.end())
    {
        std::cout << BROWN "Occurence found : " << ORANGE << *found << RESET << std::endl;
        return (found);
    }
    throw std::logic_error("No occurrence found");
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:16:26 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/22 09:33:03 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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
T min(T value1, T value2)
{
    if (value1 < value2)
        return (value1);
    return (value2);
}
template <typename T>
T max(T value1, T value2)
{
    if (value1 > value2)
        return (value1);
    return (value2);
}
template <typename T>
void swap(T &value1, T &value2)
{
    T temp;
    temp = value1;
    value1 = value2;
    value2 = temp;
}
#endif
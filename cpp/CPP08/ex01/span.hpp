/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:42:42 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/28 15:42:54 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <array>
#include <vector>
#include <numeric>
#include <random>

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _range;

public:
    Span(void);
    Span(unsigned int n);
    Span(Span const &src);
    ~Span(void);

    Span &operator=(Span const &src);

    void addNumber(int n);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
    void fillSpan(void);
    static int randomValue(void);


    template <typename Container>
    void addNumberRange(typename Container::iterator begin, typename Container::iterator end) {
        if (this->_range.size() + std::distance(begin, end) > this->_maxSize)
            throw Span::FullSpanException();
            
        this->_range.insert(this->_range.end(), begin, end);
    };

    class EmptySpanException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FullSpanException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif
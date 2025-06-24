/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:05:37 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/30 09:59:57 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// Constructor(s)
Span::Span(void) : _maxSize(0), _range() {}

Span::Span(unsigned int n) : _maxSize(n), _range() {}

Span::Span(Span const &src) : _maxSize(src._maxSize), _range(src._range) {}

// Destructor(s)
Span::~Span(void) {}

// Copy assignation overload
Span &Span::operator=(Span const &src) {
    if (this != &src) {
        this->_maxSize = src._maxSize;
        this->_range = src._range;
    }
    return (*this);
}

// Method(s)
void Span::addNumber(int n) {
    if (this->_range.size() >= this->_maxSize)
        throw Span::FullSpanException();
    this->_range.push_back(n);
}

unsigned int Span::longestSpan(void)
{
    if (this->_range.size() < 2)
        throw Span::EmptySpanException();

    unsigned int minValue = *std::min_element(this->_range.begin(), this->_range.end());
    unsigned int maxValue = *std::max_element(this->_range.begin(), this->_range.end());

    return (maxValue - minValue);
}

unsigned int Span::shortestSpan(void){
    int minValue;

    if (this->_range.size() < 2)
        throw Span::EmptySpanException();

    std::vector<int> spanCopy(this->_range);
    std::sort(spanCopy.begin(), spanCopy.end());

    std::vector<int> difference(spanCopy);
    std::adjacent_difference(spanCopy.begin(), spanCopy.end(), difference.begin());
    minValue = *std::min_element(++(difference.begin()), difference.end());
    
    return (minValue);
}

int Span::randomValue() { return (rand() % 20000) / 3.5; }

void Span::fillSpan() {
    srand(static_cast<unsigned>(time(0)));

    std::generate_n(std::back_inserter(_range), _maxSize - _range.size(), randomValue);
}


// Exception(s)
const char *Span::EmptySpanException::what() const throw() {
    return (ORANGE ITALIC "Span needs at least two elements" RESET);
}

const char *Span::FullSpanException::what() const throw() {
    return (ORANGE ITALIC "Span is full" RESET);
}
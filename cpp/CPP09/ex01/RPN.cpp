/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:41:39 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/31 08:48:40 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructor(s)
RPN::RPN(std::string userInput) {
	bool	digitChecker = false;

	for (size_t i = 0; i < userInput.size(); i++) {
		if (isdigit(userInput[i]) || ((userInput[i] == '+' || userInput[i] == '-') && isdigit(userInput[i + 1]))) {
			if (digitChecker) { throw InvalidRPNException(); }
			int	polarity = 1;
			if (userInput[i] == '+' || userInput[i] == '-') {
				if (userInput[i] == '-')
					polarity *= -1;
				i++;
            }
			int	digit = userInput[i] - '0';
			this->_stack.push(digit * polarity);
			digitChecker = true;
        }
		else {
			digitChecker = false;
			if (_isOp(userInput[i])) {
				if (this->_stack.size() < 2) { throw InvalidRPNException(); }
				double first = this->_stack.top();
				this->_stack.pop();
				double second = this->_stack.top();
				this->_stack.pop();
				double math = doMath(userInput[i], second, first);
				this->_stack.push(math);
			}
			else if (iswspace(userInput[i]))
				continue;
			else
				throw InvalidRPNException();
		}
	}
	if (this->_stack.size() != 1) { throw InvalidExpressionException(); }
	std::cout << BROWN << this->_stack.top() << RESET << std::endl;
}

RPN::RPN(RPN const &src) { *this = src; }

// Deconstructor(s)
RPN::~RPN(void) {}

// Copy assignation overload
RPN &RPN::operator=(RPN const &src) {
	if (this != &src) {
		this->_stack = src._stack;
	}
	return (*this);
}

// Method(s)
bool	RPN::_isOp(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

double	RPN::doMath(char op, double b, double a) {
	switch(op) {
		case '+':
			return (b + a);
		case '-':
			return (b - a);
		case '*':
			return (b * a);
		case '/':
			return (b / a);
		default:
			throw InvalidRPNException();
	}
}

// Exception(s)
const char * RPN::InvalidRPNException::what() const throw() { return (WrongInput); }
const char * RPN::InvalidExpressionException::what() const throw() { return (WrongRPN); }

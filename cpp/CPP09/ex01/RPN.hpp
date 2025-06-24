/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:11:47 by rayeku            #+#    #+#             */
/*   Updated: 2025/04/03 13:11:55 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"

// Include(s)
# include <iostream>
# include <stack>
# include <string>
# include <sstream>

// Define(s)
# define Usage BROWN BOLD "How is your input should looks like : " RESET
# define Exp CYAN ITALIC "'1 2 * 4 - 2 + 5 * 2 +'\n" RESET
# define WrongArg ORANGE BOLD "Invalid Argument\n" RESET
# define WrongInput ORANGE BOLD "Invalid input\n" RESET
# define WrongRPN ORANGE BOLD "Invalid RPN expression\n" RESET

class RPN
{
    private:
        std::stack<double>  _stack;

        bool _isOp(char c);

    public:
        RPN(std::string input);
        RPN(RPN const &src);
        ~RPN(void);

        RPN &operator=(RPN const &src);
        
        double doMath(char op, double x, double y);

        class	InvalidRPNException : public std::exception {
			public:
				virtual const char* what() const throw(); };

		class	InvalidExpressionException : public std::exception {
			public:
				virtual const char* what() const throw(); };
};

#endif
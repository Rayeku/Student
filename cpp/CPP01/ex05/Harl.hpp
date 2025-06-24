/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:10:17 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/12 05:23:02 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define BOLD "\033[1m"
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define YELLOW "\033[1;33m"
# define DARK_YELLOW "\033[0;38;5;94m"
# define DARK_ORANGE "\033[0;38;5;208m"

# define DEBUG YELLOW BOLD "DEBUG level:" RESET " I love having extra bacon for my bla bla bla..."
# define INFO DARK_YELLOW BOLD "INFO level:" RESET " I cannot believe adding extra bacon costs more money bla bla bla..."
# define WARNING DARK_ORANGE BOLD "WARNING level:" RESET " I think I deserve to have some extra bacon for bla bla ble ..."
# define ERROR RED BOLD "ERROR level:" RESET " This is unacceptable! I want to bla bla bla..."

# define INVALID RED BOLD "404 level not found" RESET

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl();
	~Harl();
	typedef void (Harl::*Functions)();
	void complain(std::string level);
};
#endif
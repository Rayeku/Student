/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:10:17 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/10 15:36:44 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define BOLD "\033[1m"
# define RESET "\033[0m"
# define RED "\033[0;31m"
# define ITALIC "\033[3m"
# define YELLOW "\033[1;33m"
# define DARK_YELLOW "\033[0;38;5;94m"
# define DARK_ORANGE "\033[0;38;5;208m"

# define DEBUG YELLOW BOLD "I love having extra bacon for my bla bla bla..." RESET
# define INFO DARK_YELLOW BOLD "I cannot believe adding extra bacon costs more money bla bla bla..." RESET
# define WARNING DARK_ORANGE BOLD "I think I deserve to have some extra bacon for bla bla ble ..." RESET
# define ERROR RED BOLD "This is unacceptable! I want to bla bla bla..." RESET

# define NOTFOUND RED BOLD ITALIC "[ Probably complaining about insignificant problems ]" RESET
# define BLABLA RED BOLD ITALIC "[ Probably Blablaing ....................... ]" RESET

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
	int	DoThings(std::string level);
	int Blabla(void);
	int complain(int i);

};
#endif
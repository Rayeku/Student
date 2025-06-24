/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:58:30 by abougrai          #+#    #+#             */
/*   Updated: 2024/04/12 01:35:00 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <fstream>
# include <iostream>
# include <string>

# define RED "\033[31m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define GREEN "\033[38;5;40m"
# define ORANGE "\033[38;5;208m"
# define ORANGE_DARK "\033[38;5;202m"

# define CAPART 0
# define ERRARG 1
# define ERRFILE 2
# define ERRCOPY 3
# define SUCESSCPY 42
# define SUCESSREP 21

# define INVARG RED BOLD "Invalid Arguments" RESET
# define ACCESS RED BOLD "Cannot access" RESET
# define NOCOPY RED BOLD "Cannot create copy of" RESET
# define YESCOPY ORANGE BOLD "Copy succesfully done" RESET
# define YESREP ORANGE BOLD "Copy and Replace done" RESET

#endif
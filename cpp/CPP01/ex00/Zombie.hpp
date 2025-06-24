/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:08:14 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/29 01:18:29 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


# define RED "\033[31m"
# define RESET "\033[0m"
# define ORANGE "\033[33m"
# define MAGENTA "\033[35m"

# define BRAIN "BraiiiiiiinnnzzzZ..."
# define DESTROY "Has been destroyed"

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	void setName(std::string newName)
	{
		_name = newName;
	}
	
	void announce(void);
	Zombie(void);
	~Zombie(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif

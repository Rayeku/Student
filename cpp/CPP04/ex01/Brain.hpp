/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:48:35 by rayeku            #+#    #+#             */
/*   Updated: 2024/09/23 23:44:06 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
  private:   
	std::string _ideas[100];

  public:
	Brain();
	Brain(const Brain &Brain);
	~Brain();
	Brain &operator=(const Brain &Brain);
	void changeIdeas(std::string newIdea);
	void copyIdeas(Brain &Brain);
	void printIdeas() const;
};

#endif
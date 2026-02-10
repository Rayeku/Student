/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 02:55:44 by rayeku            #+#    #+#             */
/*   Updated: 2026/02/10 14:15:25 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
# define VECTOR2_HPP

// Include(s)
# include <iostream>
# include <stdexcept>

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"

// Define(s)
# define ERRNEG BOLD RED "Values must be in range : 0 to 9" RESET

class Vector2
{
	private:
        std::pair<float, float> _point;
        
    public:
		Vector2();
        Vector2(float x, float y);
        float getX(void) const;
        float getY(void) const;  
        int getXPos(void) const; 
        int getYPos(void) const; 
};

std::ostream &operator<<(std::ostream &os, const Vector2 &p_vector2);

#endif
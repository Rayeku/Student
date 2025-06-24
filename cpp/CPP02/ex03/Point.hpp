/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:28:08 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/14 16:30:33 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
  private:
	Fixed const _x;
	Fixed const _y;

  public:
	Point();
	Point(const Point &copy);
	Point(const float x, const float y);
	Point &operator=(const Point &copy);

	float showX() const;
	float showY() const;
	~Point();

};

#endif

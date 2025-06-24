/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:12:56 by abougrai          #+#    #+#             */
/*   Updated: 2024/09/14 14:59:37 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _fixedPointValue;
	static const int _fractionalBits;

  public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &Fixed);
	~Fixed();
	
	Fixed &operator=(const Fixed &fixed);
	
	int operator>(Fixed fixed)const;
	int operator<(Fixed fixed)const;
	int operator>=(Fixed fixed)const;
	int operator<=(Fixed fixed)const;
	int operator==(Fixed fixed)const;
	int operator!=(Fixed fixed)const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	
	float operator+(Fixed fixed)const;
	float operator-(Fixed fixed)const;
	float operator*(Fixed fixed)const;
	float operator/(Fixed fixed)const;

	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(Fixed const &first, const Fixed &second);
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(Fixed const &first, Fixed const &second);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};
	std::ostream & operator<<(std::ostream& os, const Fixed& fixed);

#endif
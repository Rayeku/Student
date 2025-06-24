/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 07:56:58 by abougrai          #+#    #+#             */
/*   Updated: 2024/08/18 19:57:20 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
};
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return (*this);
};
Fixed::Fixed(const Fixed &fixed) : _fixedPointValue(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
};
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
};
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
};
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw << _fractionalBits;
	return ;
};

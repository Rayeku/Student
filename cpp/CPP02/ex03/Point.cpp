#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	return ;
}

Point::Point(const Point &copy)
{
	*this = copy;
	return ;
}

Point &Point::operator=(const Point &copy)
{
	const_cast<Fixed &>(this->_x) = copy.showX();
	const_cast<Fixed &>(this->_y) = copy.showY();
	return (*this);
}

Point::~Point()
{
	return ;
}

float Point::showX(void) const
{
	return (this->_x.toFloat());
}

float Point::showY(void) const
{
	return (this->_y.toFloat());
}

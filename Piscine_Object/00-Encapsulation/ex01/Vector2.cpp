#include "Vector2.hpp"

Vector2::Vector2(float x, float y) {
    if (x < 0 || y < 0)
        throw std::out_of_range(ERRNEG);
    this->_point.first = x;
    this->_point.second = y;
}

float Vector2::getX(void) const {return this->_point.first;}
float Vector2::getY(void) const  {return this->_point.second;}
int Vector2::getXPos(void) const  {return this->_point.first;}
int Vector2::getYPos(void) const  {return this->_point.second;}

std::ostream &operator<<(std::ostream &os, const Vector2 &p_vector2) {
    os << CYAN << "Vector2 informations :" << RESET << std::endl;
    os << ORANGE << "Value (X,Y) : " << RESET;
    os << "(" << p_vector2.getX() << ",";
    os << p_vector2.getY() << ")" << std::endl;
	return os;
}

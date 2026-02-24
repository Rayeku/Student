#include "Position.hpp"

Position::Position() : _x(0), _y(0), _z(0) {
    std::cout << CYAN << "Default Position Constructor Called" << RESET << std::endl;
}

Position::Position(int x, int y, int z) : _x(x), _y(y), _z(z) {
    std::cout << "Assignement Position Constructor Called" << RESET << std::endl;
}
Position::~Position() {
    std::cout << CYAN << "Default Position Destructor Called" << RESET << std::endl;
}

int Position::getXpos() const {return this->_x;}
int Position::getYpos() const {return this->_y;}
int Position::getZpos() const {return this->_z;}
void Position::setXpos(int pos) {this->_x = pos;}
void Position::setYpos(int pos) {this->_x = pos;}
void Position::setZpos(int pos) {this->_x = pos;}

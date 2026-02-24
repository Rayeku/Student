#include "Statistic.hpp"

Statistic::Statistic() : _level(1), _exp(0) {
    std::cout << CYAN << "Default Statistic Constructor Called" << RESET << std::endl;
}

Statistic::Statistic(int level, int exp) : _level(level), _exp(exp) {
    std::cout << "Assignement Statistic Constructor Called" << RESET << std::endl;
}

Statistic::~Statistic() {
    std::cout << CYAN << "Default Statistic Destructor Called" << RESET << std::endl;
}

int Statistic::getLevel() const {return this->_level;}
int Statistic::getExp() const {return this->_exp;}

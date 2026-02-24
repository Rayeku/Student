#include "Hammer.hpp"

Hammer::Hammer() {
    std::cout << BOLD ITALIC LIGHTBROWN << "Default Hammer Constructor Called" << RESET << std::endl;
    this->_type = "Hammer";
}

Hammer::~Hammer() {
    std::cout << BOLD ITALIC LIGHTBROWN << "Default Hammer Destructor Called" << RESET << std::endl;
}

void Hammer::use(void) {
    if (this->_numberOfUses <= 0) {
        std::cout << BOLD RED << "Current " << this->_type << " is unusable" << RESET << std::endl; 
        return;
    }
    std::cout << "Hi i'm a " << this->_type << std::endl;
    this->_numberOfUses--;
    if (this->_numberOfUses <= 0) {
        std::cout << BOLD RED << "Last used " << this->_type << " got broken" << std::endl;
        this->_owner->removeTool(this);
    }
}

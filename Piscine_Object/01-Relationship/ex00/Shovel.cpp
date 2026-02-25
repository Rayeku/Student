#include "Shovel.hpp"

Shovel::Shovel() {
    std::cout << BOLD ITALIC LIGHTBROWN << "Default Shovel Constructor Called" << RESET << std::endl;
    this->_type = "Shovel";
}

Shovel::~Shovel() {
    std::cout << BOLD ITALIC LIGHTBROWN << "Default Shovel Destructor Called" << RESET << std::endl;
}

void Shovel::use(void) {
    if (this->_numberOfUses <= 0) {
        std::cout << BOLD RED "ERROR : " << "Current " << this->_type << " is unusable" << RESET << std::endl; 
        return;
    }
    std::cout << BOLD PINK << this->_owner->getName() << " is using a " << this->_type << RESET << std::endl;
    this->_numberOfUses--;
    if (this->_numberOfUses <= 0) {
        std::cout << BOLD RED << "Last used " << this->_type << " got broken" << std::endl;
        this->_owner->removeTool(this);
        this->removeOwner();
    }
}


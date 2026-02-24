#include "Tool.hpp"

Tool::Tool() : _type("Tool"), _numberOfUses(5), _owner(NULL) {
    std::cout << BOLD ITALIC BROWN2 << "Default Tool Constructor Called" << RESET << std::endl;
}

Tool::~Tool() {
    std::cout << BOLD ITALIC BROWN2 << "Default Tool Destructor Called" << RESET << std::endl;
}

void Tool::setOwner(Worker *owner) {
    if (owner != NULL) {
        this->removeOwner();
        this->_owner = owner;
    }
    else {
        this->_owner = owner;
    }
}

void Tool::removeOwner(void) {
    if (this->gotOwner() == true) {
        this->_owner = NULL;
    }
}

bool Tool::gotOwner(void) {
    if (this->_owner == NULL)
        return false;
    return true;
}

Worker* Tool::getOwner(void) {return this->_owner;}
std::string Tool::getType(void) const {return this->_type;}
int Tool::getNumberOfUses(void) const {return this->_numberOfUses;}

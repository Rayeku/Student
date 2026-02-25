#include "Worker.hpp"

Worker::Worker() : _name("Aurel"), _coordonnee(), _stat(), _tool() {
    std::cout << BOLD ORANGE << "Default Worker Constructor Called" << RESET << std::endl;
}
Worker::Worker(std::string name, Position coord, Statistic stat, Tool *tool) : _name(name), _coordonnee(coord), _stat(stat), _tool() {
    std::cout << BOLD ORANGE << "Assignement Worker Constructor Called" << RESET << std::endl;
    if (tool != NULL && tool->_numberOfUses > 0) {
        this->_tool.push_back(tool);
        tool->_owner = this;
        std::cout << BOLD ITALIC GREEN << this->_name << " has one more " << tool->getType() << RESET << std::endl;
    }
    else if (tool->_numberOfUses < 0) {
        std::cout << BOLD RED "ERROR : " << "Current " << tool->_type << " is unusable" << RESET;
        return; 
    }
    else
        std::cout << BOLD RED "ERROR : " << "Something went wrong " << this->_name << " couldn't get his " << tool->_type << RESET << std::endl;
}

void Worker::setTool(Tool *tool) {
    if (tool->_numberOfUses <= 0) {
        std::cout << BOLD RED "ERROR : " << "Current " << tool->_type << " is unusable" << RESET << std::endl;
        return; 
    }

    if (tool != NULL && tool->getOwner() != this && tool->getOwner() != NULL)
        for (std::vector<Tool *>::iterator it = tool->_owner->_tool.begin();it != tool->_owner->_tool.end(); it++) {
            if (*it == tool) {
                tool->_owner->_tool.erase(it);
                std::cout << BOLD RED ITALIC << tool->_owner->_name << " got a " << tool->getType() << " removed" << RESET << endl;
                break;
            }
        }
        
    if (tool != NULL) {
        for (std::vector<Tool *>::iterator it = this->_tool.begin();it != this->_tool.end(); it++) {
            if (*it == tool) {
                std::cout << BOLD RED "ERROR : " << this->_name << " already have this specific " << tool->getType() << RESET << endl;
                return;
            }
        }
        this->_tool.push_back(tool);
        tool->setOwner(this);
        std::cout << BOLD ITALIC GREEN << this->_name << " has one more " << tool->getType() << RESET << std::endl;
        return;
    }
    std::cout << BOLD RED "ERROR : " << "Something went wrong " << this->_name << " couldn't get his tool" << RESET << std::endl; 
}

void Worker::removeTool(Tool *tool) {
    if (tool != NULL && tool->getOwner() == this) {
        for (std::vector<Tool *>::iterator it = this->_tool.begin();it != this->_tool.end(); it++) {
            if (*it == tool) {
                this->_tool.erase(it);
                std::cout << BOLD RED ITALIC << this->_name << " got a " << tool->getType() << " removed" << RESET << endl;
                return;
            }
        }
    }
    std::cout << BOLD RED "ERROR : " << "Something went wrong, couldn't remove a specific " << tool->getType() << " from " << this->_name << RESET << std::endl;
}

void Worker::useTool(Tool *tool) {
    if (tool->_owner != this)
        std::cout << BOLD RED "ERROR : " << this->_name << " can't use this " << tool->_type << RESET << std::endl;
    else if(tool->_owner == this)
        tool->use();
    else
        std::cout << BOLD RED "ERROR : " << "Something went wrong " << this->_name << " couldn't use the tool" << RESET << std::endl;
}

std::string Worker::getName(void) {
    return this->_name;
}

Tool* Worker::getTool(std::string type) {
    for (std::vector<Tool *>::iterator it = this->_tool.begin();it != this->_tool.end(); it++) {
        if ((*it)->getType() == type)
            return ((*it));
        }
    std::cout << BOLD RED "ERROR : " << "Something went wrong " << this->_name << " do not have any " << type << " tool" << RESET << std::endl;
    return NULL;
}

Worker::~Worker() {
    std::cout << BOLD ORANGE << "Default Worker Destructor Called" << RESET << std::endl;
    this->_tool.clear();
}

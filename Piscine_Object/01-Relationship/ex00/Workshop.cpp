#include "Workshop.hpp"

Workshop::Workshop() : _name("Default"), _workshop(), _workersRegistered(0) {
    std::cout << BOLD PURPLE << "Default Workshop Constructor Called" << RESET << std::endl;
}

Workshop::Workshop(std::string name) : _name(name), _workshop(), _workersRegistered(0) {
    std::cout << BOLD PURPLE << "Assignement Workshop Constructor Called" << RESET << std::endl;
}

Workshop::~Workshop() {
    std::cout << BOLD PURPLE << "Default Workshop Destructor Called" << RESET << std::endl;
}

bool Workshop::isWorkerRegistered(Worker *worker) {
    for (std::vector<Worker *>::iterator it = this->_workshop.begin(); it != this->_workshop.end(); it++) {
        if (*(it) == worker)
            return true;
    }
    return false;
}

void Workshop::registerWorker(Worker *worker) {
    if (worker != NULL) {
        if (this->isWorkerRegistered(worker) == true) {
            std::cout << RED BOLD << worker->getName() << " is already registered in " << this->_name << " workshop" << RESET << std::endl;
            return;
        }
        this->_workshop.push_back(worker);
        worker->_register++;
        this->_workersRegistered++;
        std::cout << GREEN BOLD << worker->getName() << " has registered in " << this->_name << " workshop" << RESET << std::endl;
    }
    else
        std::cout << BOLD RED "ERROR : " << "Something went wrong, a certain worker couldn't register in " << this->_name << " workshop" << RESET << std::endl;
}

void Workshop::releaseWorker(Worker *worker) {
    if (worker != NULL) {
        if (this->isWorkerRegistered(worker) == false) {
            std::cout << BOLD RED << worker->getName() << " is not registered in " << this->_name << " workshop" << RESET << std::endl;
            return;
        }

        for (std::vector<Worker *>::iterator it = this->_workshop.begin(); it != this->_workshop.end(); it++) {
            if ((*it) == worker) {
                this->_workshop.erase(it);
                worker->_register--;
                this->_workersRegistered--;
                std::cout << BOLD RED << worker->getName() << " has been released from " << this->_name << " workshop" << RESET << std::endl;
                return; 
            }
        }
    }
    std::cout << BOLD RED "ERROR : " << "Something went wrong, a certain worker couldn't being release of " << this->_name << " workshop" << RESET << std::endl;
}

void Workshop::executeWorkDay() {
    std::cout << BOLD PURPLE << this->_name << " working day :" << RESET << std::endl;
    if (this->_workersRegistered <= 0) {
        std::cout << BOLD RED << "No workers registered in this workshop" << RESET << std::endl;
    }
    for (std::vector<Worker *>::iterator it = this->_workshop.begin(); it != this->_workshop.end(); it++) {
        (*it)->work();
    }
}

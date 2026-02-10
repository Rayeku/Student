#include "Graph.hpp"

Graph::Graph(Vector2 size) : _size(size) {
    if (size.getX() < 0 || size.getY() < 0
        || size.getX() > 9 || size.getY() > 9)
    throw std::out_of_range(ERRNEG);
}

void Graph::addVector(Vector2 *point) {
    if (point->getX() > this->_size.getX() || point->getY() > this->_size.getY())
        throw std::out_of_range(ERRPOINT);
    this->_vecList.push_back(point);
}

bool Graph::pointFound(int x, int y) const {
    for (size_t i = 0; i < this->_vecList.size(); i++)
            if (this->_vecList[i]->getXPos() == x && this->_vecList[i]->getYPos() == y)
                return true;
    return false;
}

void Graph::showGraph(void) {
    for (int y = this->_size.getY(); y >= 0; y--) {
        std::cout << "& " << y << " ";
        for (int x = 0; x <= this->_size.getX(); x++) {
            if (this->pointFound(x, y) == true)
                std::cout << "X ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }

    std::cout << "&   ";
    for (int x = 0; x <= this->_size.getX(); x++)
        std::cout << x << " ";
    std::cout << std::endl;
}


std::ostream &operator<<(std::ostream &os, const Graph &p_graph){
    os << CYAN << "Graph informations :" << RESET << endl;
    os << BROWN << "Size : " << RESET;
    os << "(" << p_graph._size.getX() << ",";
    os << p_graph._size.getY() << ")" << std::endl;
    for (std::vector<Vector2 *>::const_iterator it = p_graph._vecList.begin();
            it != p_graph._vecList.end(); it++)
            os << *(*it) << endl;
    return os;
}
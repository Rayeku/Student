#ifndef GRAPH_HPP
# define GRAPH_HPP

// Include(s)
# include <vector>
# include "Vector2.hpp"

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"

// Define(s)
# define ERRPOINT BOLD RED "A certain point is out of bound of the graph" RESET

using namespace std;

class Graph
{
	private:
        std::vector<Vector2 *> _vecList;
        Vector2 _size;
        
    public:
        Graph(Vector2 size);
        void addVector(Vector2 *point);
        bool pointFound(int x, int y) const;
        void showGraph(void);
        friend std::ostream &operator<<(std::ostream &os, const Graph &p_graph);
};

#endif
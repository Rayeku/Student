#ifndef WORKER_HPP
# define WORKER_HPP

// Include(s)
# include <iostream>
# include <string>
# include <vector>
# include "Position.hpp"
# include "Statistic.hpp"
# include "Tool.hpp"

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define PINK "\033[38;5;200m"
# define BROWN "\033[38;5;94m"
# define BROWN2 "\033[38;5;130m"
# define ORANGE "\033[38;5;202m"
# define LIGHTBROWN "\033[38;5;180m"
using namespace std;

class Tool;

class Worker
{
    private:
        std::string _name;
        Position _coordonnee;
        Statistic _stat;
        std::vector<Tool *> _tool;

    public:
        Worker();
        Worker(std::string name, Position coord, Statistic stat, Tool *tool);
        void setTool(Tool *tool);
        void removeTool(Tool *tool);
        void useTool(Tool *tool);
        std::string getName(void);
        ~Worker();

        friend class Tool;
};

#endif

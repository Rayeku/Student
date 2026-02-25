#ifndef WORKER_HPP
# define WORKER_HPP

// Include(s)
# include <iostream>
# include <string>
# include <vector>
# include <ostream>
# include "Position.hpp"
# include "Statistic.hpp"
# include "Tool.hpp"
# include "Workshop.hpp"

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
class Workshop;

class Worker
{
    private:
        std::string _name;
        Position _coordonnee;
        Statistic _stat;
        std::vector<Tool *> _tool;
        int _register;
        void work();

    public:
        Worker();
        Worker(std::string name, Position coord, Statistic stat, Tool *tool);
        ~Worker();
        void setTool(Tool *tool);
        void removeTool(Tool *tool);
        void useTool(Tool *tool);
        std::string getName(void);
        Tool* getTool(std::string type);

        friend class Tool;
        friend class Workshop;
};

#endif

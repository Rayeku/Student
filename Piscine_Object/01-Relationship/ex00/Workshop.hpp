#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

// Include(s)
# include "Worker.hpp"

class Worker;

class Workshop
{
    private:
        std::string _name;
        std::vector<Worker *> _workshop;
        int _workersRegistered;
        bool isWorkerRegistered(Worker *worker);
    public:
        Workshop();
        Workshop(std::string name);
        ~Workshop();
        
        void registerWorker(Worker *worker);
        void releaseWorker(Worker *worker);
        void executeWorkDay();

};

#endif

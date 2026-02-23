#ifndef WORKER_HPP
# define WORKER_HPP

#include "Shovel.hpp"

struct Position
{
    int x;
    int y;
    int z;
};

struct Statistic
{
    int level;
    int exp;
};

class Worker
{
    private:
        Position _coordonnee;
        Statistic _stat;
        Shovel &_shovel;
    public:
        Worker();
        ~Worker();
};
    
Worker::Worker() {}
Worker::~Worker() {}

#endif
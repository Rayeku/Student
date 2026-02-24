#ifndef TOOL_HPP
# define TOOL_HPP

// Include(s)
# include "Worker.hpp"

class Worker;

class Tool
{
    protected:
        std::string _type;
        int _numberOfUses;
        Worker *_owner;

    public:
        Tool();
        virtual ~Tool() = 0;
        virtual void use() = 0;
        void setOwner(Worker *owner);
        void removeOwner(void);
        bool gotOwner(void);

        Worker *getOwner(void);
        std::string getType(void) const;
        int getNumberOfUses(void) const;

        friend class Worker;
};

#endif

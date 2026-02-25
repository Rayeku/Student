#ifndef HAMMER_HPP
# define HAMMER_HPP

// Include(s)
# include "Tool.hpp"

class Hammer : public Tool
{
    private:
        void use(void);

    public:
        Hammer();
        ~Hammer();
};

#endif

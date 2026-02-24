#ifndef SHOVEL_HPP
# define SHOVEL_HPP

// Include(s)
# include "Tool.hpp"

class Shovel : public Tool
{
    private:

    public:
        Shovel();
        ~Shovel();
        void use(void);
};

#endif

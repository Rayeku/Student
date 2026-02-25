#ifndef SHOVEL_HPP
# define SHOVEL_HPP

// Include(s)
# include "Tool.hpp"

class Shovel : public Tool
{
    private:
        void use(void);

    public:
        Shovel();
        ~Shovel();
};

#endif

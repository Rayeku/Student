#ifndef SHOVEL_HPP
# define SHOVEL_HPP

class Shovel
{
    private:
        int numberOfUses;
    public:
        void use(void);
        Shovel();
        ~Shovel();
};

Shovel::Shovel() {}
Shovel::~Shovel() {}

#endif
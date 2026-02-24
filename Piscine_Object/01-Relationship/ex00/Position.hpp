#ifndef POSITION_HPP
# define POSITION_HPP

// Include(s)
# include <iostream>

// Color(s)
# define RESET "\033[0m"
# define CYAN "\033[36m"

struct Position
{
    private:
        int _x;
        int _y;
        int _z;

    public:
        Position();
        Position(int x, int y, int z);
        ~Position();
        int getXpos() const;
        int getYpos() const;
        int getZpos() const;
        void setXpos(int pos);
        void setYpos(int pos);
        void setZpos(int pos);
};

#endif

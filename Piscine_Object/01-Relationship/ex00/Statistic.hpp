#ifndef STATISTIC_HPP
# define STATISTIC_HPP

// Include(s)
# include <iostream>

// Color(s)
# define RESET "\033[0m"
# define CYAN "\033[36m"

struct Statistic
{
    private:
        int _level;
        int _exp;

    public:
        Statistic();
        Statistic(int level, int exp);
        ~Statistic();
        int getLevel() const;
        int getExp() const;
};

#endif

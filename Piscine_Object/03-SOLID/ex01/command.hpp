#ifndef COMMAND_HPP
# define COMMAND_HPP

// Include(s)
# include <iostream>
# include <string>
# include <map>

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"
# define PURPLE "\033[38;5;175m"

using namespace std;

// Basic car class
class Command
{
    private:
        int _id;
        string _date;
        string _client;
        std::map<string, int> _articles;


    public:
        void get_total_price();
        void get_list_articles();

        Command();
        Command(int id, string date, string client, );
        ~Command();

};

Command::Command() {}
Command::~Command() {}

#endif

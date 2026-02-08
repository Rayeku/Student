#ifndef BANK_HPP
# define BANK_HPP

// Include(s)
# include <map>
# include <stdexcept>
# include "Account.hpp"

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"

// Define(s) 
# define ERRID RED BOLD "Wrong ID, account not found" RESET
# define ERRAMOUNT RED BOLD "Wrong amount of money, operation denied" RESET
# define ERRADD RED BOLD "Wrong amount of money, couldn't create an account" RESET
# define ERRBANK RED BOLD "Liquidity's bank is insufficient, operation denied" RESET
# define ERRCUSTOMER RED BOLD "Customer's funds are insufficient, operation denied" RESET

using namespace std;

class Bank
{
	private:
		double _liquidity;
		size_t _accountId;
		std::map<const size_t, Account *> _clientAccounts;
	
	public:
		Bank();
		~Bank();

		size_t addCustomer(double amount);
		void depositCustomer(size_t id, double amount);
		void loanCustomer(size_t id, double amount);
		void withdrawalCustomer(size_t id, double amount);
	
		double getLiquidity(void) const;
		Account* operator[](size_t id) const;
		friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank);
};

#endif
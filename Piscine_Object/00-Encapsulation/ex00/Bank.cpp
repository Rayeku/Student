#include "Bank.hpp"

// Constructor(s)
Bank::Bank() : _liquidity(0), _accountId(0), _clientAccounts() {}

// Deconstructor(s)
Bank::~Bank() {
    for (std::map<const size_t, Account *>::const_iterator it = this->_clientAccounts.begin();
            it != this->_clientAccounts.end(); it++)
        delete it->second;
    _clientAccounts.clear();
}

// Method(s)
size_t Bank::addCustomer(double amount) {
    if (amount < 0)
        throw std::out_of_range(ERRADD);
    double tax = amount * 0.05;
    this->_liquidity += tax;
    this->_clientAccounts[_accountId] = new Account();
    this->_clientAccounts[_accountId]->_id = _accountId;
    this->_clientAccounts[_accountId]->_value = amount - tax;
    return (_accountId++);
}

void Bank::depositCustomer(size_t id, double amount) {
    if (amount <= 0)
        throw std::out_of_range(ERRAMOUNT);
    Account *Customer = (*this)[id];
    double tax = amount * 0.05;
    Customer->_value += amount - tax;
    this->_liquidity += tax;
}

void Bank::loanCustomer(size_t id, double amount) {
    if (amount <= 0)
        throw std::out_of_range(ERRAMOUNT);
    Account *Customer = (*this)[id];
    if (amount > this->_liquidity)
        throw std::out_of_range(ERRBANK);
    double tax = amount * 0.05;
    Customer->_value += amount - tax;
    this->_liquidity += tax;
}

void Bank::withdrawalCustomer(size_t id, double amount) {
    if (amount <= 0)
        throw std::out_of_range(ERRAMOUNT);
    Account *Customer = (*this)[id];
    if (amount > Customer->_value)
        throw std::out_of_range(ERRCUSTOMER);
    Customer->_value -= amount;
}

double Bank::getLiquidity(void) const {return this->_liquidity;}

// Operator(s) Overload
Account* Bank::operator[](size_t id) const {
    std::map<const size_t, Account *>::const_iterator it = this->_clientAccounts.find(id);
    if (it != this->_clientAccounts.end())
        return it->second;
    else
        throw std::invalid_argument(ERRID);
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank) {
	p_os << CYAN << "Bank informations : " << RESET << std::endl;
	p_os << ORANGE << "Liquidity : " << RESET << p_bank.getLiquidity() << std::endl;
	for (std::map<const size_t, Account *>::const_iterator it = p_bank._clientAccounts.begin();
			it != p_bank._clientAccounts.end(); it++)
				p_os << *(it->second) << endl;
	return p_os;
}

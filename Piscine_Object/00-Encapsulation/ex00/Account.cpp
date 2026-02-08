#include "Account.hpp"

// Method(s)
size_t Account::getId(void) const { return this->_id; }
double Account::getValue(void) const { return (this->_value); }

// Operator(s) Overload
std::ostream &operator<<(std::ostream &p_os, const Account &p_account) {
    p_os << BROWN << "Account : " << RESET;
    p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
    return (p_os);
}
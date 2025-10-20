#include "Account.hpp"
#include <iostream>

//static variables shared by all objects, they must be defined outside the class.
int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

void	_displayTimestamp(void)
{

}

Account::Account(int initial_deposit)
	:_accountIndex(_nbAccounts),
	 _amount(initial_deposit),
	 _nbDeposits(0),
	 _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amout" << _amount
			<< ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amout" << _amount
			<< ";closed" << std::endl;
}

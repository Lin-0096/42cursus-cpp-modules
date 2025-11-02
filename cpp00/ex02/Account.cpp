#include "Account.hpp"
#include <iostream>
<<<<<<< HEAD

//static variables shared by all objects, they must be defined outside the class.
int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

void	_displayTimestamp(void)
{

=======
#include <chrono>
#include <iomanip> // for std::put_time

//static variables shared by all objects, they must be defined outside the class.
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}
int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "account:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";depsits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	auto now = std::chrono::system_clock::now(); //return time_point
	std::time_t t = std::chrono::system_clock::to_time_t(now); //convers time_point to time_t(since 1970, in seconds)
	std::cout << std::put_time(localtime(&t), "[%Y%m%d_%H%M%S] ");
>>>>>>> ef7cc9ffd7aea720a91d5f874afa336ba4699c59
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
<<<<<<< HEAD
=======

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
	}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount;
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal
	 			<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
		return true;
	}
	std::cout << "withdrawal:refused" << std::endl;
	return false;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

Account::Account(void)
	: _accountIndex(_nbAccounts++),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{}
>>>>>>> ef7cc9ffd7aea720a91d5f874afa336ba4699c59

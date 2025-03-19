/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:00:17 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/19 17:08:49 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <locale>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
    time_t rawtime;
    struct tm * timeinfo;
	
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    std::cout << "[" << (1900 + timeinfo->tm_year)
              << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << timeinfo->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << timeinfo->tm_hour
              << std::setw(2) << std::setfill('0') << timeinfo->tm_min
              << std::setw(2) << std::setfill('0') << timeinfo->tm_sec << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
		<< "account:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<<";withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created"
		<< std::endl;
}

Account::~Account() 
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed"
		<< std::endl;
}


void	Account::makeDeposit( int deposit )
{
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit
		<< ";amount:" << (this->_amount + deposit)
		<< ";nb_deposits:" << ++this->_nbDeposits
		<< std::endl;
	this->_amount += deposit;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;
	if (withdrawal > _amount)
	{
		std::cout  << ";withdrawal:refused" << std::endl;
		return (0);
	}
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return (1);
}
int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:59:01 by kyusulee          #+#    #+#             */
/*   Updated: 2024/08/16 19:04:18 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * @brief IMPLEMENTATION OF PRIVATE FUNCTIONS
 */
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/**
 * @brief 
 */
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:"		<< getNbAccounts()		<< ";";
	std::cout << "total:"			<< getTotalAmount()		<< ";";
	std::cout << "deposits:"		<< getNbDeposits()		<< ";";
	std::cout << "withdrawals:"		<< getNbWithdrawals()	<< "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_amount = initial_deposit;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:"			<< _accountIndex	<< ";";
	std::cout << "amount:"			<< _amount			<< ";";
	std::cout << "created"			<< "\n";
}

Account::~Account()
{
	_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:"			<< _accountIndex	<< ";";
	std::cout << "amount:"			<< _amount			<< ";";
	std::cout << "closed"			<< "\n";
}

/**
 * @brief IMPLEMENTATION OF PUBLIC FUNCTIONS
 */

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	std::cout << "index:"			<< _accountIndex	<< ";";
	std::cout << "p_amount:"		<< _amount			<< ";";
	std::cout << "deposit:"			<< deposit			<< ";";
	_amount += deposit;
	std::cout << "amount:"			<< _amount			<< ";";
	std::cout << "nb_deposits:"		<< _nbDeposits		<< "\n";
	_totalAmount += deposit;
	_totalNbDeposits ++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:"		<< _accountIndex	<< ";";
		std::cout << "p_amount:"	<< _amount			<< ";";
		std::cout << "withdrawal:"	<< "refused"		<< "\n";
		return (false);
	}
	_nbWithdrawals++;
	std::cout << "index:"			<< _accountIndex	<< ";";
	std::cout << "p_amount:"		<< _amount			<< ";";
	std::cout << "withdrawal:"		<< withdrawal		<< ";";
	_amount -= withdrawal;
	std::cout << "amount:" 			<< _amount			<< ";";
	std::cout << "nb_withdrawals:"	<< _nbWithdrawals	<< "\n";
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:"			<< _accountIndex	<< ";";
	std::cout << "amount:"			<< _amount			<< ";";
	std::cout << "deposits:"		<< _nbDeposits		<< ";";
	std::cout << "withdrawals:"		<< _nbWithdrawals	<< "\n";
}

void	Account::_displayTimestamp()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout<<"[" << (1900 + now->tm_year);

	std::cout.width(2);
	std::cout.fill('0');
	std::cout << (now->tm_mon + 1);

	std::cout.width(2);
	std::cout.fill('0');
	std::cout << now->tm_mday;

	std::cout << "_";

	std::cout.width(2);
	std::cout.fill('0');
	std::cout << now->tm_hour;

	std::cout.width(2);
	std::cout.fill('0');
	std::cout << now->tm_min;
	
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << now->tm_sec << "]";

	std::cout << " ";
}

/**
 * @brief Default Constructor
 * @detail Nothing To Do
 */
Account::Account( void )
{
	// Nothing To Do
}

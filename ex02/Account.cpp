/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:59:01 by kyusulee          #+#    #+#             */
/*   Updated: 2024/08/16 17:29:14 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/**
 * @brief IMPLEMENTATION OF PRIVATE FUNCTIONS
 */

static int	Account::getNbAccounts( void )
{
	return (Account._nbAccounts);
}

static int	Account::getTotalAmount( void )
{
	return (Account._totalAmount);
}

static int	Account::getNbDeposits( void )
{
	return (Account._totalNbDeposits);
}

static int	Account::getNbWithdrawals( void )
{
	return (Account._totalNbWithdrawals);
}

/**
 * @brief 
 */
static void	Account::displayAccountsInfos( void )
{

}

Account::Account( int initial_deposit )
{
	this->_totalNbDeposits = initial_deposit;
}

Account::~Account()
{
	Account._displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << "\n";
}

/**
 * @brief IMPLEMENTATION OF PUBLIC FUNCTIONS
 */

void	Account::makeDeposit( int deposit );
bool	Account::makeWithdrawal( int withdrawal );

int	Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:;" << _nbDeposits;
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << "\n";
}

static void	Account::_displayTimestamp()
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

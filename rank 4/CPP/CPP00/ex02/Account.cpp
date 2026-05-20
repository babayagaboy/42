/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:32:56 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/20 17:36:48 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	getNbAccounts( void ) {
	return (_nbAccounts);
}

int	getTotalAmount( void ) {
	return (_totalAmount);
}

int	getNbDeposits( void ) {
	return(_totalNbDeposits);
}

int	getNbWithdrawals( void ) {
	return(_totalNbWithdrawals);
}

void	displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account( int initial_deposit )
{
	this->amount = initial_deposit;

	_displayTimestamp();
	std::cout << this->_accountIndex << ";";
	std::cout << this->_amount << ";";
	std::cout << "created" << std::endl;
}
~Account( void )
{
	_displayTimestamp();
	std::cout << this->_accountIndex << ";";
	std::cout << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	makeDeposit( int deposit )
{
	;
}
bool	makeWithdrawal( int withdrawal )
{
	;
}
int		checkAmount( void )
{
	;
}
void	displayStatus( void )
{
	
}

void	_displayTimestamp( void )
{
	;
}

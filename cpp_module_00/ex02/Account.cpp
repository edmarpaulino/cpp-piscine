/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:55:39 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/19 21:28:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) :
_accountIndex(0),
_amount(initial_deposit),
_nbDeposits(1),
_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalNbDeposits++;
	this->_accountIndex = Account::_nbAccounts - 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;

	return;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;

	return;
}

void Account::makeDeposit(int deposit)
{
	// TODO
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	// TODO
	return true;
}

int Account::checkAmount(void) const
{
	// TODO
	return 1;
}

void Account::displayStatus(void) const
{
	// TODO
	return;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";" 
		<< "withdrawals:" << Account::_totalNbWithdrawals << ";"
		<< std::endl;
}

void Account::_displayTimestamp(void)
{
	std::cout << "[]";
	return;
}


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

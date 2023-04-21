/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:55:39 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/20 21:20:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :
_accountIndex(0),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
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
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";" 
		<< "withdrawals:" << Account::_totalNbWithdrawals << ";"
		<< std::endl;

	return;
}

void Account::makeDeposit(int deposit)
{
	Account::_totalAmount += deposit;
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
		
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	int p_amount = this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused"
			<< std::endl;

		return false;
	}
	
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex
		<< ";p_amout:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	
	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
		
	return;
}

void Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[16];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 16, "%Y%m%d_%I%M%S", timeinfo);
	
	std::cout << "[" << buffer << "] ";
	
	return;
}

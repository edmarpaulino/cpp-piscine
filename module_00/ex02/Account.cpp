/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:55:39 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/21 20:10:32 by edpaulin         ###   ########.fr       */
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
	t::_nbAccounts++;
	t::_totalAmount += initial_deposit;
	
	this->_accountIndex = t::_nbAccounts - 1;

	t::_displayTimestamp();
	
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created" << std::endl;

	return;
}

Account::Account(void) :
_accountIndex(0),
_amount(0),
_nbDeposits(0),
_nbWithdrawals(0)
{
	t::_nbAccounts++;
	
	this->_accountIndex = t::_nbAccounts - 1;
	
	t::_displayTimestamp();
	
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created" << std::endl;
		
	return;
}

Account::~Account(void)
{
	t::_displayTimestamp();
	
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;

	return;
}

int Account::getNbAccounts(void)
{
	return t::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return t::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return t::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return t::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	
	std::cout << "accounts:" << t::_nbAccounts
		<< ";total:" << t::_totalAmount
		<< ";deposits:" << t::_totalNbDeposits
		<< ";withdrawals:" << t::_totalNbWithdrawals
		<< std::endl;

	return;
}

void Account::makeDeposit(int deposit)
{
	t::_totalAmount += deposit;
	t::_totalNbDeposits++;
	
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	
	t::_displayTimestamp();
	
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
	int p_amount = this->_amount;
	
	t::_displayTimestamp();

	if (this->_amount - withdrawal <= 0)
	{
		std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused"
			<< std::endl;

		return false;
	}
	
	t::_totalAmount -= withdrawal;
	t::_totalNbWithdrawals++;
	
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
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
	t::_displayTimestamp();
	
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
	strftime(buffer, 16, "%Y%m%d_%H%M%S", timeinfo);
	
	std::cout << "[" << buffer << "] ";
	
	return;
}

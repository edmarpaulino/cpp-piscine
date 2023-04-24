/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:55:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/24 20:36:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void Harl::complain(std::string level)
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*methods[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*methods[i])();

			return;
		}
	}

	throw std::invalid_argument(
		"Invalid level entry. "
		"Enter a valid level: DEBUG, INFO, WARNING or ERROR."
	);

	return;
}

void Harl::debug(void)
{
	std::cout
		<< "DEBUG: "
		<< "I love having extra bacon for "
		<< "my 7XL-double-cheese-triple-pickle-special ketchup burger. "
		<< "I really do!"
		<< std::endl;

	return;
}

void Harl::info(void)
{
	std::cout
		<< "INFO: "
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!"
		<< std::endl;

	return;
}

void Harl::warning(void)
{
	std::cout
		<< "WARNING: "
		<< "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working "
		<< "here since last month."
		<< std::endl;

	return;
}

void Harl::error(void)
{
	std::cout
		<< "ERROR: "
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;

	return;
}

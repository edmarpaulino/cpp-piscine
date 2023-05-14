/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:17:07 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 19:24:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;

	return;
}

void HumanB::attack(void) const
{
	if (this->_weapon)
	{
		std::cout
			<< this->_name
			<< " attacks with their "
			<< this->_weapon->getType()
			<< std::endl;
	}
	else
	{
		std::cout
			<< this->_name
			<< " doesn't has a weapon to attack :("
			<< std::endl;
	}

	return;
}

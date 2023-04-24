/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:17:07 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/24 20:42:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;

	return;
}

void HumanB::attack(void) const
{
	std::cout
		<< this->_name
		<< " attacks with their "
		<< this->_weapon->getType()
		<< std::endl;
}

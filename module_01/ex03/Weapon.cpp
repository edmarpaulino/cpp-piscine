/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:59:54 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/24 20:42:51 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return;
}

Weapon::Weapon(std::string type): _type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

const std::string Weapon::getType(void) const
{
	return (const std::string)this->_type;
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;

	return;
}

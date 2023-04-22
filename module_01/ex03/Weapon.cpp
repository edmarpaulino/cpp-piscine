/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:59:54 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/22 17:19:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	return;
}

Weapon::Weapon(std::string type): _type(type)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

const std::string Weapon::getType() const
{
	return (const std::string)this->_type;
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;

	return;
}

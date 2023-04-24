/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:14:06 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/24 20:39:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return;
}

Zombie::Zombie(std::string name): _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " was destroyed" << std::endl;

	return;
}

void Zombie::setName(std::string name)
{
	this->_name = name;

	return;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

	return;
}

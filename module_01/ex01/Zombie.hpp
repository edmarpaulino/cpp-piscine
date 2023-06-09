/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:11:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 19:04:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void setName(std::string name);
		void announce(void) const;
	
	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif

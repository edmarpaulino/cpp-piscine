/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:57:00 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/13 21:10:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string getType(void) const;
		void setType(std::string newType);

	private:
		std::string _type;

};

#endif

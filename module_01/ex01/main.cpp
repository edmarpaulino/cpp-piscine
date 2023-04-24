/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:03:17 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/24 20:39:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 10;

	Zombie* horde = zombieHorde(hordeSize, "Ganado");

	for (int i = 0; i < hordeSize; i++)
	{
		horde[i].announce();
	}

	delete [] horde;

	return 0;
}


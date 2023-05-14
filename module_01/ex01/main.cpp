/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:03:17 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 19:09:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 10;

	Zombie* horde = zombieHorde(hordeSize, "Ganado");

	for (int zombieNb = 0; zombieNb < hordeSize; zombieNb++)
	{
		horde[zombieNb].announce();
	}

	delete [] horde;

	return 0;
}


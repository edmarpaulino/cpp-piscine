/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:53:00 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/24 20:34:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdexcept>

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
		{
			throw std::invalid_argument(
				"Invalid entry. "
				"Harl need one level entry: DEBUG, INFO, WARNING or ERROR."
			);
		}

		Harl harl;

		harl.complain(argv[1]);

		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;

		return 1;
	}
}

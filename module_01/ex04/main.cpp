/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:19:25 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 12:19:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#include "Replacer.hpp"

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 4)
		{
			throw std::invalid_argument("Invalid number of arguments");
		}

		std::string filename(argv[1]);
		std::string from(argv[2]);
		std::string to(argv[3]);

		Replacer::replaceFile(filename, from, to);

		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;

		return 1;
	}
}

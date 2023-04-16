/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:57:04 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/16 20:13:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string command;
	bool running = true;

	while (running)
	{
		std::cout << "Enter your command: ";
		std::getline(std::cin, command);

		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			std::cout << "searched" << std::endl;
		else if (command == "EXIT")
			running = false;
		else
			std::cout << "Please enter: ADD, SEARCH or EXIT" << std::endl;
	}

	return 0;
}

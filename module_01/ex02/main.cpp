/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:35:00 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 19:13:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string brain("HI THIS IS BRAIN");
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout
		<< "The memory address of the string variable: "
		<< &brain
		<< std::endl;
	std::cout
		<< "The memory address held by stringPTR: "
		<< stringPTR
		<< std::endl;
	std::cout
		<< "The memory address held by stringREF: "
		<< &stringREF
		<< std::endl;

	std::cout
		<< "The value of the string variable: "
		<< brain
		<< std::endl;
	std::cout
		<< "The value pointed to by stringPTR: "
		<< *stringPTR
		<< std::endl;
	std::cout
		<< "The value pointed to by stringREF: "
		<< stringREF
		<< std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:35:00 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/22 16:48:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain("HI THIS IS BRAIN");
	std::string* stringPtr = &brain;
	std::string& stringRef = brain;

	std::cout
		<< "The memory address of the string variable: "
		<< &brain
		<< std::endl;
	std::cout
		<< "The memory address held by stringPTR: "
		<< stringPtr
		<< std::endl;
	std::cout
		<< "The memory address held by stringREF: "
		<< &stringRef
		<< std::endl;

	std::cout
		<< "The value of the string variable: "
		<< brain
		<< std::endl;
	std::cout
		<< "The value pointed to by stringPTR: "
		<< *stringPtr
		<< std::endl;
	std::cout
		<< "The value pointed to by stringREF: "
		<< stringRef
		<< std::endl;

	return 0;
}

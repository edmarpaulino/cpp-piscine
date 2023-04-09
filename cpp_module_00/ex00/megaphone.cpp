/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:05:48 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/09 20:14:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

	for (int i = 1; argv[i] != NULL; i++) {
		std::string str(argv[i]);
		for (std::string::iterator it = str.begin(); it != str.end(); it++) {
			*it = toupper(*it);
		}
		std::cout << str << std::endl;
	}
	
	return 0;
}

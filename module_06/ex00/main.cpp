/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:13:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/16 22:45:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
// TODO - tests
int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./convert [input]" << std::endl;
    return 1;
  }

  ScalarConverter::convert(argv[1]);

  return 0;
}

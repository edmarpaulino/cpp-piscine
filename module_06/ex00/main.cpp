/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:13:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 17:18:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

#include "ScalarConverter.hpp"
#include "ScalarTest.hpp"

int main(int argc, char **argv) {
  if (argc != 2 || !(strlen(argv[1]) > 0)) {
    std::cout << "Usage: ./convert [input]" << std::endl;
    return 1;
  }

  if (!strcmp(argv[1], "--test") || !strcmp(argv[1], "-t")) {
    ScalarTest::runTests();
    return 0;
  }

  ScalarValues *sv = ScalarConverter::convert(argv[1]);

  std::cout << *sv;

  delete sv;

  return 0;
}

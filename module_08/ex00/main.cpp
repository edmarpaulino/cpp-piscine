/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:49:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/09/03 20:30:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

static void testNotFound(void);

int main(void) {
  testNotFound();
  return 0;
}

static void testNotFound(void) {
  {
    const std::string description = "Should return -1 if the first param is an empty container";
    const std::vector<int> vec;
    const ssize_t result = easyfind(vec,42);
    if (result == -1) {
      std::cout << "PASS";
    } else {
      std::cout << "FAIL";
    }
    std::cout << " - " << description << std::endl;
  }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:49:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/09/03 20:59:34 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

static void test(void);

int main(void) {
  test();
  return 0;
}

static void test(void) {
  {
    const std::string description = "Should throw an exception if the first param is an empty container";
    std::string testResult = "FAIL";
    const std::vector<int> vec;
    try {
      easyfind(vec,42);
    } catch (const std::exception &e) {
      testResult = "PASS";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
  {
    const std::string description = "Should throw an exception if the second param is not in the container";
    std::string testResult = "FAIL";
    std::vector<int> vec;
    for (int i = -10000; i < 10000; i++) {
      if (i == 42) continue;
      vec.push_back(i);
    }
    try {
      easyfind(vec,42);
    } catch (const std::exception &e) {
      testResult = "PASS";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
}


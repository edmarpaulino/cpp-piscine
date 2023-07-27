/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:36:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/27 13:18:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

int main(void) {
  Animal fox;
  Animal cat("Cat");
  Animal animal(cat);

  std::cout << fox << std::endl;
  std::cout << cat << std::endl;
  std::cout << animal << std::endl;

  animal = fox;

  std::cout << animal << std::endl;

  fox.makeSound();
  cat.makeSound();
  animal.makeSound();

  return 0;
}

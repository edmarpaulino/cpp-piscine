/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:14:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/16 18:55:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
  ClapTrap ct1("Josias");
  ClapTrap ct2("Pinoquio");

  ct1.setAttackDamage(2);
  ct2.setAttackDamage(1);

  ClapTrap ct3(ct1);
  
  std::cout << std::endl;
  std::cout << ct1 << std::endl;
  std::cout << ct2 << std::endl;
  std::cout << ct3 << std::endl;

  ct1.attack(ct2.getName());
  ct2.takeDamage(ct1.getAttackDamage());
  ct2.attack(ct1.getName());
  ct1.takeDamage(ct2.getAttackDamage());
  ct2.beRepaired(2);
  ct2.beRepaired(1);

  std::cout << std::endl;
  std::cout << ct1 << std::endl;
  std::cout << ct2 << std::endl;

  ct1.setAttackDamage(9);
  ct1.attack(ct2.getName());
  ct2.takeDamage(ct1.getAttackDamage());
  for (int i = 0; i < 9; i++) {
    ct2.beRepaired(1);
  }
  ct2.attack(ct1.getName());
  
  ct1.setAttackDamage(100);

  std::cout << std::endl;
  std::cout << ct1 << std::endl;
  std::cout << ct2 << std::endl;

  ct1.attack(ct2.getName());
  ct2.takeDamage(ct1.getAttackDamage());
  ct1.attack(ct2.getName());
  ct2.takeDamage(ct1.getAttackDamage());
  ct2.beRepaired(2);
  ct2.attack(ct1.getName());

  std::cout << std::endl;
  std::cout << ct1 << std::endl;
  std::cout << ct2 << std::endl;

  ct2 = ct1;

  std::cout << std::endl;
  std::cout << ct1 << std::endl;
  std::cout << ct2 << std::endl;

  return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:14:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/25 13:02:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap ct("Josias");
  ScavTrap st("Pinoquio");

  std::cout << ct.getName() << " is " << ct.whoItIs() << std::endl;
  std::cout << st.getName() << " is " << st.whoItIs() << std::endl;

  ct.attack("Pinoquio");
  st.takeDamage(ct.getAttackDamage());
  st.attack("Josias");
  ct.takeDamage(st.getAttackDamage());
  st.beRepaired(10);
  st.guardGate();

  std::cout << std::endl;
  std::cout << ct << std::endl;
  std::cout << st << std::endl;

  ScavTrap st2;

  for (int i = 0; i < 6; i++) {
    st2.attack("Pinoquio");
    st.takeDamage(st2.getAttackDamage());
  }

  st.guardGate();

  std::cout << std::endl;
  std::cout << st << std::endl;
  std::cout << st2 << std::endl;

  return 0;
}

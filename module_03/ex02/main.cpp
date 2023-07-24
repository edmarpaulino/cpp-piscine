/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:14:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/24 18:57:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
  ClapTrap ct("Josias");
  ScavTrap st("Pinoquio");
  FragTrap ft("Galerito");

  std::cout << ct.getName() << " is " << ct.whoItIs() << std::endl;
  std::cout << st.getName() << " is " << st.whoItIs() << std::endl;
  std::cout << ft.getName() << " is " << ft.whoItIs() << std::endl;

  std::cout << std::endl;

  std::cout << ct << std::endl;
  std::cout << st << std::endl;
  std::cout << ft << std::endl;

  ct.attack("Pinoquio");
  st.takeDamage(ct.getAttackDamage());
  st.attack("Galerito");
  ft.takeDamage(st.getAttackDamage());
  ft.attack("Josias");
  ct.takeDamage(ft.getAttackDamage());

  ct.beRepaired(10);
  st.beRepaired(10);
  ft.beRepaired(10);

  st.guardGate();
  ft.highFivesGuys();

  return 0;
}

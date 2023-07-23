/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:14:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/23 19:38:51 by edpaulin         ###   ########.fr       */
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

  return 0;
}

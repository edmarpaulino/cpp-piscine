/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:47:44 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/24 18:58:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
  std::cout << "FragTrap default constructor called!" << std::endl;
  this->_name = "FragTrap";
  this->_whoItIs = "FragTrap";
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
  std::cout << "FragTrap string constructor called!" << std::endl;
  this->_name = name;
  this->_whoItIs = "FragTrap";
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &rhs): ClapTrap(rhs) {
  std::cout << "FragTrap copy constructor called!" << std::endl;
  *this = rhs;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  std::cout << "FragTrap copy assignment operator called!" << std::endl;
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout
    << "FragTrap " << this->_name
    << " asks for a high five!" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const FragTrap &rhs) {
  o << "FragTrap" << std::endl
    << "Name: " << rhs.getName() << std::endl
    << "Hit Points: " << rhs.getHitPoints() << std::endl
    << "Energy Points: " << rhs.getEnergyPoints() << std::endl
    << "Attack Damage: " << rhs.getAttackDamage() << std::endl;
  return o;
}

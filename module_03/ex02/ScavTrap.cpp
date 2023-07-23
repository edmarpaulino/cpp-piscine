/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:59:36 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/23 19:38:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
  std::cout << "ScavTrap default constructor called!" << std::endl;
  this->_name = "ScavTrap";
  this->_whoItIs = "ScavTrap";
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
  std::cout << "ScavTrap string constructor called!" << std::endl;
  this->_name = name;
  this->_whoItIs = "ScavTrap";
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &rhs): ClapTrap(rhs) {
  std::cout << "ScavTrap copy constructor called!" << std::endl;
  *this = rhs;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap destructor called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  std::cout << "ScavTrap copy assignment operator called!" << std::endl;
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (this->isDead()) {
    std::cout
      << "ScavTrap " << this->_name
      << " cannot attack " << target
      << ", because it is resting in peace!" << std::endl;
  } else if (!this->hasEnergy()) {
    std::cout
      << "ScavTrap " << this->_name
      << " cannot attack " << target
      << ", because it has no motivation!" << std::endl;
  } else {
    std::cout
      << "ScavTrap " << this->_name
      << " fiercely attacks " << target
      << ", causing " << this->_attackDamage
      << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
}

void ScavTrap::guardGate(void) {
  if (this->isDead()) {
    std::cout
      << "ScavTrap "
      << this->_name
      << " cannot enter in gate keeper mode because it is dead!"
      << std::endl;
  } else if (!this->hasEnergy()) {
    std::cout
      << "ScavTrap "
      << this->_name
      << " cannot enter in gate keeper mode because it has no energy points!"
      << std::endl;
  } else {
    std::cout
      << "ScavTrap "
      << this->_name
      << " is now in gate keeper mode."
      << std::endl;
  }
}

std::ostream &operator<<(std::ostream &o, const ScavTrap &rhs) {
  o << "ScavTrap" << std::endl
    << "Name: " << rhs.getName() << std::endl
    << "Hit Points: " << rhs.getHitPoints() << std::endl
    << "Energy Points: " << rhs.getEnergyPoints() << std::endl
    << "Attack Damage: " << rhs.getAttackDamage() << std::endl;

  return o;
}

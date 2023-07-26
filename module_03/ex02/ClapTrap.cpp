/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:39:15 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/24 21:12:29 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
  std::cout << "ClapTrap default constructor called!" << std::endl;
  this->_name = "ClapTrap";
  this->_whoItIs = "ClapTrap";
  this->_hitPoints = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
  std::cout << "ClapTrap string constructor called!" << std::endl;
  this->_name = name;
  this->_whoItIs = "ClapTrap";
  this->_hitPoints = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) {
  std::cout << "ClapTrap copy constructor called!" << std::endl;
  *this = rhs;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap destructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  std::cout << "ClapTrap copy assignment operator called!" << std::endl;
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return *this;
}

std::string ClapTrap::getName(void) const {
  return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const {
  return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
  return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
  return this->_attackDamage;
}

void ClapTrap::setName(std::string name) {
  this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
  this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
  this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
  this->_attackDamage = attackDamage;
}

bool ClapTrap::isDead(void) const {
  return this->_hitPoints == 0;
}

bool ClapTrap::hasEnergy(void) const {
  return this->_energyPoints > 0;
}

std::string ClapTrap::whoItIs(void) const {
  return this->_whoItIs;
}

void ClapTrap::attack(const std::string &target) {
  if (this->isDead()) {
    std::cout
      << "ClapTrap " << this->_name
      << " cannot attack " << target
      << ", because it is dead!" << std::endl;
  } else if (!this->hasEnergy()) {
    std::cout
      << "ClapTrap " << this->_name
      << " cannot attack " << target
      << ", because it has no energy points!" << std::endl;
  } else {
    std::cout
      << "ClapTrap " << this->_name
      << " attacks " << target
      << ", causing " << this->_attackDamage
      << " points of damage!" << std::endl;
    this->_energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->isDead()) {
    std::cout
      << "ClapTrap " << this->_name
      << " cannot take more damage because it is dead!"
      << std::endl;
  } else {
    std::cout
      << "ClapTrap " << this->_name
      << " take " << amount
      << " points of damage!" << std::endl;

    if (this->_hitPoints > amount) {
      this->_hitPoints -= amount;
    } else {
      this->_hitPoints = 0;
    }

    if (this->isDead()) {
      std::cout
        << "ClapTrap " << this->_name
        << " died!" << std::endl;
    }
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->isDead()) {
    std::cout
      << "ClapTrap "
      << this->_name
      << " cannot be repaired because it is dead!"
      << std::endl;
  } else if (!this->hasEnergy()) {
    std::cout
      << "ClapTrap "
      << this->_name
      << " cannot be repaired because it has no energy points!"
      << std::endl;
  } else if (this->_hitPoints == 10) {
    std::cout
      << "ClapTrap "
      << this->_name
      << " don't neet repair because its hit points is full!"
      << std::endl;
  } else {
    std::cout
      << "ClapTrap " << this->_name
      << " repaired " << amount
      << " hit points!" << std::endl;

    this->_hitPoints += amount;
    this->_energyPoints--;
  }
}

std::ostream &operator<<(std::ostream &o, const ClapTrap &rhs) {
  o << "ClapTrap" << std::endl
    << "Name: " << rhs.getName() << std::endl
    << "Hit Points: " << rhs.getHitPoints() << std::endl
    << "Energy Points: " << rhs.getEnergyPoints() << std::endl
    << "Attack Damage: " << rhs.getAttackDamage() << std::endl;

  return o;
}

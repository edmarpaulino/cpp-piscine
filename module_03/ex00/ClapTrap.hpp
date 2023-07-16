/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:39:17 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/16 17:22:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <string>

class ClapTrap {
public:
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &rhs);
  ~ClapTrap(void);

  ClapTrap &operator=(const ClapTrap &rhs);

  std::string getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDamage(void) const;

  void setName(std::string name);
  void setHitPoints(unsigned int hitPoints);
  void setEnergyPoints(unsigned int energyPoints);
  void setAttackDamage(unsigned int attackDamage);

  bool isDead(void) const;
  bool hasEnergy(void) const;

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &o, const ClapTrap &rhs);

#endif // CLAP_TRAP_H

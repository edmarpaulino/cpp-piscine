/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:59:33 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/19 20:39:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
  ScavTrap(void);
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &rhs);
  ~ScavTrap(void);

  ScavTrap &operator=(const ScavTrap &rhs);

  void attack(const std::string &target);
  void guardGate(void);
};

std::ostream &operator<<(std::ostream &o, const ScavTrap &rhs);

#endif // SCAV_TRAP_H

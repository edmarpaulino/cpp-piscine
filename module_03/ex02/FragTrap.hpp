/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:42:14 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/24 18:53:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
public:
  FragTrap(void);
  FragTrap(std::string name);
  FragTrap(const FragTrap &rhs);
  ~FragTrap(void);

  FragTrap &operator=(const FragTrap &rhs);

  void highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &o, const FragTrap &rhs);

#endif // FRAG_TRAP_H

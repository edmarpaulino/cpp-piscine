/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:01:36 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 11:13:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Derived.hpp"

Base *generate(void) {
  std::srand(std::time(0));
  int option = std::rand() % 3;

  switch (option) {
    case 0:
      return new A;
    case 1:
      return new B;
    case 2:
      // fallthrough
    default:
      return new C;
  }
}

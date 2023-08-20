/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:02:08 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 18:05:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Derived.hpp"

void identify(Base *p) {
  Base *a = dynamic_cast<A *>(p);
  Base *b = dynamic_cast<B *>(p);
  Base *c = dynamic_cast<C *>(p);
  std::string type("Unknown");

  if (a != NULL) {
    type = "A";
  } else if (b != NULL) {
    type = "B";
  } else if (c != NULL) {
    type = "C";
  }

  std::cout << "👉 Pointer type: " << type << std::endl;
}

void identify(Base &p) {
  std::string type("Unknown");
  
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    type = "A";
  } catch (std::exception &e) {}
  
  try {
    if (type != "Unknown") throw std::exception();
    B &b = dynamic_cast<B &>(p);
    (void)b;
    type = "B";
  } catch (std::exception &e) {}

  try {
    if (type != "Unknown") throw std::exception();
    C &c = dynamic_cast<C &>(p);
    (void)c;
    type = "C";
  } catch (std::exception &e) {}

  std::cout << "🫵  Reference type: " << type << std::endl;
}

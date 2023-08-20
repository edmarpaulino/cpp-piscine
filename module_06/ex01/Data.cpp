/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:26:56 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 10:42:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): _content("") {}

Data::Data(std::string content): _content(content) {}

Data::Data(const Data &rhs) {
  *this = rhs;
}

Data::~Data(void) {}

Data &Data::operator=(const Data &rhs) {
  if (this != &rhs) {
    _content = rhs._content;
  }
  
  return (*this);
}

std::string Data::getContent(void) const {
  return _content;
}

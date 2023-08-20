/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarValues.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:58:28 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 17:10:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARVALUES_HPP
#define SCALARVALUES_HPP

#include <string>
#include <iostream>

#define IMP "impossible"

class ScalarValues {
public:
  ScalarValues(void);
  ScalarValues(std::string c, std::string i, std::string f, std::string d);
  ScalarValues(const ScalarValues &rhs);
  ~ScalarValues(void);

  ScalarValues &operator=(const ScalarValues &rhs);
  bool operator==(const ScalarValues &rhs);

  std::string getValueChar(void) const;
  std::string getValueInt(void) const;
  std::string getValueFloat(void) const;
  std::string getValueDouble(void) const;

private:
  std::string _c;
  std::string _i;
  std::string _f;
  std::string _d;
};

std::ostream &operator<<(std::ostream &out, const ScalarValues &rhs);

#endif /* SCALARVALUES_HPP */

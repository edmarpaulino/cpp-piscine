/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:54:20 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/30 19:36:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <iomanip>
#include <string>

#define IDEAS_SIZE 100

class Brain {
public:
  Brain(void);
  Brain(const Brain &rhs);
  ~Brain(void);

  Brain &operator=(const Brain &rhs);

  std::string getIdea(const unsigned int index) const;
  void setIdea(const unsigned int index, std::string idea);

private:
  std::string _ideas[IDEAS_SIZE];
};

std::ostream &operator<<(std::ostream &o, const Brain &rhs);

#endif /* BRAIN_HPP */

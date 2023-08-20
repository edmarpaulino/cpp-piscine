/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:26:11 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/20 10:38:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
public:
  Data(void);
  Data(std::string content);
  Data(const Data &rhs);
  ~Data(void);

  Data &operator=(const Data &rhs);

  std::string getContent(void) const;

private:
  std::string _content;
};

#endif /* DATA_HPP */

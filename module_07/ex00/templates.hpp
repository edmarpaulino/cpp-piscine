/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:21:23 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/21 21:33:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename T>
void swap(T &a, T &b) {
  T aux = a;
  a = b;
  b = aux;
}

template <typename T>
T min(T a, T b) {
  return (a < b ? a : b);
}

template <typename T>
T max(T a, T b) {
  return (a > b ? a : b);
}

#endif /* TEMPLATES_HPP */

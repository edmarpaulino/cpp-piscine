/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:00:48 by edpaulin          #+#    #+#             */
/*   Updated: 2023/08/22 21:03:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
public:
  Array(void): _arr(new T[0]), _size(0) {};
  
  Array(unsigned int n): _arr(new T[n]), _size(n) {
    for (unsigned int i = 0; i < _size; i++) {
      _arr[i] = T();
    }
  };
  
  Array(Array const &rhs): _arr(new T[rhs._size]), _size(rhs._size) { *this = rhs; };
  
  ~Array(void) { delete [] _arr; };

  Array &operator=(Array const &rhs) {
    if (this != &rhs) {
      delete [] _arr;
      _arr = new T[rhs._size];
      _size = rhs._size;
      for (unsigned int i = 0; i < _size; i++)
        _arr[i] = rhs._arr[i];
    }

    return *this;
  };

  T &operator[](unsigned int i) const {
    if (i >= _size) throw OutOfBoundsException();
    
    return _arr[i];
  };

  class OutOfBoundsException: public std::exception {
    virtual const char *what() const throw() {
      return "Error: index out of bounds";
    };
  };

  unsigned int size(void) const { return _size; };

private:
  T *_arr;
  unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &rhs) {
  out << "{ ";

  for (unsigned int i = 0; i < rhs.size(); i++) {
    out << rhs[i];
    if (i != rhs.size() - 1) {
      out << ", ";
    }
  }

  out << " }";

  return out;
}

#endif

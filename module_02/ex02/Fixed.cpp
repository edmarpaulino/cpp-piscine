/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:30:57 by edpaulin          #+#    #+#             */
/*   Updated: 2023/07/25 21:29:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _rawBits(0) {}

Fixed::Fixed(const int raw) {
	this->_rawBits = raw << this->_nbFractBits;
}

Fixed::Fixed(const float raw) {
	this->_rawBits = roundf(raw * (1 << this->_nbFractBits));
}

Fixed::Fixed(const Fixed &rhs) {
	*this = rhs;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {}

//  The 6 comparison operators:

bool Fixed::operator>(const Fixed &rhs) const {
  return this->_rawBits > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
  return this->_rawBits < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
  return this->_rawBits >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
  return this->_rawBits <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
  return this->_rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
  return this->_rawBits != rhs.getRawBits();
}

//  The 4 arithmetic operators:

Fixed Fixed::operator+(const Fixed &rhs) const {
  Fixed f;
  f.setRawBits(this->_rawBits + rhs.getRawBits());
  return f;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  Fixed f;
  f.setRawBits(this->_rawBits - rhs.getRawBits());
  return f;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  Fixed f;
  f.setRawBits((this->_rawBits * rhs.getRawBits()) >> this->_nbFractBits);
  return f;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  Fixed f;
  f.setRawBits((this->_rawBits << this->_nbFractBits) / rhs.getRawBits());
  return f;
}

//  The 4 increment/decrement:

Fixed &Fixed::operator++(void) {
  ++this->_rawBits;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed f = *this;
  this->_rawBits++;
  return f;
}

Fixed &Fixed::operator--(void) {
  --this->_rawBits;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed f = *this;
  this->_rawBits--;
  return f;
}

// methods

int Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

int Fixed::toInt(void) const {
	return this->_rawBits >> this->_nbFractBits;
}

float Fixed::toFloat(void) const {
	return (float)this->_rawBits / (1 << this->_nbFractBits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs) {
	o << rhs.toFloat();
	return o;
}

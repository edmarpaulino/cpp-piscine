/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/17 19:22:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):	_index(0), _length(0)
{
	this->_clearFields();
	
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::add(void)
{
	this->_requestAllFields();

	if (std::cin.eof())
	{
		return;
	}
	
	this->_index < MAX_CONTACTS 
	? this->_createNewContact() 
	: this->_updateLastContact();

	this->_clearFields();
	// this->_printAllContacts();

	return;
}

void PhoneBook::_requestAllFields(void)
{
	std::string fields[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};

	for (int i = 0; i < 5; i++)
	{
		this->_requestField(fields[i], this->_firstName);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
	}

	return;
}

void PhoneBook::_requestField(std::string field, std::string &fieldStorage)
{
	std::cout << "Enter " << field << ": ";
	std::getline(std::cin, fieldStorage);

	while (fieldStorage.empty() && !std::cin.eof())
	{
		std::cout
			<< "The fieldStorage '"
			<< field <<
			"' cannot be empty... Enter a value: ";
		std::getline(std::cin, fieldStorage);
	}

	return;
}

void PhoneBook::_createNewContact(void)
{
	Contact contact;

	contact.setFirstName(this->_firstName);
	contact.setLastName(this->_lastName);
	contact.setNickname(this->_nickname);
	contact.setPhoneNumber(this->_phoneNumber);
	contact.setDarkestSecret(this->_darkestSecret);

	this->_contacts[this->_index] = contact;
	this->_index++;
	this->_length++;

	return;
}

void PhoneBook::_updateLastContact(void)
{
	this->_contacts[LAST].setFirstName(this->_firstName);
	this->_contacts[LAST].setLastName(this->_lastName);
	this->_contacts[LAST].setNickname(this->_nickname);
	this->_contacts[LAST].setPhoneNumber(this->_phoneNumber);
	this->_contacts[LAST].setDarkestSecret(this->_darkestSecret);

	return;
}

void PhoneBook::_printAllContacts(void) const
{
	for (int i = 0; i < this->_length; i++)
	{
		this->_contacts[i].print();
		std::cout << std::endl << std::endl;
	}

	return;
}

void PhoneBook::_clearFields(void)
{
	this->_firstName.clear();
	this->_lastName.clear();
	this->_nickname.clear();
	this->_phoneNumber.clear();
	this->_darkestSecret.clear();

	return;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/16 20:13:31 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):	_index(0)
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
	
	this->_index < MAX_CONTACTS 
	? this->_createNewContact() 
	: this->_updateLastContact();

	this->_clearFields();
	this->_printAllContacts();

	return;
}

void PhoneBook::_requestAllFields(void)
{
	this->_requestField("first name", this->_firstName);
	this->_requestField("last name", this->_lastName);
	this->_requestField("nickname", this->_nickname);
	this->_requestField("phone number", this->_phoneNumber);
	this->_requestField("darkest secret", this->_darkestSecret);
}

void PhoneBook::_requestField(std::string prompt, std::string &field)
{
	std::cout << "Enter " << prompt << ": ";
	std::getline(std::cin, field);
	
	return;
}

void PhoneBook::_createNewContact(void)
{
	Contact contact;

	std::cout << "Create new contact" << std::endl;
	contact.setFirstName(this->_firstName);
	contact.setLastName(this->_lastName);
	contact.setNickname(this->_nickname);
	contact.setPhoneNumber(this->_phoneNumber);
	contact.setDarkestSecret(this->_darkestSecret);

	this->_contacts[this->_index] = contact;
	this->_index++;

	return;
}

void PhoneBook::_updateLastContact(void)
{
	std::cout << "Update last contact" << std::endl;
	this->_contacts[LAST].setFirstName(this->_firstName);
	this->_contacts[LAST].setLastName(this->_lastName);
	this->_contacts[LAST].setNickname(this->_nickname);
	this->_contacts[LAST].setPhoneNumber(this->_phoneNumber);
	this->_contacts[LAST].setDarkestSecret(this->_darkestSecret);

	return;
}

void PhoneBook::_printAllContacts(void) const
{
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "First name: " << this->_contacts[i].getFirstName() << std::endl;
		std::cout << "Last name: " << this->_contacts[i].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[i].getNickname() << std::endl;
		std::cout << "Phone number: " << this->_contacts[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->_contacts[i].getDarkestSecret() << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
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
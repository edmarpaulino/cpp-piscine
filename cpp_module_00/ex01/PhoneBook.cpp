/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:47 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/18 21:28:17 by edpaulin         ###   ########.fr       */
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

	return;
}

void PhoneBook::search(void) const
{
	this->_printSearch();

	std::string searchIndex;
	std::cout << "Enter the search index: ";
	std::getline(std::cin, searchIndex);
	
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return;
	}

	int index = this->_validateSearchIndex(searchIndex);

	if (index == -1)
	{
		std::cout << "Invalid index. Search again." << std::endl;
		return;
	}

	std::cout << std::endl;
	this->_contacts[index].print();
	std::cout << std::endl;

	return;
}

void PhoneBook::_requestAllFields(void)
{
	this->_requestField("first name", this->_firstName);
	this->_requestField("last name", this->_lastName);
	this->_requestField("nickname", this->_nickname);
	this->_requestField("phone number", this->_phoneNumber);
	this->_requestField("darkest secret", this->_darkestSecret);

	if (std::cin.eof())
	{
		std::cout << std::endl;
		return;
	}

	return;
}

void PhoneBook::_requestField(std::string field, std::string& fieldStorage)
{
	if (std::cin.eof())
	{
		return;
	}

	std::cout << "Enter " << field << ": ";
	std::getline(std::cin, fieldStorage);

	// TODO: Validate fields
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

void PhoneBook::_printSearch(void) const
{
	this->_printHeader();
	for (int i = 0; i < this->_length; i++)
	{
		this->_printRow(i);
	}
	this->_printFooter();

	return;
}

void PhoneBook::_printHeader(void) const
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	return;
}

void PhoneBook::_printRow(int index) const
{
	std::string firstName(this->_contacts[index].getFirstName());
	std::string lastName(this->_contacts[index].getLastName());
	std::string nickname(this->_contacts[index].getNickname());

	this->_truncateString(firstName);
	this->_truncateString(lastName);
	this->_truncateString(nickname);
 
	std::cout << "|";
	std::cout << std::setfill(SPACE) << std::setw(WIDTH);
	std::cout << index;
	std::cout << "|";
	std::cout << std::setfill(SPACE) << std::setw(WIDTH);
	std::cout << firstName;
	std::cout << "|";
	std::cout << std::setfill(SPACE) << std::setw(WIDTH);
	std::cout << lastName;
	std::cout << "|";
	std::cout << std::setfill(SPACE) << std::setw(WIDTH);
	std::cout << nickname;
	std::cout << "|" << std::endl;

	return;
}

void PhoneBook::_printFooter(void) const
{
	std::cout << "---------------------------------------------" << std::endl;

	return;
}

void PhoneBook::_truncateString(std::string& str) const
{
	if (str.length() > WIDTH)
	{
		str.resize(WIDTH);
		str[WIDTH - 1] = '.';
	}
}

int PhoneBook::_validateSearchIndex(std::string searchIndex) const
{
	if (searchIndex.length() != 1 || !std::isdigit(*searchIndex.begin()))
	{
		return -1;
	}

	int index = std::atoi(searchIndex.c_str());

	if (index < 0 || index > this->_length - 1)
	{
		return -1;
	}

	return index;
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

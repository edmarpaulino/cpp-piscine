/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:36:38 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/23 19:35:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReader.hpp"

FileReader::FileReader(std::string filename)
{
	this->_file.open(filename.c_str());

	if (!this->_file.is_open())
	{
		throw std::runtime_error("File not found");
	}

	return;
}

FileReader::~FileReader()
{
	this->_file.close();

	return;
}

std::string FileReader::read()
{
	std::stringstream ss;
	ss << this->_file.rdbuf();

	return ss.str();
}

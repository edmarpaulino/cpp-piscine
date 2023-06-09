/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:17:12 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 11:57:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileWriter.hpp"

FileWriter::FileWriter(std::string filename)
{
	this->_file.open(filename.c_str());

	if (!this->_file.is_open())
	{
		throw std::runtime_error("Unable to open " + filename + ".");
	}

	return;
}

FileWriter::~FileWriter(void)
{
	this->_file.close();

	return;
}

void FileWriter::write(std::string content)
{
	this->_file << content;

	return;
}

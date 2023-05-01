/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:14:27 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 13:13:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <string>
#include <fstream>
#include <sstream>
#include <exception>

class FileWriter
{
public:
	FileWriter(std::string filename);
	~FileWriter(void);

	void write(std::string content);

private:
	std::ofstream _file;
};

#endif

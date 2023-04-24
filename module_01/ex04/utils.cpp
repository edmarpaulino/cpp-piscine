/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:21:13 by edpaulin          #+#    #+#             */
/*   Updated: 2023/04/23 20:57:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string replace(std::string str, std::string from, std::string to)
{
	if (str.empty() || from.empty() || to.empty())
	{
		return str;
	}

	size_t pos = str.find(from);

	if (pos == str.npos)
	{
		return str;
	}

	std::string result(str.substr(0, pos));
	result.append(to);
	result.append(str.substr(pos + from.length()));

	return result;
}

std::string replaceAll(std::string str, std::string from, std::string to)
{
	if (str.empty() || from.empty() || to.empty())
	{
		return str;
	}

	std::string result("");
	size_t pos = str.find(from);

	while(pos != str.npos)
	{
		std::string buffer(str.substr(0, pos + from.length()));
		result.append(replace(buffer, from, to));
		str = str.substr(pos + from.length());
		pos = str.find(from);
	}

	if (str.length() > 0)
	{
		result.append(str);
	}

	return result;
}

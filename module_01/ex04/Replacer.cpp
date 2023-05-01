/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:01:43 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 12:17:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

str_t Replacer::replace(str_t str, str_t from, str_t to)
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

	str_t result(str.substr(0, pos));
	result.append(to);
	result.append(str.substr(pos + from.length()));

	return result;
}

str_t Replacer::replaceAll(str_t str, str_t from, str_t to)
{
	if (str.empty() || from.empty() || to.empty())
	{
		return str;
	}

	str_t result("");
	size_t pos = str.find(from);

	while(pos != str.npos)
	{
		str_t buffer(str.substr(0, pos + from.length()));
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

void Replacer::replaceFile(str_t filename, str_t from, str_t to)
{
	FileReader fr(filename);
	FileWriter fw(filename + ".replace");

	str_t content = fr.read();
	str_t replacedContent = replaceAll(content, from, to);

	fw.write(replacedContent);

	return;
}

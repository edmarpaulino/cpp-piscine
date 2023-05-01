/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:59:24 by edpaulin          #+#    #+#             */
/*   Updated: 2023/05/01 12:17:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
#define REPLACER_H

#include <string>

#include "FileReader.hpp"
#include "FileWriter.hpp"

typedef std::string str_t;

class Replacer
{
public:
	static str_t replace(str_t str, str_t from, str_t to);
	static str_t replaceAll(str_t str, str_t from, str_t to);
	static void replaceFile(str_t filename, str_t from, str_t to);

private:
};

#endif

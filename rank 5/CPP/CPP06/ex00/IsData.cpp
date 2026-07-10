/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsData.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:38:29 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/08 16:38:29 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

bool ScalarConverter::isChar( const std::string& param )
{
	return (param.length() == 1 && !std::isdigit(static_cast<char>(param[0])));
}

bool ScalarConverter::isInt( const std::string& param )
{
	size_t i = 0;

	if (param.empty())
		return (false);
	if ((static_cast<char>(param[0]) == '+') || (static_cast<char>(param[0]) == '-'))
		++i;
	if (i >= param.size())
		return (false);

	while (i < param.size())
	{
		if(!std::isdigit(static_cast<char>(param[i])))
			return (false);
		++i;
	}
	return (true);
}

bool ScalarConverter::isFloat( const std::string& param )
{
	if (param == "nanf" || param == "+inff" || param == "-inff")
		return (true);
	if (param[param.length() - 1] != 'f')
		return (false);
	
	std::string	number = param.substr(0, param.length() - 1);
	size_t i = 0;

	if (number.empty())
		return (false);
	if (i >= number.size())
		return (false);
	if (number.find('.') == 0
		|| ((number.find('e') != std::string::npos || number.find('E') != std::string::npos) && (std::count(number.begin(), number.end(), '.') > 2))
		|| ((number.find('e') == std::string::npos && number.find('E') == std::string::npos) && (std::count(number.begin(), number.end(), '.') > 1)))
		return (false);
	if ((number.find_first_of('e') != number.find_last_of('e'))
		|| (number.find_first_of('E') != number.find_last_of('E')))
		return (false);
	if ((static_cast<char>(number[0]) == '+') || (static_cast<char>(number[0]) == '-'))
		++i;
	while (i < number.size())
	{
		if(!std::isdigit(static_cast<char>(number[i])) 
			&& number[i] != '.' 
			&& number[i] != 'e'
			&& number[i] != '+'
			&& number[i] != '-'
			&& number[i] != 'E')
			return (false);
		++i;
	}
	return (true);
}

bool ScalarConverter::isDouble( const std::string& param )
{
	if (param == "nan" || param == "+inf" || param == "-inf")
		return (true);

	size_t i = 0;
	if (param.empty())
		return (false);
	if (i >= param.size())
		return (false);
	if (param.find('.') == 0
		|| ((param.find('e') != std::string::npos || param.find('E') != std::string::npos) && (std::count(param.begin(), param.end(), '.') > 2))
		|| ((param.find('e') == std::string::npos && param.find('E') == std::string::npos) && (std::count(param.begin(), param.end(), '.') > 1)))
		return (false);
	if ((param.find_first_of('e') != param.find_last_of('e'))
		|| (param.find_first_of('E') != param.find_last_of('E')))
		return (false);
	if ((static_cast<char>(param[0]) == '+') || (static_cast<char>(param[0]) == '-'))
		++i;
	while (i < param.size())
	{
		if(!std::isdigit(static_cast<char>(param[i])) 
			&& param[i] != '.'
			&& param[i] != 'e'
			&& param[i] != '+'
			&& param[i] != '-'
			&& param[i] != 'E')
			return (false);
		++i;
	}
	return (true);
}
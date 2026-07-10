/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 01:24:30 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/08 01:24:30 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::converterChar( const std::string& param )
{
	char	c = param[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout	<< "char: ";
	if (std::isprint(static_cast<unsigned char>(i)))
		std::cout	<< "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout	<< "int: " << i << "\n"
				<< "float: " << std::fixed << std::setprecision(1) << f << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << d
				<< std::endl;
}

void ScalarConverter::converterInt( const std::string& param )
{
	long int num = std::strtol(param.c_str(), NULL, 10);

	char	c = static_cast<char>(num);
	int		i = (num > INT_MAX || num < INT_MIN) ? 0 : static_cast<int>(num);
	float	f = static_cast<float>(num);
	double	d = static_cast<double>(num);
	
	std::cout	<< "char: ";
	if (std::isprint(static_cast<unsigned char>(i)))
		std::cout	<< "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout	<< "int: ";
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout	<< "float: " << std::fixed << std::setprecision(1) << f << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << d
				<< std::endl;
}

void ScalarConverter::converterFloat( const std::string& param )
{
	if (param == "nanf" || param == "+inff" || param == "-inff")
	{
		std::cout	<< "char: Impossible\n"
					<< "int: Impossible\n"
					<< "float: " << param << "\n"
					<< "double: " << param.substr(0, param.length() - 1)
					<< std::endl;
		return ;
	}
	
	std::string	numstring = param.substr(0, param.length() - 1);
	float num = std::strtof(numstring.c_str(), NULL);

	int n = (numstring.find('.') != std::string::npos ?
			((numstring.find_first_of("eE") != std::string::npos) ?
			static_cast<int>(numstring.find_first_of("eE") - numstring.find('.') - 1) :
			static_cast<int>(numstring.size() - numstring.find('.') - 1)) : 0);

	char	c = static_cast<char>(num);
	long	i = static_cast<long>(num);
	float	f = num;
	double	d = static_cast<double>(num);

	std::cout	<< "char: ";
	if (std::isprint(static_cast<unsigned char>(i)))
		std::cout	<< "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (numstring.find('e') != std::string::npos || numstring.find('E') != std::string::npos)
	{
		std::cout	<< "int: ";
		if (num < static_cast<float>(INT_MAX) && num > static_cast<float>(INT_MIN))
			std::cout	<< i << std::endl;
		else
			std::cout	<< "Impossible" << std::endl;
		std::cout	<< "float: " << std::scientific << std::setprecision(n) << f << "f\n"
					<< "double: " << std::scientific << std::setprecision(n) << d
					<< std::endl;
	}
	else
	{
		std::cout	<< "int: ";
		if (num < static_cast<float>(INT_MAX) && num > static_cast<float>(INT_MIN))
			std::cout	<< i << std::endl;
		else
			std::cout	<< "Impossible" << std::endl;
		std::cout	<< "float: " << std::fixed << std::setprecision(n) << f << "f\n"
					<< "double: " << std::fixed << std::setprecision(n) << d
					<< std::endl;
	}
}

void ScalarConverter::converterDouble( const std::string& param )
{
	if (param == "nan" || param == "+inf" || param == "-inf")
	{
		std::cout	<< "char: Impossible\n"
					<< "int: Impossible\n"
					<< "float: " << param << "f\n"
					<< "double: " << param
					<< std::endl;
		return ;
	}
	
	double num = std::strtod(param.c_str(), NULL);

	int n = (param.find('.') != std::string::npos ?
			((param.find_first_of("eE") != std::string::npos) ?
			static_cast<int>(param.find_first_of("eE") - param.find('.') - 1) :
			static_cast<int>(param.size() - param.find('.') - 1)) : 0);

	char	c = static_cast<char>(num);
	long	i = static_cast<long>(num);
	float	f = static_cast<float>(num);
	double	d = num;

	std::cout	<< "char: ";
	if (std::isprint(static_cast<unsigned char>(i)))
		std::cout	<< "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	
	if (param.find('e') != std::string::npos || param.find('E') != std::string::npos)
	{
		std::cout	<< "int: ";
		if (num < static_cast<float>(INT_MAX) && num > static_cast<float>(INT_MIN))
			std::cout	<< i << std::endl;
		else
			std::cout	<< "Impossible" << std::endl;
		std::cout	<< "float: " << std::scientific << std::setprecision(n) << f << "f\n"
					<< "double: " << std::scientific << std::setprecision(n) << d
					<< std::endl;
	}
	else
	{
		std::cout	<< "int: ";
		if (num < static_cast<float>(INT_MAX) && num > static_cast<float>(INT_MIN))
			std::cout	<< i << std::endl;
		else
			std::cout	<< "Impossible" << std::endl;
		std::cout	<< "float: " << std::fixed << std::setprecision(n) << f << "f\n"
					<< "double: " << std::fixed << std::setprecision(n) << d
					<< std::endl;
	}
}
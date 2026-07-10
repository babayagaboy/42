/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:29:58 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 22:29:58 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	// std::cout << "ScalarConverter Default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
	(void)other;	
	// std::cout << "ScalarConverter Copy constructor called." << std::endl;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
	// std::cout << "ScalarConverter Copy assignment called." << std::endl;
	if (this != &other) {}
	return (*this);
}

ScalarConverter::~ScalarConverter( void )
{
	// std::cout << "ScalarConverter Destructor called." << std::endl;
}

void	ScalarConverter::convert( const std::string& param )
{
	bool (*checks[]) ( const std::string& ) = {
		isChar,
		isInt,
		isFloat,
		isDouble,
	};

	void (*converters[]) ( const std::string& ) = {
		converterChar,
		converterInt,
		converterFloat,
		converterDouble,
	};

	for(int i = 0; i <= 3; ++i) {
		if(checks[i](param))
		{
			converters[i](param);
			return ;
		}
	}
	std::cout << "Unknown type: " << param << std::endl;
}
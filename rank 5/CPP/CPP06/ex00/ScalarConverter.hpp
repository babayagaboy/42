/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:30:05 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 22:30:05 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <iomanip>
# include <cctype>
# include <sstream>
# include <algorithm>

class ScalarConverter {
	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter& operator=( const ScalarConverter& other );
		~ScalarConverter( void );

		static	bool isChar( const std::string& param );
		static	bool isInt( const std::string& param );
		static	bool isFloat( const std::string& param );
		static	bool isDouble( const std::string& param );

		static	void converterChar( const std::string& param );
		static	void converterInt( const std::string& param );
		static	void converterFloat( const std::string& param );
		static	void converterDouble( const std::string& param );
	public:
		static void	convert( const std::string& param );
};

#endif
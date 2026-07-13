/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:54:00 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/09 17:19:41 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 12;
	int b = 33;

	std::cout	<< "a: " << a << "\n"
				<< "b: " << b << "\n"
				<< std::endl;
	::swap(a, b);
	std::cout	<< "a: " << a << "\n"
				<< "b: " << b << "\n"
				<< std::endl;

	std::cout	<< WHATEVER_HPP::min(a ,b) << std::endl;
	std::cout	<< WHATEVER_HPP::max(a ,b) << std::endl;
	
	/*
	{
		std::cout	<< std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}
	*/
}
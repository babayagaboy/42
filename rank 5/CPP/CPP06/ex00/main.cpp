/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:33:11 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/07 22:33:11 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		ScalarConverter::convert("0");
		std::cout << std::endl;
		ScalarConverter::convert("42.0f");
		std::cout << std::endl;
		ScalarConverter::convert("-0.0");
		std::cout << std::endl;
		ScalarConverter::convert("nan");
		std::cout << std::endl;
		ScalarConverter::convert("42");
		std::cout << std::endl;
		ScalarConverter::convert("1000000000000000f");
		std::cout << std::endl;
		ScalarConverter::convert("1000000000000000");
		std::cout << std::endl;
		ScalarConverter::convert("1.3222e+13f");
		std::cout << std::endl;
		ScalarConverter::convert("5.5555e+5.5f");
		std::cout << std::endl;
		ScalarConverter::convert("2.34e+13..4");
		std::cout << std::endl;
		ScalarConverter::convert("1.323.f");
		std::cout << std::endl;
		ScalarConverter::convert("1.23456789");
		std::cout << std::endl;
		ScalarConverter::convert("-inff");
		return (0);
	}
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "wrong imput :P" << std::endl;
	return (0);
}
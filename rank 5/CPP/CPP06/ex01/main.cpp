/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:04:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/09 15:34:13 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	{
		Data	d;

		d.valueInt = 42;
		d.valueStr = "Hello";

		uintptr_t intptr = Serializer::serialize(&d);
		Data*	d2 = Serializer::deserialize(intptr);
		
		std::cout	<< "d &: " << &d << std::endl;
		std::cout	<< "d2 : " << d2 << std::endl;

		std::cout	<< "d  int value: " << d.valueInt << std::endl;
		std::cout	<< "d2 int value: " << d2->valueInt << std::endl;

		std::cout	<< "d  str value: " << d.valueStr << std::endl;
		std::cout	<< "d2 str value: " << d2->valueStr << std::endl;
	}
}
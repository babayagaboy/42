/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:19:44 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 20:28:12 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout 
		<< "The memory address of the string variable: " << &string << std::endl
		<< "The memory address held by stringPTR: " << stringPTR << std::endl
		<< "The memory address held by stringREF: " << &stringREF << std::endl
		<< std::endl;
	
	std::cout 
		<< "The value of the string variable.: " << string << std::endl
		<< "The value pointed to by stringPTR: " << *stringPTR << std::endl
		<< "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
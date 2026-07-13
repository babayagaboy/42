/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:20:38 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/11 15:20:38 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = i * i;
		for (unsigned int i = 0; i < arr.size(); ++i)
			std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
		std::cout << std::endl;
		
		Array<int> b(arr);
		arr[0] = 42;
			std::cout << "arr[0]: " << arr[0] << std::endl;
		for (unsigned int i = 0; i < b.size(); ++i)
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
		
		arr[arr.size() + 1] = 100;
	}
	catch(std::exception &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl;
	}
}
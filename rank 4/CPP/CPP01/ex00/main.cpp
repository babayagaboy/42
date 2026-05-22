/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:36:47 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 20:59:41 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	{
		Zombie it;
		it.announce();
	}
	{
		Zombie it("hugo");
		it.announce();
	}
	{
		Zombie* it = newZombie("biraj");
		it->announce();
		delete it;
	}
	{
		randomChump("alan");
	}
	{
		std::string names[] = {"huguinho" , "cutie", "kiskis"};
		for(int i = 0; i < 3; ++i) {
			randomChump(names[i]);
		}
	}
	return (0);
}
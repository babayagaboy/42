/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:36:47 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 20:26:04 by hgutterr         ###   ########.fr       */
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
		int n = 3;
		Zombie* horde;
		horde = zombieHorde(n, "Foo");
		for (int i = 0; i < n; ++i) {
			horde[i].announce();
		}
		delete[] horde;
	}
	return (0);
}
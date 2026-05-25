/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:29:05 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/25 17:53:34 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{

	Weapon w1;
	w1.setType("laser sword");

	{
		HumanA a("hugo", w1);
		a.attack();
		//HumanA b("miguel");
	}
	std::cout << std::endl;
	{
		HumanB a("hugo", &w1);
		a.attack();
		HumanB b("miguel");
		b.attack();
	}
}
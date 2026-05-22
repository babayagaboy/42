/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:01:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/05/22 20:11:05 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombiearr;

	zombiearr = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		zombiearr[i] = Zombie(name);
	}
	return (zombiearr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:06:54 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/02 16:56:19 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define NB_ANIMALS 10

int main()
{
	Animal *tab[NB_ANIMALS + 1];
	tab[NB_ANIMALS] = NULL;

	for(int i = 0; i < (NB_ANIMALS / 2); ++i) {
		tab[i] = new Cat();
	}
	for(int i = (NB_ANIMALS / 2); i < NB_ANIMALS; ++i) {
		tab[i] = new Dog();
	}
	for(int i = 0; i < NB_ANIMALS; ++i) {
		tab[i]->makeSound();
	}
	for(int i = 0; i < NB_ANIMALS; ++i) {
		delete tab[i];
	}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:06:54 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/03 13:05:24 by hgutterr         ###   ########.fr       */
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
	{	
		//const Animal* meta = new Animal();
		//const Animal beta;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const Animal& k = *i;
		const Cat m;
		const Animal* n = new Cat(m);
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << n->getType() << std::endl;

		i->makeSound();
		j->makeSound();
		k.makeSound();
		n->makeSound();
		m.makeSound();
		//meta->makeSound();

		//delete meta;
		delete j;
		delete i;
		delete n;
	}
}
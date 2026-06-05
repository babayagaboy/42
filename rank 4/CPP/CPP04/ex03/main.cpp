/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:18:08 by hgutterr          #+#    #+#             */
/*   Updated: 2026/06/05 22:32:26 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* cloud = new Character("Cloud");
    ICharacter* sephiroth = new Character("Sephiroth");

    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    cloud->equip(tmp);

	tmp = src->createMateria("ice");
    sephiroth->equip(tmp);
    
    tmp = src->createMateria("cure");
    cloud->equip(tmp);
	tmp = src->createMateria("cure");
    cloud->equip(tmp);
	tmp = src->createMateria("cure");
    cloud->equip(tmp);
	tmp = src->createMateria("cure");
    cloud->equip(tmp);

    cloud->use(0, *sephiroth);
    cloud->use(1, *sephiroth);
    cloud->use(2, *sephiroth);

	cloud->unequip(0);
	sephiroth->unequip(0);
    cloud->use(0, *sephiroth);

    delete sephiroth;
    delete cloud;
    delete src;
    return 0;
}
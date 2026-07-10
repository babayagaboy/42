/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:38:20 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/09 16:30:14 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	switch ((std::rand() % 3) + 1)
	{
		case 1:
			return (new A());
		case 2:
			return (new B());
		case 3:
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type: C" << std::endl;
	else
		std::cout << "type: unknown" << std::endl;
}

void	identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "type: C" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));
	{
		Base *b = generate();
		identify(b);
		delete b;
	}
	{
		Base *b = generate();
		identify(*b);
		delete b;
	}
	std::cout << std::endl;
	{
		Base *b[5];
		for (size_t i = 0; i < 5; ++i)
		{
			b[i] = generate();
			identify(b[i]);
			delete b[i];
		}
		
	}
}
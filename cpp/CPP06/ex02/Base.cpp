/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:10:28 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/21 08:35:34 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base *Base::generate(void)
{
	srand(static_cast<unsigned>(time(0)));
	int randomValue = rand() % 3;

	if (!randomValue)
		return new A();
	else if (randomValue == 1)
		return new B();
	else
		return new C();
}

void Base::identify(Base *base)
{
	if (!base)
	{
		std::cerr << ORANGE << "Base " << RESET << "Pointer is NULL" << std::endl;
		return;
	}
	else if (dynamic_cast<A *>(base))
		std::cout << ORANGE << "Base " << RESET << "Pointer of type A" << std::endl;
	else if (dynamic_cast<B *>(base))
		std::cout << ORANGE << "Base " << RESET << "Pointer of type B" << std::endl;
	else if (dynamic_cast<C *>(base))
		std::cout << ORANGE << "Base " << RESET << "Pointer of type C" << std::endl;
	else
	{
		std::cerr << ORANGE << "Base " << RESET << "Pointer is UNKNOWN type" << std::endl;
		delete base;
	}
}
void Base::identify(Base &base)
{
	try
	{
		A &aRef = dynamic_cast<A &>(base);
		std::cout << ORANGE << "Base " << RESET << "Ref of type A" << std::endl;
	}
	catch (const std::bad_cast &)
	{
		try
		{
			B &bRef = dynamic_cast<B &>(base);
			std::cout << ORANGE << "Base " << RESET << "Ref of type B" << std::endl;
		}
		catch (const std::bad_cast &)
		{
			try
			{
				C &cRef = dynamic_cast<C &>(base);
				std::cout << ORANGE << "Base " << RESET << "Ref of type C" << std::endl;
			}
			catch (const std::bad_cast &)
			{
				std::cerr << ORANGE << "Base " << RESET << "Ref is NULL or UNKNOWN type" << std::endl;
			}
		}
	}
}

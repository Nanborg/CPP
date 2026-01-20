/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:59:19 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 13:59:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int r = std::rand() % 3;
    if (r == 0)
        return new A;
    if (r == 1)
        return new B;
    return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";

}

void identify(Base &p)
{

    try
    {
        (void)dynamic_cast<A&>(p);
		std::cout << "A";
		return;
    }
    catch(const std::exception& e) {}

	try
    {
        (void)dynamic_cast<B&>(p);
		std::cout << "B";
		return;
    }
    catch(const std::exception& e) {}

	try
    {
        (void)dynamic_cast<C&>(p);
		std::cout << "C";
		return;
    }
    catch(const std::exception& e) {}

	std::cout << "Unknown";
}

int main(void)
{
	std::srand(std::time(NULL));
	
	for (int i = 0; i < 10; i++)
	{
		Base *instance = generate();
		std::cout << i ;
		std::cout << " = "; 
		identify(instance);
		std::cout << "|";
		identify(*instance);
		std::cout << std::endl;
		delete instance;
	}

	std::cout << "Cas limites" << std::endl;
	Base *nullPtr = NULL;
	std::cout << "NULL pointer = ";
	identify(nullPtr);
	std::cout << std::endl;

	Base *baseOnly = new Base;
	std::cout << "Base only = ";
	identify(baseOnly);
	std::cout << " | ";
	identify(*baseOnly);
	std::cout << std::endl;
	delete baseOnly;

	return 0;
}

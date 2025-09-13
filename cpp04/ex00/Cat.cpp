/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:26:41 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:54:21 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
    std::cout << "[C] Constructor\n";
}
Cat::Cat(const Cat &o) : Animal(o)
{
    // type = "Cat"; pas besoin car le copy ctor de Animal le fait deja
    std::cout << "[C] Copy Constructor\n";
}
Cat &Cat::operator=(const Cat &o)
{
    Animal::operator=(o);
    type = "Cat";
    std::cout << "[C] Copy Assignment\n";
    return *this;
}
Cat::~Cat()
{
    std::cout << "[C] Destructor\n";
}
void Cat::makeSound() const
{
    std::cout << "Meow Meow\n";
}

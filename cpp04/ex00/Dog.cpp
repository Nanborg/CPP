/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:27:00 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:54:56 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    std::cout << "[D] Constructor\n";
}
Dog::Dog(const Dog &o) : Animal(o)
{
    type = "Dog";
    std::cout << "[D] Copy Constructor\n";
}
Dog &Dog::operator=(const Dog &o)
{
    Animal::operator=(o);
    // type = "Dog";
    std::cout << "[D] Copy Assignment\n";
    return *this;
}
Dog::~Dog()
{
    std::cout << "[D] Destructor\n";
}
void Dog::makeSound() const
{
    std::cout << "Woof Woof\n";
}

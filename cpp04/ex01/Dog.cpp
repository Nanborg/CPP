/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:26:51 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:59:14 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "[D] Constructor\n";
}
Dog::Dog(const Dog &o) : Animal(o)
{
    brain = new Brain(*o.brain);
    std::cout << "[D] Copy Constructor\n";
}
Dog &Dog::operator=(const Dog &o)
{
    if (this != &o)
    {
        Animal::operator=(o);
        Brain *newBrain = new Brain(*o.brain);
        delete brain;
        brain = newBrain;
    }
    std::cout << "[D] Copy Assignment\n";
    return *this;
}
Dog::~Dog()
{
    delete brain;
    std::cout << "[D] Destructor\n";
}
void Dog::makeSound() const
{
    std::cout << "Woof Woof\n";
}

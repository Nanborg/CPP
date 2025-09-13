/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:29:42 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:58:41 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "[C] Constructor\n";
}
Cat::Cat(const Cat &o) : Animal(o)
{

    brain = new Brain(*o.brain);
    std::cout << "[C] Copy Constructor\n";
}

Cat &Cat::operator=(const Cat &o)
{
    if (this != &o)
    {
        Animal::operator=(o);
        Brain *newBrain = new Brain(*o.brain);
        delete brain;
        brain = newBrain;
    }
    std::cout << "[C] Copy Assignment\n";
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[C] Destructor\n";
}
void Cat::makeSound() const
{
    std::cout << "Meow Meow\n";
}

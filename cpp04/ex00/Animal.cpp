/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:17:32 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:58:05 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "[A] Constructor\n";
}
Animal::Animal(const Animal &o) : type(o.type)
{
    std::cout << "[A] Copy Constructor\n";
}
Animal &Animal::operator=(const Animal &o)
{
    std::cout << "[A] Copy Assignment\n";
    if (this != &o)
        type = o.type;
    return *this;
}
Animal::~Animal()
{
    std::cout << "[A] Destructor\n";
}
std::string Animal::getType() const
{
    return type;
}
void Animal::makeSound() const
{
    std::cout << "[A] ???\n";
}

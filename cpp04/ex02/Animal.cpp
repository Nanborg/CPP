/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:04:07 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 18:07:55 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "[A] Constructor\n";
}
Animal::Animal(const Animal &o) : type(o.type)
{
    std::cout << "[A] Copy ctor\n";
}
Animal &Animal::operator=(const Animal &o)
{
    type = o.type;
    std::cout << "[A] Copy Assignement\n";
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

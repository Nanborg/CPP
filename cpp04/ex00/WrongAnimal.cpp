/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:48:29 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:56:31 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "[WA] Constructor\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal &o) : type(o.type)
{
    std::cout << "[WA] Copy Constructor\n";
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o)
{
    type = o.type;
    std::cout << "[WA] Copy Assignment\n";
    return *this;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "[WA] Destructor\n";
}
std::string WrongAnimal::getType() const
{
    return type;
}
void WrongAnimal::makeSound() const
{
    std::cout << "[WA] ???\n";
}

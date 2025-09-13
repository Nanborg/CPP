/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:54:00 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 17:56:31 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "[WC] Constructor\n";
}
WrongCat::WrongCat(const WrongCat &o) : WrongAnimal(o)
{
    type = "WrongCat";
    std::cout << "[WC] Copy Constructor\n";
}
WrongCat &WrongCat::operator=(const WrongCat &o)
{
    WrongAnimal::operator=(o);
    type = "WrongCat";
    std::cout << "[WC] Copy Assignment\n";
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "[WC] Destructor\n";
}
void WrongCat::makeSound() const
{
    std::cout << "Miaou???\n";
}

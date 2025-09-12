/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Humans.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:22:11 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 17:12:03 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>
void HumanA::attack() const
{
    std::cout << name << " attacks with his " << weapon.getType() << "\n";
}
void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with his " << weapon->getType() << "\n";
    else
        std::cout << name << " has no weapon\n";
}

/*
HumanA::attack() : utilise weapon (référence, opérateur .).
HumanB::attack() : vérifie si weapon existe (pointeur, opérateur -->), sinon affiche "no weapon".
*/

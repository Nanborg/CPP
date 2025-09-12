/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:16:18 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 17:11:42 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>
class HumanB
{
    std::string name;
    Weapon *weapon;

public:
    HumanB(std::string n) : name(n), weapon(0) {}
    void setWeapon(Weapon &w) { weapon = &w; }
    void attack() const;
};
#endif

/*
HumanB : peut être sans arme.
weapon est un pointeur ---> peut être nul. setWeapon() permet d’armer plus tard.
*/

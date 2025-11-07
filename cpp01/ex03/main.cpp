/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:16:21 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 17:15:53 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main(void)
{
    {
        Weapon weapon("personal revolver");

        HumanA moriarty("Moriarty", weapon);
        moriarty.attack();

        std::cout << "Another weapon is chosen..." << std::endl;
        weapon.setType("sword-cane");
        moriarty.attack();
    }

    std::cout << std::endl;

    {
        Weapon weapon("service pistol");

        HumanB sherlock("Sherlock");

        sherlock.attack();
        std::cout << "Sherlock receives a weapon..." << std::endl;
        sherlock.setWeapon(weapon);
        // sherlock.attack();
        // std::cout << "Sherlock change his weapon..." << std::endl;
        weapon.setType("old cane");
        sherlock.attack();
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:28:55 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 15:19:39 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    // --- Les Héros ---
    ClapTrap merlin("Merlin");
    ScavTrap galahad("Galahad");
    FragTrap lancelot("Lancelot");
    ClapTrap chimera("The Chimera");

    merlin.attack("a rampaging Chimera");
    std::cout << "Magic doesnt work ..." << std::endl;
    chimera.takeDamage(0);
    galahad.guardGate();
    lancelot.attack("the Chimera");
    chimera.takeDamage(30);
    galahad.attack("the Chimera");
    chimera.takeDamage(20);
    lancelot.highFivesGuys();
    galahad.beRepaired(25);
    return 0;
}
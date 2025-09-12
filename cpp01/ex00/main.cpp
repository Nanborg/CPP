/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:56:58 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 15:33:57 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    // Zombie alloué sur la HEAP
    Zombie *heapZombie = newZombie("Foo");
    heapZombie->announce();
    delete heapZombie; // Indispensable pour libérer la mémoire et éviter les fuites

    // Zombie alloué sur la STACK
    randomChump("Bar");

    return 0;
}
/*
Zombie* heapZombie = newZombie("Foo"); : crée un Zombie sur le heap.
heapZombie->announce(); : appel via pointeur.
delete heapZombie; : libère mémoire + appelle destructeur.
randomChump("Bar"); : crée un Zombie local sur la stack, détruit auto en fin de fonction.
*/

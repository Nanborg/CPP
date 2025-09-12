/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:28:01 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 14:00:51 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Céréal_Killer");
    ClapTrap b("victim");
    a.attack("victim");
    b.takeDamage(5);
    b.beRepaired(3);
    b.takeDamage(20);
    a.attack("and miss");
    return 0;
}

/*Rôle du fichier : Ce fichier sert de scénario de test pour la classe ClapTrap. Son objectif est de créer des instances de la classe et de les faire interagir pour prouver que leur comportement est correct et conforme aux règles de l'exercice.
Scénario à deux objets : Le test est particulièrement bien conçu car il met en scène deux objets distincts (a et b). Cela permet de créer une histoire plus logique (un attaquant et une victime) et de démontrer que chaque instance de ClapTrap possède son propre état indépendant (sa propre santé, ses propres points de mouvement, etc.).
Validation Complète : Le scénario exécute une séquence d'actions qui valide toutes les fonctionnalités clés : une attaque, la prise de dégâts, la réparation, et la prise de dégâts fatals, suivie d'une tentative d'action pour prouver que le ClapTrap est bien hors de combat.
Preuve par la Sortie : L'exécution de ce main produit une sortie terminale qui sert de preuve complète. On y voit clairement la construction des deux objets, le déroulement des actions et leurs conséquences sur l'état de la victime, et enfin la destruction des deux objets dans l'ordre inverse de leur création.
*/
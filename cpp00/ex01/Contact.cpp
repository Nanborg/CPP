/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:33 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 15:34:36 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    return;
}

Contact::~Contact(void)
{
    return;
}

void Contact::set_First_Name(std::string str) { this->first_Name = str; }
std::string Contact::get_First_Name(void) const { return this->first_Name; }

void Contact::set_Last_Name(std::string str) { this->last_Name = str; }
std::string Contact::get_Last_Name(void) const { return this->last_Name; }

void Contact::set_Nickname(std::string str) { this->nickname = str; }
std::string Contact::get_Nickname(void) const { return this->nickname; }

void Contact::set_Phone_Number(std::string str) { this->phone_Number = str; }
std::string Contact::get_Phone_Number(void) const { return this->phone_Number; }

void Contact::set_Secret(std::string str) { this->secret = str; }
std::string Contact::get_Secret(void) const { return this->secret; }

/*
 --- Explications Synthétiques ---
 Objectif : Implémenter le "comment faire" des fonctions déclarées dans Contact.hpp.
 Syntaxe : 'Contact::' est l'opérateur de résolution de portée. Il lie la fonction à la classe 'Contact'.
 Logique : Les 'setters' assignent une valeur aux membres privés.
 Logique : Les 'getters' retournent la valeur des membres privés.
 Syntaxe : 'this->' est un pointeur vers l'objet courant, utilisé pour accéder à ses membres.
 Pratique : Les constructeur et destructeur sont vides car il n'y a pas d'allocation mémoire à gérer.
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:20 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 15:34:36 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string first_Name;
	std::string last_Name;
	std::string nickname;
	std::string phone_Number;
	std::string secret;

public:
	Contact(void);
	~Contact(void);

	void set_First_Name(std::string str);
	void set_Last_Name(std::string str);
	void set_Nickname(std::string str);
	void set_Phone_Number(std::string str);
	void set_Secret(std::string str);

	std::string get_First_Name(void) const;
	std::string get_Last_Name(void) const;
	std::string get_Nickname(void) const;
	std::string get_Phone_Number(void) const;
	std::string get_Secret(void) const;
};

#endif

/*
Explications Synthétiques
 Objectif : Déclarer la "structure" d'un contact, ce qu'il contient et ce qu'on peut faire avec.
 Syntaxe : '#ifndef/#define/#endif' sont des "include guards". Ils empêchent les erreurs d'inclusion multiple.
 Logique : 'private' cache les données pour protéger l'intégrité de l'objet (encapsulation).
 Logique : 'public' expose les fonctions (méthodes) pour interagir avec l'objet de manière contrôlée.
 Pratique : 'setters' (setFirstName) pour modifier les données, 'getters' (getFirstName) pour les lire.
 Syntaxe : Le 'const' à la fin d'un getter promet que la fonction ne modifiera pas l'objet.
*/
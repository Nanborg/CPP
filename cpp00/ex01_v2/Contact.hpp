/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:51:20 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 19:29:14 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>

class Contact
{
private:
	std::string first, last, nick, phone, secret;

public:
	Contact();
	bool read_Stdin();				  // lit tous les champs (retourne false si EOF)
	void prt_Search(int index) const; // ligne 10 colonnes pour SEARCH
	void prt_Details() const;		  // détail d’un contact
};
#endif

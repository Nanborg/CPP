/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:45:02 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/10 14:51:50 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
int main()
{
    Harl h;
    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");
    return 0;
}

/*
Test : crée un Harl et appelle complain() avec DEBUG, INFO, WARNING, ERROR.
Vérifie que chaque niveau déclenche le bon message.
*/
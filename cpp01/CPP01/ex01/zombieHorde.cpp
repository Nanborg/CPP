/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:36:59 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 16:00:24 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return 0;
    Zombie *h = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        h[i].setName(name);
        i++;
    }
    return h;
}


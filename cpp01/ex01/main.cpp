/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:36:41 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 16:00:24 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main()
{
    int N = 12;
    Zombie *h = zombieHorde(N, "marcheurs blancs");
    int i = 0;
    while (i < N)
    {
        h[i].announce();
        i++;
    }
    delete[] h;
    return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:22:40 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/12 15:34:36 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        while (i < ac)
        {
            int j = 0;
            while (av[i][j] != '\0')
            {
                std::cout << (char)toupper(av[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return 0;
}
/*
Afficher en majuscule les args, si pas d'args LOUD NOISE
*/

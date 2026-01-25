/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:59:40 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 16:59:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error nb of arg invalid" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.calculate(av[1]);
    return 0;
}

/* TESTS
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"
./RPN "1 2 +"
./RPN "1 2 -"
./RPN "7 8 *"
./RPN "8 4 /"
./RPN "1 2 + +"
./RPN "1 2 3 +"
./RPN "5 0 /"
./RPN "1 2 a +"
./RPN ""
./RPN "1    2    +"
./RPN "  5 5 +  "
*/

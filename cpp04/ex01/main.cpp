/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:33:40 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/13 18:00:04 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    int n = 5;
    Animal *animals[n];
    int k = 0;
    while (k < n)
    {
        if (k % 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
        k++;
    }
    k = 0;
    while (k < n)
    {
        delete animals[k];
        k++;
    }
    return 0;
}
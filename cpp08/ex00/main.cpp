/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:45:32 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 10:45:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    //vecteurs
    std::vector<int> vec;
    vec.push_back(15);
    vec.push_back(30);
    vec.push_back(45);

    try
    {
        std::vector<int>::iterator x = ::easyfind(vec, 30);
        std::cout << "value is found " << *x << std::endl;
        std::cout << "searcj new value (22)" << std::endl;
        ::easyfind(vec, 22);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    
    //listes
    std::list<int> liste;
    liste.push_back(2);
    liste.push_back(3);
    liste.push_back(4);

        try
    {
        std::list<int>::iterator x = ::easyfind(liste, 3);
        std::cout << "value is found " << *x << std::endl;
        std::cout << "search new value (1)" << std::endl;
        ::easyfind(liste, 1);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    //deques
    std::deque<int> deq;
    deq.push_back(80);
    deq.push_back(140);

    try
    {
        std::deque<int>::iterator x = ::easyfind(deq, 140);
        std::cout << "value is found " << *x << std::endl;
        std::cout << "search new value (100)" << std::endl;
        ::easyfind(deq, 100);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
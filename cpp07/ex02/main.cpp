/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:55:36 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 14:55:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> /// ils ont oublie cstdlib dans le main donné
#include <ctime> //pareil pour time
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    // ceci est rajouté par moi pour des test supplementaires
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "42";

	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;

	const Array<std::string> const_strings = strings;
	std::cout << "Const string [1] = " << const_strings[1] << std::endl;
    
    Array<int> empty;
    std::cout << "Empty array = " << empty.size() << std::endl;

    Array<int> init_test(3);
    std::cout << "init a (0) = " << init_test[0] << std::endl;

    Array<int> original(1);
    original[0] = 42;
    Array<int> copy = original;
    original[0] = 999;
    std::cout << "Original = " << original[0] << " | Copy = " << copy[0] << " (correct if = 42)" << std::endl;

    copy = copy;
    return 0;
}
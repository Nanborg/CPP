/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:11:59 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 11:11:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>

int main()
{

    Span sp = Span(10);
    sp.addNumber(1); 
    sp.addNumber(43);
    sp.addNumber(234);
    sp.addNumber(56);
    sp.addNumber(78);
    sp.addNumber(90);
    sp.addNumber(12);
    sp.addNumber(34);
    sp.addNumber(80);
    sp.addNumber(1000);
    std::cout << "short = " << sp.shortestSpan() << std::endl;
    std::cout << "long = " << sp.longestSpan() << std::endl;

    std::cout << "for big numbers" << std::endl;
    Span bigSpan(30000);
    std::list<int> lst;
    std::srand(std::time(0));
    for (int i = 0; i < 30000; ++i)
    {
        lst.push_back(std::rand());
    }

    try
    {
        bigSpan.addNumber(lst.begin(), lst.end());
        std::cout << "short = " << bigSpan.shortestSpan() << std::endl;
        std::cout << "long = " << bigSpan.longestSpan() << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    
    std::cout << "add more numbers than dispo" << std::endl;
    try
    {
        Span smallDiff(1);
        smallDiff.addNumber(25);
        smallDiff.addNumber(26);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
    
}
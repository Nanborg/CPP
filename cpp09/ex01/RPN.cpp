/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:59:26 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 16:59:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &src)
{
    *this = src;
}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->stak = other.stak;
    }
    return *this;
}

void RPN::calculate(const std::string &input)
{
    for (size_t i = 0; i < input.length(); ++i)
    {
        char c = input[i];
        if (c == ' ')
            continue;
        if (isdigit(c))
        {
            stak.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (stak.size() < 2)
            {
                std::cerr << "Error: not enough operands for " << c << std::endl;
                return;
            }
            int b = stak.top(); stak.pop();
            int a = stak.top(); stak.pop();
            if (c == '+')
                stak.push(a + b);
            else if (c == '-')
                stak.push(a - b);
            else if (c == '*')
                stak.push(a * b);
            else if (c == '/')
            {
                if (b == 0)
                {
                    std::cerr << "Error div zero" << std::endl;
                    return;
                }
                stak.push(a / b);
            }
        }
        else
        {
            std::cerr << "Error char invalid " << std::endl;
            return;
        }
        

    }
    if (stak.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    else
        std::cout << stak.top() << std::endl;
}
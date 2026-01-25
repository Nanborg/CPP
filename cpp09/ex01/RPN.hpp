/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:59:16 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 16:59:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> stak;
    public: //canon
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &other);
        ~RPN();
        void calculate(const std::string &input);
};

#endif

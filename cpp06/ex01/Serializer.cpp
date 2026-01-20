/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:12:49 by marvin            #+#    #+#             */
/*   Updated: 2026/01/20 11:12:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(Serializer const &src) 
{ 
    (void)src; 
}
Serializer &Serializer::operator=(Serializer const &other) 
{ 
    (void)other; return *this; 
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) 
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) 
{
	return reinterpret_cast<Data*>(raw);
}
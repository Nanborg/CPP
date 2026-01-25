/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:17:40 by marvin            #+#    #+#             */
/*   Updated: 2026/01/25 20:17:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vectorData = other.vectorData;
        dequeData = other.dequeData;
    }
    return *this;
}

void PmergeMe::sortVec()
{
    if (vectorData.size() <= 1)
        return;
    std::vector<int> sortedMain, remainder;
    for (size_t index = 0; index < vectorData.size() - 1; index += 2)
    {
        if (vectorData[index] < vectorData[index + 1])
            std::swap(vectorData[index], vectorData[index + 1]);
        sortedMain.push_back(vectorData[index]);
        remainder.push_back(vectorData[index + 1]);
    }
    if (vectorData.size() % 2 != 0)
        remainder.push_back(vectorData.back());
    std::sort(sortedMain.begin(), sortedMain.end());
    for (size_t index = 0; index < remainder.size(); index++)
    {
        std::vector<int>::iterator position = std::lower_bound(sortedMain.begin(), sortedMain.end(), remainder[index]);
        sortedMain.insert(position, remainder[index]);
    }
    vectorData = sortedMain;
}
void PmergeMe::sortDeq()
{
    if (dequeData.size() <= 1)
        return;
    std::deque<int> sortedMain, remainder;
    for (size_t index = 0; index < dequeData.size() - 1; index += 2)
    {
        if (dequeData[index] < dequeData[index + 1])
            std::swap(dequeData[index], dequeData[index + 1]);
        sortedMain.push_back(dequeData[index]);
        remainder.push_back(dequeData[index + 1]);
    }
    if (dequeData.size() % 2 != 0)
        remainder.push_back(dequeData.back());
    std::sort(sortedMain.begin(), sortedMain.end());
    for (size_t index = 0; index < remainder.size(); index++)
    {
        std::deque<int>::iterator position = std::lower_bound(sortedMain.begin(), sortedMain.end(), remainder[index]);
        sortedMain.insert(position, remainder[index]);
    }
    dequeData = sortedMain;
}

void PmergeMe::runSort(int ac, char **av)
{
    for (int index = 1; index < ac; index++)
    {
        std::stringstream inputstream(av[index]);
        int number;
        while (inputstream >> number)
        {
            if (number < 0)
            {
                std::cerr << "Error: Negative numbers are not allowed." << std::endl;
                exit(1);
            }
            vectorData.push_back(number);
            dequeData.push_back(number);
        }
    }
    std::cout << "Befor ";
    for (size_t index = 0; index < vectorData.size(); index++)
    {
        std::cout << vectorData[index] << " ";
    }
    std::cout << std::endl;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortVec();
    gettimeofday(&end, NULL);
    long vectorTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    sortDeq();
    gettimeofday(&end, NULL);
    long dequeTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    std::cout << "After ";
    for (size_t index = 0; index < vectorData.size(); index++)
    {
        std::cout << vectorData[index] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process  " << vectorData.size() << " with vector  " << vectorTime << " us" << std::endl;
    std::cout << "Time to process  " << dequeData.size() << " with deque   " << dequeTime << " us" << std::endl;
}

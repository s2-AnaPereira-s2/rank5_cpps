/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:07:47 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/05/08 01:40:38 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <deque>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::vector<int> vec_sorted;
        std::deque<int> dq;
        std::deque<int> dq_sorted;
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void add_number(std::string number);
        int vec_sort(std::vector<int>& v);
        int dq_sort(std::deque<int>& d);
        void funcSort();
};

#endif
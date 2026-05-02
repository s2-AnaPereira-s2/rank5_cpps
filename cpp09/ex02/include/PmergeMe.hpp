/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:07:47 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/05/02 16:44:13 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <deque>

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
        void vec_bNlNsN(std::vector<int>& v);
        void dq_bNlNsN(std::deque<int>& d);
        void funcSort();
};

#endif
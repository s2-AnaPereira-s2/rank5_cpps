/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana <ana@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:20:44 by ana-pdos          #+#    #+#             */
/*   Updated: 2026/04/27 23:47:29 by ana              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main() {
    std::cout << "=== Test 1: Basic push/pop and iteration ===" << std::endl;

    MutantStack<int> mstack;
    
    mstack.push(3);
	mstack.push(234);
	mstack.push(179);
	mstack.push(96);
	mstack.push(3472946);

    std::cout << "Stack elements: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	std::cout << "pop element at the top (last added)" << std::endl;
    mstack.pop();
    std::cout << "After pop(): ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 2: Copy constructor ===" << std::endl;
    MutantStack<int> copyStack(mstack);
    std::cout << "CopyStack elements: ";
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Assignment operator ===" << std::endl;
    MutantStack<int> assignStack;
    assignStack = mstack;
    std::cout << "AssignStack elements: ";
    for (MutantStack<int>::iterator it = assignStack.begin(); it != assignStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 4: Const iteration ===" << std::endl;
    const MutantStack<int>& constRef = mstack;
    std::cout << "Const stack elements: ";
    for (MutantStack<int>::const_iterator it = constRef.begin(); it != constRef.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}


//// Main from subject
//int main() { 
//MutantStack<int> mstack;
//
//mstack.push(5);
//mstack.push(17);
//
//std::cout << mstack.top() << std::endl;
//
//mstack.pop();
//
//std::cout << mstack.size() << std::endl;
//
//mstack.push(3);
//mstack.push(5);
//mstack.push(737); 
////[...] 
//mstack.push(0); 
//
//MutantStack<int>::iterator it = mstack.begin();
//MutantStack<int>::iterator ite = mstack.end(); 
//
//++it;
//--it;
//while (it != ite) { 
//	std::cout << *it << std::endl; 
//	++it; 
//} 
//
//std::stack<int> s(mstack);
//return 0;
//}

//// Main for different types of containers
//#include <iostream>
//#include <stack>
//#include <list>
//#include <vector>
//#include "MutantStack.hpp"
//
//// Uncomment the container you want to test
////#define MUTANT_STACK
////typedef MutantStack<int> MyContainer;
//typedef std::vector<int> MyContainer;
////typedef std::list<int> MyContainer;
//
//int main() {
//    MyContainer c;
//
//    #ifdef MUTANT_STACK
//        c.push(5);
//        c.push(17);
//		std::cout << "Last element added: " << c.top() << std::endl;
//        std::cout << "Size before pop: " << c.size() << std::endl;
//        c.pop();
//		std::cout << "Size after pop: " << c.size() << std::endl;
//        c.push(3);
//        c.push(5);
//        c.push(737);
//        c.push(0);
//    #else
//        c.push_back(5);
//        c.push_back(17);
//		std::cout << "Last element added: " << c.back() << std::endl;
//        std::cout << "Size before pop: " << c.size() << std::endl;
//        c.pop_back();
//		std::cout << "Size after pop: " << c.size() << std::endl;
//        c.push_back(3);
//        c.push_back(5);
//        c.push_back(737);
//        c.push_back(0);
//    #endif
//
//    // Iteration
//    for (MyContainer::iterator it = c.begin(); it != c.end(); ++it) {
//        std::cout << *it << std::endl;
//    }
//
//    return 0;
//}
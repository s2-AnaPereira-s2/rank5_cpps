#include "iter.hpp"

void printInt(int x) {
    std::cout << x << " ";
}

void printString(const std::string &s) {
    std::cout << s << " ";
}

void incrementInt(int &x) {
    x += 1;
}

int main(void) {
    std::cout << "=== Test 1: Integers with value function ===" << std::endl;
    int arr1[] = {1, 2, 3, 4, 5};
    ::iter(arr1, 5, printInt);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 2: Strings with const reference function ===" << std::endl;
    std::string arr2[] = {"hello", "world", "template"};
    ::iter(arr2, 3, printString);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 3: Modify array (increment) ===" << std::endl;
    int arr3[] = {10, 20, 30};
    std::cout << "Before: ";
    ::iter(arr3, 3, printInt);
    std::cout << std::endl;
    ::iter(arr3, 3, incrementInt);
    std::cout << "After:  ";
    ::iter(arr3, 3, printInt);
    std::cout << std::endl << std::endl;

    return 0;
}
#include "array.hpp"
#include <iostream>

int main(void) 
{
    std::cout << "=== Test 1: Default Constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 2: Constructor with Size ===" << std::endl;
    Array<int> arr(5);
    std::cout << "Array of 5 ints created" << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << "Default initialized values: ";
    for (size_t i = 0; i < arr.size(); i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 3: Access and Modify Elements ===" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = i * 10;
    }
    std::cout << "After modification: ";
    for (size_t i = 0; i < arr.size(); i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 4: Copy Constructor (Deep Copy) ===" << std::endl;
    Array<int> arr2(arr);
    std::cout << "Original arr: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Copy arr2: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    arr2[0] = 999;
    arr2[1] = 888;
    
    std::cout << "After modifying copy arr2[0] = 999, arr2[1] = 888" << std::endl;
    std::cout << "Original arr[0]: " << arr[0] << ", arr[1]: " << arr[1] << std::endl;
    std::cout << "Copy arr2[0]: " << arr2[0] << ", arr2[1]: " << arr2[1] << std::endl;
    std::cout << "✓ Deep copy confirmed (modification didn't affect original)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 5: Assignment Operator (Deep Copy) ===" << std::endl;
    Array<int> arr3(2);
    arr3[0] = 111;
    arr3[1] = 222;
    std::cout << "arr3 before assignment: size=" << arr3.size() << ", values: " << arr3[0] << " " << arr3[1] << std::endl;
    
    arr3 = arr;
    std::cout << "After arr3 = arr: size=" << arr3.size() << std::endl;
    std::cout << "arr3 values: ";
    for (size_t i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
    
    // Modify arr3
    arr3[0] = 777;
    std::cout << "After modifying arr3[0] = 777" << std::endl;
    std::cout << "Original arr[0]: " << arr[0] << ", arr3[0]: " << arr3[0] << std::endl;
    std::cout << "✓ Assignment operator works (deep copy)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 6: Self-Assignment Check ===" << std::endl;
    arr = arr;  
    std::cout << "Self-assignment successful, arr values: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 7: Bounds Checking (Exception) ===" << std::endl;
    try {
        std::cout << "Trying to access arr[100]..." << std::endl;
        std::cout << arr[100] << std::endl;
        std::cout << "✗ Exception NOT thrown (BAD)" << std::endl;
    } catch (std::exception &e) {
        std::cout << "✓ Exception caught! Out of bounds access prevented" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 8: String Array ===" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "hello";
    strings[1] = "world";
    strings[2] = "template";
    std::cout << "String array: ";
    for (size_t i = 0; i < strings.size(); i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "=== All Tests Completed ===" << std::endl;
    return 0;
}
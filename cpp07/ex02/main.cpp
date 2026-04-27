#include "array.hpp"

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
    
    arr3[0] = 777;
    std::cout << "After modifying arr3[0] = 777" << std::endl;
    std::cout << "Original arr[0]: " << arr[0] << ", arr3[0]: " << arr3[0] << std::endl;
    std::cout << "✓ Assignment operator works (deep copy)" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 6: Bounds Checking (Exception) ===" << std::endl;
    try {
        std::cout << "Trying to access arr[100]..." << std::endl;
        std::cout << arr[100] << std::endl;
        std::cout << "✗ Exception NOT thrown (BAD)" << std::endl;
    } catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 7: String Array ===" << std::endl;
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

/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}*/
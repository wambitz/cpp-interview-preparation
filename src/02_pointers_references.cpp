/*
 * Pointers and References - Interview Topics
 * 
 * Key Topics to Cover:
 * - Pointer declaration and initialization
 * - Pointer arithmetic
 * - References vs pointers
 * - Null pointers and nullptr
 * - Dangling pointers
 * - Double pointers
 * - Function pointers
 */

#include <iostream>
#include <string>

// TODO: Implement these functions for function pointer demonstrations

// 1. Simple functions for function pointer demo
int add(int a, int b);
int multiply(int a, int b);
void greet(const std::string& name);

// 2. Function that takes function pointer
int calculate(int a, int b, int (*operation)(int, int));

// 3. Function that returns function pointer
int (*getOperation(char op))(int, int);

// TODO: Implement these classes

// 4. Class for demonstrating pointer to members
class Calculator {
private:
    double value;
    
public:
    Calculator(double val = 0.0);
    
    double add(double x);
    double subtract(double x);
    double multiply(double x);
    double divide(double x);
    
    void setValue(double val);
    double getValue() const;
};

// Function prototypes for demonstrations
void demonstrateBasicPointers();
void demonstratePointerArithmetic();
void demonstrateReferencesVsPointers();
void demonstrateNullPointers();
void demonstrateDanglingPointers();
void demonstrateDoublePointers();
void demonstrateFunctionPointers();
void demonstratePointerToMembers();

int main() {
    std::cout << "=== Pointers and References Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicPointers();
    demonstratePointerArithmetic();
    demonstrateReferencesVsPointers();
    demonstrateNullPointers();
    demonstrateDanglingPointers();
    demonstrateDoublePointers();
    demonstrateFunctionPointers();
    demonstratePointerToMembers();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicPointers() {
    std::cout << "1. Basic Pointer Operations:\n";
    // Create variables and pointers
    // Show address-of and dereference operators
    // Demonstrate pointer initialization
    
    int value = 42;
    int* ptr = &value;
    
    // TODO: Show pointer operations
    // Address printing, dereferencing
    // Const pointers vs pointer to const
    
    std::cout << "---\n\n";
}

void demonstratePointerArithmetic() {
    std::cout << "2. Pointer Arithmetic:\n";
    // Create array and demonstrate pointer arithmetic
    // Show relationship between arrays and pointers
    
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    
    // TODO: Demonstrate pointer increment/decrement
    // Show pointer subtraction
    // Array indexing vs pointer arithmetic
    
    std::cout << "---\n\n";
}

void demonstrateReferencesVsPointers() {
    std::cout << "3. References vs Pointers:\n";
    // Show differences between references and pointers
    // Initialization requirements
    // Reassignment capabilities
    
    int a = 10, b = 20;
    int* ptr = &a;
    int& ref = a;
    
    // TODO: Show key differences
    // Reference must be initialized
    // Pointer can be reassigned, reference cannot
    // Null reference doesn't exist
    
    std::cout << "---\n\n";
}

void demonstrateNullPointers() {
    std::cout << "4. Null Pointers:\n";
    // Show NULL vs nullptr
    // Demonstrate null pointer checking
    
    int* ptr1 = nullptr;
    int* ptr2 = NULL;
    int* ptr3 = 0;
    
    // TODO: Show best practices with null pointers
    // Checking before dereferencing
    // Modern C++ prefers nullptr
    
    std::cout << "---\n\n";
}

void demonstrateDanglingPointers() {
    std::cout << "5. Dangling Pointers:\n";
    // Show how dangling pointers are created
    // Demonstrate the problem and solutions
    
    int* ptr;
    {
        int local = 100;
        ptr = &local;  // Dangerous!
    }
    // ptr is now dangling
    
    // TODO: Show the problem and safe alternatives
    // Stack vs heap allocated memory
    // Smart pointer solutions
    
    std::cout << "---\n\n";
}

void demonstrateDoublePointers() {
    std::cout << "6. Double Pointers:\n";
    // Show pointer to pointer concept
    // Demonstrate common use cases
    
    int value = 42;
    int* ptr = &value;
    int** doublePtr = &ptr;
    
    // TODO: Show double pointer operations
    // Modify pointer through double pointer
    // Dynamic array of pointers
    
    std::cout << "---\n\n";
}

void demonstrateFunctionPointers() {
    std::cout << "7. Function Pointers:\n";
    // Show function pointer declaration and usage
    // Demonstrate function pointer arrays
    
    // TODO: Use function pointers
    // Call functions through pointers
    // Function pointer as parameter
    // Array of function pointers
    
    std::cout << "---\n\n";
}

void demonstratePointerToMembers() {
    std::cout << "8. Pointer to Members:\n";
    // Show pointer to member variables and functions
    // Demonstrate usage with objects
    
    Calculator calc(10.0);
    
    // TODO: Demonstrate pointer to member variables
    // double Calculator::*valuePtr = &Calculator::value;  // Won't compile - private
    
    // TODO: Demonstrate pointer to member functions
    double (Calculator::*funcPtr)(double) = &Calculator::add;
    
    // Using pointer to member function
    double result = (calc.*funcPtr)(10.5);  // Call add through function pointer
    std::cout << "Result using function pointer: " << result << "\n";
    
    std::cout << "---\n\n";
}

// TODO: Implement the helper functions
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

void greet(const std::string& name) {
    std::cout << "Hello, " << name << "!\n";
}

int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

int (*getOperation(char op))(int, int) {
    switch (op) {
        case '+': return add;
        case '*': return multiply;
        default: return nullptr;
    }
}

// TODO: Implement Calculator class methods
Calculator::Calculator(double val) : value(val) {}

double Calculator::add(double x) {
    return value += x;
}

double Calculator::subtract(double x) {
    return value -= x;
}

double Calculator::multiply(double x) {
    return value *= x;
}

double Calculator::divide(double x) {
    if (x != 0) {
        return value /= x;
    }
    return value;
}

void Calculator::setValue(double val) {
    value = val;
}

double Calculator::getValue() const {
    return value;
}

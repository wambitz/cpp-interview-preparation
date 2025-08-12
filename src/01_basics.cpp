/*
 * C++ Basics - Interview Topics
 * 
 * Key Topics to Cover:
 * - Data types and their sizes
 * - Variables and constants
 * - Scope and lifetime
 * - Input/Output operations
 * - Basic control structures
 * - Functions and parameter passing
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// TODO: Global variables for scope demonstration
int globalVar = 100;
const int globalConst = 200;
constexpr int globalConstexpr = 300;

// TODO: Implement these functions

// 1. Data Types and Sizes
void demonstrateDataTypes();
void showDataTypeSizes();

// 2. Variable Declaration and Initialization
void demonstrateVariableDeclarations();
void demonstrateConstVsConstexpr();

// 3. Scope and Lifetime
void demonstrateScope();
void demonstrateLifetime();
static int staticCounter = 0;

// 4. Parameter Passing
void passByValue(int value);
void passByReference(int& reference);
void passByPointer(int* pointer);
void passByConstReference(const int& constRef);
void demonstrateParameterPassing();

// 5. Function Overloading
void processValue(int value);
void processValue(double value);
void processValue(const std::string& value);
void demonstrateFunctionOverloading();

// 6. Default Parameters
void functionWithDefaults(int required, int optional1 = 10, double optional2 = 3.14);
void demonstrateDefaultParameters();

// 7. Inline Functions
inline int square(int x) {
    return x * x;
}

int main() {
    std::cout << "=== C++ Basics Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateDataTypes();
    showDataTypeSizes();
    demonstrateVariableDeclarations();
    demonstrateConstVsConstexpr();
    demonstrateScope();
    demonstrateLifetime();
    demonstrateParameterPassing();
    demonstrateFunctionOverloading();
    demonstrateDefaultParameters();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateDataTypes() {
    std::cout << "1. Basic Data Types:\n";
    // Create variables of different types
    // Show their values and characteristics
    
    int intVar = 42;
    float floatVar = 3.14f;
    double doubleVar = 3.14159265359;
    char charVar = 'A';
    bool boolVar = true;
    
    // TODO: Display each variable with proper formatting
    // Show overflow behavior
    // Demonstrate type conversions
    
    std::cout << "---\n\n";
}

void showDataTypeSizes() {
    std::cout << "2. Data Type Sizes:\n";
    // TODO: Use sizeof to show sizes of different types
    // Show platform-dependent nature
    // Include signed vs unsigned variations
    
    std::cout << "---\n\n";
}

void demonstrateVariableDeclarations() {
    std::cout << "3. Variable Declarations:\n";
    // TODO: Show different initialization styles
    // C++11 uniform initialization
    // Auto keyword usage
    // Zero initialization vs default initialization
    
    std::cout << "---\n\n";
}

void demonstrateConstVsConstexpr() {
    std::cout << "4. const vs constexpr:\n";
    // TODO: Show differences between const and constexpr
    // Runtime vs compile-time evaluation
    // When to use each
    
    std::cout << "---\n\n";
}

void demonstrateScope() {
    std::cout << "5. Variable Scope:\n";
    // TODO: Show local vs global scope
    // Block scope demonstration
    // Name hiding/shadowing
    
    int localVar = 50;
    
    {
        int blockVar = 75;
        // TODO: Show scope rules
    }
    
    std::cout << "---\n\n";
}

void demonstrateLifetime() {
    std::cout << "6. Variable Lifetime:\n";
    // TODO: Show automatic vs static storage duration
    // Demonstrate static local variables
    // Object destruction order
    
    staticCounter++;
    static int staticLocal = 0;
    staticLocal++;
    
    std::cout << "---\n\n";
}

void demonstrateParameterPassing() {
    std::cout << "7. Parameter Passing:\n";
    // TODO: Call functions with different parameter types
    // Show how each affects the original variable
    
    int value = 10;
    
    std::cout << "Original value: " << value << "\n";
    
    passByValue(value);
    std::cout << "After pass by value: " << value << "\n";
    
    passByReference(value);
    std::cout << "After pass by reference: " << value << "\n";
    
    passByPointer(&value);
    std::cout << "After pass by pointer: " << value << "\n";
    
    std::cout << "---\n\n";
}

void demonstrateFunctionOverloading() {
    std::cout << "8. Function Overloading:\n";
    // TODO: Call overloaded functions
    // Show compiler resolution
    
    processValue(42);
    processValue(3.14);
    processValue(std::string("Hello"));
    
    std::cout << "---\n\n";
}

void demonstrateDefaultParameters() {
    std::cout << "9. Default Parameters:\n";
    // TODO: Call function with different argument counts
    
    functionWithDefaults(5);
    functionWithDefaults(5, 20);
    functionWithDefaults(5, 20, 2.71);
    
    std::cout << "---\n\n";
}

// TODO: Implement the parameter passing functions
void passByValue(int value) {
    value = 999;  // Only modifies the copy
    std::cout << "Inside passByValue: " << value << "\n";
}

void passByReference(int& reference) {
    reference = 888;  // Modifies the original
    std::cout << "Inside passByReference: " << reference << "\n";
}

void passByPointer(int* pointer) {
    if (pointer) {
        *pointer = 777;  // Modifies the original through pointer
        std::cout << "Inside passByPointer: " << *pointer << "\n";
    }
}

void passByConstReference(const int& constRef) {
    // constRef = 666;  // Compilation error - cannot modify
    std::cout << "Inside passByConstReference: " << constRef << "\n";
}

// TODO: Implement overloaded functions
void processValue(int value) {
    std::cout << "Processing integer: " << value << "\n";
}

void processValue(double value) {
    std::cout << "Processing double: " << std::fixed << std::setprecision(2) << value << "\n";
}

void processValue(const std::string& value) {
    std::cout << "Processing string: " << value << "\n";
}

// TODO: Implement function with default parameters
void functionWithDefaults(int required, int optional1, double optional2) {
    std::cout << "Required: " << required 
              << ", Optional1: " << optional1 
              << ", Optional2: " << optional2 << "\n";
}

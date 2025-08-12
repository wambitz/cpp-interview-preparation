/*
 * Lambda Functions - Interview Topics
 * 
 * Key Topics to Cover:
 * - Lambda syntax and capture modes
 * - Capture by value vs reference
 * - Mutable lambdas
 * - Generic lambdas
 * - Lambda as function parameters
 * - Closure types
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

// TODO: Implement these helper functions and classes

// Function that takes lambda as parameter
template<typename Func>
void processNumbers(const std::vector<int>& numbers, Func processor);

// Function that returns a lambda
std::function<int(int)> createMultiplier(int factor);

// Class to demonstrate lambda with member variables
class Calculator {
private:
    double base;
    
public:
    Calculator(double b);
    
    auto getAdder() const;
    auto getMultiplier();
    void processWithLambda(const std::vector<double>& values);
};

// Function prototypes for demonstrations
void demonstrateBasicLambda();
void demonstrateCaptureByValue();
void demonstrateCaptureByReference();
void demonstrateMutableLambda();
void demonstrateGenericLambda();
void demonstrateLambdaWithSTL();
void demonstrateLambdaAsParameter();
void demonstrateClosureTypes();

int main() {
    std::cout << "=== Lambda Functions Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicLambda();
    demonstrateCaptureByValue();
    demonstrateCaptureByReference();
    demonstrateMutableLambda();
    demonstrateGenericLambda();
    demonstrateLambdaWithSTL();
    demonstrateLambdaAsParameter();
    demonstrateClosureTypes();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicLambda() {
    std::cout << "1. Basic Lambda Syntax:\n";
    
    // Simple lambda without capture
    auto simpleLambda = []() {
        std::cout << "Hello from lambda!\n";
    };
    
    // Lambda with parameters
    auto addLambda = [](int a, int b) {
        return a + b;
    };
    
    // Lambda with return type specification
    auto divideLambda = [](double a, double b) -> double {
        return (b != 0) ? a / b : 0.0;
    };
    
    // TODO: Call these lambdas and show their usage
    
    std::cout << "---\n\n";
}

void demonstrateCaptureByValue() {
    std::cout << "2. Capture by Value [=]:\n";
    
    int x = 10;
    int y = 20;
    
    // Capture all by value
    auto lambda1 = [=]() {
        std::cout << "Captured x: " << x << ", y: " << y << "\n";
        // x = 15; // Error: cannot modify captured values
    };
    
    // Capture specific variables by value
    auto lambda2 = [x, y](int z) {
        return x + y + z;
    };
    
    // Change original variables
    x = 100;
    y = 200;
    
    // TODO: Show that captured values don't change
    
    std::cout << "---\n\n";
}

void demonstrateCaptureByReference() {
    std::cout << "3. Capture by Reference [&]:\n";
    
    int counter = 0;
    std::string message = "Count: ";
    
    // Capture all by reference
    auto incrementCounter = [&]() {
        counter++;
        std::cout << message << counter << "\n";
    };
    
    // Capture specific variables by reference
    auto modifyMessage = [&message](const std::string& newMsg) {
        message = newMsg;
    };
    
    // TODO: Show how reference capture allows modification
    
    std::cout << "---\n\n";
}

void demonstrateMutableLambda() {
    std::cout << "4. Mutable Lambda:\n";
    
    int value = 42;
    
    // Mutable lambda allows modification of captured-by-value variables
    auto mutableLambda = [value]() mutable {
        value += 10;
        std::cout << "Inside lambda: " << value << "\n";
        return value;
    };
    
    // TODO: Show mutable lambda behavior
    // Original value should remain unchanged
    
    std::cout << "---\n\n";
}

void demonstrateGenericLambda() {
    std::cout << "5. Generic Lambda (auto parameters):\n";
    
    // Generic lambda with auto parameters
    auto genericPrint = [](const auto& value) {
        std::cout << "Value: " << value << " (type: " << typeid(value).name() << ")\n";
    };
    
    // Generic lambda for arithmetic
    auto genericAdd = [](auto a, auto b) {
        return a + b;
    };
    
    // TODO: Use generic lambda with different types
    
    std::cout << "---\n\n";
}

void demonstrateLambdaWithSTL() {
    std::cout << "6. Lambda with STL Algorithms:\n";
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // TODO: Use lambdas with STL algorithms
    // - std::for_each
    // - std::find_if
    // - std::count_if
    // - std::transform
    // - std::sort with custom comparator
    
    // Example: Find even numbers
    auto isEven = [](int n) { return n % 2 == 0; };
    
    // Example: Custom sort
    std::vector<std::string> words = {"apple", "pie", "a", "longer"};
    
    std::cout << "---\n\n";
}

void demonstrateLambdaAsParameter() {
    std::cout << "7. Lambda as Function Parameter:\n";
    
    std::vector<int> data = {1, 2, 3, 4, 5};
    
    // TODO: Pass different lambdas to processNumbers function
    
    // Square each number
    auto squareLambda = [](int x) { std::cout << x * x << " "; };
    
    // Double each number
    auto doubleLambda = [](int x) { std::cout << x * 2 << " "; };
    
    std::cout << "---\n\n";
}

void demonstrateClosureTypes() {
    std::cout << "8. Closure Types and std::function:\n";
    
    // Lambda stored in std::function
    std::function<int(int, int)> operation;
    
    int multiplier = 5;
    
    // Assign different lambdas
    operation = [](int a, int b) { return a + b; };
    // TODO: Show assignment and calling
    
    operation = [multiplier](int a, int b) { return (a + b) * multiplier; };
    // TODO: Show capture in std::function
    
    // Vector of lambdas
    std::vector<std::function<void()>> lambdaVector;
    
    // TODO: Store multiple lambdas and execute them
    
    std::cout << "---\n\n";
}

// TODO: Implement helper functions
template<typename Func>
void processNumbers(const std::vector<int>& numbers, Func processor) {
    std::cout << "Processing: ";
    for (const auto& num : numbers) {
        processor(num);
    }
    std::cout << "\n";
}

std::function<int(int)> createMultiplier(int factor) {
    return [factor](int value) {
        return value * factor;
    };
}

Calculator::Calculator(double b) : base(b) {}

auto Calculator::getAdder() const {
    return [this](double value) {
        return base + value;
    };
}

auto Calculator::getMultiplier() {
    return [this](double value) mutable {
        base *= value;
        return base;
    };
}

void Calculator::processWithLambda(const std::vector<double>& values) {
    auto processor = [this](double value) {
        std::cout << base << " + " << value << " = " << (base + value) << "\n";
    };
    
    for (const auto& val : values) {
        processor(val);
    }
}

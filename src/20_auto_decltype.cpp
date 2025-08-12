/*
 * Auto and Decltype - Interview Topics
 * 
 * Key Topics to Cover:
 * - auto keyword for type deduction
 * - decltype for type queries
 * - auto vs decltype differences
 * - auto with references and pointers
 * - auto in function return types
 * - decltype(auto) usage
 */

#include <iostream>
#include <vector>
#include <type_traits>
#include <string>

// TODO: Implement these functions and classes

// 1. Functions for return type deduction
auto simpleAutoReturn() -> int;
auto autoReturnFromParameter(int value);
decltype(auto) decltypeAutoReturn(int& value);

template<typename Container>
auto getFirst(Container& container) -> decltype(container[0]);

template<typename Container>
decltype(auto) getFirstPerfect(Container&& container);

// 2. Class for demonstrating auto in member functions
class AutoDemo {
private:
    std::vector<int> data;
    
public:
    AutoDemo(std::initializer_list<int> list);
    
    auto size() const -> size_t;
    auto getData() -> std::vector<int>&;
    auto getData() const -> const std::vector<int>&;
    
    template<typename T>
    auto add(T value) -> decltype(data.push_back(value));
};

// 3. Template functions for type deduction
template<typename T, typename U>
auto multiply(T t, U u) -> decltype(t * u);

template<typename T>
auto processValue(T&& value) -> decltype(std::forward<T>(value));

// Function prototypes for demonstrations
void demonstrateBasicAuto();
void demonstrateAutoWithReferences();
void demonstrateAutoWithPointers();
void demonstrateAutoInLoops();
void demonstrateAutoReturnTypes();
void demonstrateDecltype();
void demonstrateDecltypeAuto();
void demonstrateTypeDeductionPitfalls();

int main() {
    std::cout << "=== Auto and Decltype Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicAuto();
    demonstrateAutoWithReferences();
    demonstrateAutoWithPointers();
    demonstrateAutoInLoops();
    demonstrateAutoReturnTypes();
    demonstrateDecltype();
    demonstrateDecltypeAuto();
    demonstrateTypeDeductionPitfalls();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicAuto() {
    std::cout << "1. Basic Auto Type Deduction:\n";
    
    // Basic auto usage
    auto intVar = 42;                    // int
    auto doubleVar = 3.14;              // double
    auto stringVar = std::string("hello"); // std::string
    auto charPtr = "world";             // const char*
    
    // TODO: Show type information
    // Print types using typeid or template techniques
    // Show auto deduction rules
    
    std::cout << "---\n\n";
}

void demonstrateAutoWithReferences() {
    std::cout << "2. Auto with References:\n";
    
    int value = 42;
    int& ref = value;
    const int& constRef = value;
    
    auto autoValue = ref;        // int (reference removed)
    auto& autoRef = ref;         // int&
    const auto& autoConstRef = value; // const int&
    
    // TODO: Show how auto handles references
    // Reference collapsing rules
    // const preservation
    
    std::cout << "---\n\n";
}

void demonstrateAutoWithPointers() {
    std::cout << "3. Auto with Pointers:\n";
    
    int value = 100;
    int* ptr = &value;
    const int* constPtr = &value;
    int* const ptrConst = &value;
    
    auto autoPtr = ptr;          // int*
    auto autoConstPtr = constPtr; // const int*
    auto autoPtrConst = ptrConst; // int*
    
    // TODO: Show auto with different pointer types
    // Const preservation with pointers
    
    std::cout << "---\n\n";
}

void demonstrateAutoInLoops() {
    std::cout << "4. Auto in Range-based For Loops:\n";
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<std::string> words = {"hello", "world", "cpp"};
    
    // TODO: Show different auto usage in loops
    // for (auto item : container)        // copy
    // for (auto& item : container)       // reference
    // for (const auto& item : container) // const reference
    
    std::cout << "---\n\n";
}

void demonstrateAutoReturnTypes() {
    std::cout << "5. Auto Return Types:\n";
    
    // TODO: Call functions with auto return types
    // Show trailing return type syntax
    // Show how return type is deduced
    
    std::cout << "---\n\n";
}

void demonstrateDecltype() {
    std::cout << "6. Decltype Usage:\n";
    
    int x = 5;
    int& y = x;
    const int z = 10;
    
    // TODO: Show decltype with different expressions
    // decltype(x)     // int
    // decltype(y)     // int&
    // decltype(z)     // const int
    // decltype((x))   // int& (parentheses make it lvalue expression)
    
    // decltype with function calls
    // decltype with array access
    
    std::cout << "---\n\n";
}

void demonstrateDecltypeAuto() {
    std::cout << "7. Decltype(auto):\n";
    
    int x = 42;
    int& ref = x;
    
    // TODO: Show difference between auto and decltype(auto)
    // auto strips references, decltype(auto) preserves them
    // Perfect forwarding scenarios
    
    std::cout << "---\n\n";
}

void demonstrateTypeDeductionPitfalls() {
    std::cout << "8. Type Deduction Pitfalls:\n";
    
    // TODO: Show common mistakes
    // auto with initializer lists
    // auto with function templates
    // Unexpected type deductions
    
    // Initializer list pitfall
    // auto list1 = {1, 2, 3};    // std::initializer_list<int>
    // auto list2{1, 2, 3};       // Error in C++17
    
    // Array decay
    int arr[5] = {1, 2, 3, 4, 5};
    auto autoArr = arr;          // int* (array decays to pointer)
    auto& autoArrRef = arr;      // int(&)[5] (reference preserves array type)
    
    std::cout << "---\n\n";
}

// TODO: Implement helper functions
auto simpleAutoReturn() -> int {
    return 42;
}

auto autoReturnFromParameter(int value) {
    return value * 2;  // Return type deduced as int
}

decltype(auto) decltypeAutoReturn(int& value) {
    return value;  // Returns int& (preserves reference)
}

template<typename Container>
auto getFirst(Container& container) -> decltype(container[0]) {
    return container[0];
}

template<typename Container>
decltype(auto) getFirstPerfect(Container&& container) {
    return std::forward<Container>(container)[0];
}

AutoDemo::AutoDemo(std::initializer_list<int> list) : data(list) {}

auto AutoDemo::size() const -> size_t {
    return data.size();
}

auto AutoDemo::getData() -> std::vector<int>& {
    return data;
}

auto AutoDemo::getData() const -> const std::vector<int>& {
    return data;
}

template<typename T, typename U>
auto multiply(T t, U u) -> decltype(t * u) {
    return t * u;
}

template<typename T>
auto processValue(T&& value) -> decltype(std::forward<T>(value)) {
    return std::forward<T>(value);
}

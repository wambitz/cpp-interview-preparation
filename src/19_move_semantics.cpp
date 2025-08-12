/*
 * Move Semantics - Interview Topics
 * 
 * Key Topics to Cover:
 * - lvalue vs rvalue
 * - Move constructor and move assignment
 * - std::move and std::forward
 * - Perfect forwarding
 * - Return value optimization (RVO)
 * - Move-only types
 */

#include <iostream>
#include <utility>
#include <vector>
#include <string>

// TODO: Implement these classes

// 1. Basic Move Semantics Demo
class MyString {
private:
    char* data;
    size_t size;
    
public:
    // TODO: Implement all constructors and operators
    MyString();                                    // Default constructor
    MyString(const char* str);                     // Constructor from C-string
    MyString(const MyString& other);               // Copy constructor
    MyString(MyString&& other) noexcept;           // Move constructor
    MyString& operator=(const MyString& other);    // Copy assignment
    MyString& operator=(MyString&& other) noexcept; // Move assignment
    ~MyString();                                   // Destructor
    
    // Utility functions
    void print() const;
    size_t length() const;
    const char* c_str() const;
};

// 2. Move-Only Type (like unique_ptr)
class MoveOnlyResource {
private:
    int* data;
    std::string name;
    
public:
    // TODO: Implement move-only semantics
    explicit MoveOnlyResource(const std::string& name);
    
    // Delete copy operations
    MoveOnlyResource(const MoveOnlyResource&) = delete;
    MoveOnlyResource& operator=(const MoveOnlyResource&) = delete;
    
    // Enable move operations
    MoveOnlyResource(MoveOnlyResource&& other) noexcept;
    MoveOnlyResource& operator=(MoveOnlyResource&& other) noexcept;
    
    ~MoveOnlyResource();
    
    void useResource() const;
    const std::string& getName() const;
};

// 3. Perfect Forwarding Demo
class Logger {
public:
    template<typename T>
    void log(T&& message);  // TODO: Implement perfect forwarding
    
    template<typename... Args>
    void logMultiple(Args&&... args);  // TODO: Variadic perfect forwarding
};

// 4. RVO/NRVO Demonstration
class Expensive {
private:
    std::vector<int> data;
    std::string name;
    
public:
    Expensive(const std::string& name, size_t size);
    Expensive(const Expensive& other);
    Expensive(Expensive&& other) noexcept;
    ~Expensive();
    
    void display() const;
};

// TODO: Implement functions showing RVO
Expensive createExpensive(const std::string& name);  // RVO case
Expensive createExpensiveConditional(bool condition);  // NRVO case

// 5. Universal Reference vs Rvalue Reference
template<typename T>
void processValue(T&& value);  // TODO: Universal reference

void processRvalue(int&& value);  // TODO: Rvalue reference

// Function prototypes for demonstrations
void demonstrateLvalueRvalue();
void demonstrateMoveConstructor();
void demonstrateMoveAssignment();
void demonstrateStdMove();
void demonstratePerfectForwarding();
void demonstrateRVO();
void demonstrateMoveOnlyTypes();
void demonstrateUniversalReferences();

int main() {
    std::cout << "=== Move Semantics Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateLvalueRvalue();
    demonstrateMoveConstructor();
    demonstrateMoveAssignment();
    demonstrateStdMove();
    demonstratePerfectForwarding();
    demonstrateRVO();
    demonstrateMoveOnlyTypes();
    demonstrateUniversalReferences();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateLvalueRvalue() {
    std::cout << "1. Lvalue vs Rvalue:\n";
    // Show difference between lvalues and rvalues
    // Demonstrate value categories
    std::cout << "---\n\n";
}

void demonstrateMoveConstructor() {
    std::cout << "2. Move Constructor:\n";
    // Create objects and show move construction
    // Compare with copy construction performance
    std::cout << "---\n\n";
}

void demonstrateMoveAssignment() {
    std::cout << "3. Move Assignment:\n";
    // Show move assignment operator
    // Self-assignment handling
    std::cout << "---\n\n";
}

void demonstrateStdMove() {
    std::cout << "4. std::move Usage:\n";
    // Show when and how to use std::move
    // Demonstrate transfer of ownership
    std::cout << "---\n\n";
}

void demonstratePerfectForwarding() {
    std::cout << "5. Perfect Forwarding:\n";
    // Use Logger class to show forwarding
    // Preserve value categories
    std::cout << "---\n\n";
}

void demonstrateRVO() {
    std::cout << "6. Return Value Optimization:\n";
    // Show RVO and NRVO in action
    // Compare with and without optimization
    std::cout << "---\n\n";
}

void demonstrateMoveOnlyTypes() {
    std::cout << "7. Move-Only Types:\n";
    // Create and transfer move-only resources
    // Show usage patterns
    std::cout << "---\n\n";
}

void demonstrateUniversalReferences() {
    std::cout << "8. Universal vs Rvalue References:\n";
    // Show difference between T&& and specific&&
    // Demonstrate reference collapsing
    std::cout << "---\n\n";
}

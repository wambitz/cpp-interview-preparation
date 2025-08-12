/*
 * Const Correctness - Interview Topics
 * 
 * Key Topics to Cover:
 * - const variables and functions
 * - const member functions
 * - const parameters and return types
 * - mutable keyword
 * - const_cast usage
 * - Logical vs bitwise const
 */

#include <iostream>
#include <string>

// TODO: Implement these classes and functions

// 1. Class demonstrating const member functions
class BankAccount {
private:
    std::string accountNumber;
    double balance;
    mutable int accessCount;  // mutable for logical const
    
public:
    BankAccount(const std::string& accNum, double initialBalance);
    
    // Const member functions
    double getBalance() const;
    const std::string& getAccountNumber() const;
    void displayInfo() const;
    int getAccessCount() const;
    
    // Non-const member functions
    void deposit(double amount);
    bool withdraw(double amount);
    void setAccountNumber(const std::string& newNum);
};

// 2. Class demonstrating const overloading
class StringContainer {
private:
    std::string data;
    
public:
    StringContainer(const std::string& str);
    
    // Const overloading - different return types for const/non-const objects
    char& at(size_t index);              // Non-const version
    const char& at(size_t index) const;  // Const version
    
    // Const member functions
    size_t length() const;
    bool empty() const;
    const std::string& getData() const;
    
    // Non-const member functions
    void setData(const std::string& newData);
    void append(const std::string& suffix);
};

// 3. Functions demonstrating const parameters
class ConstParameterDemo {
public:
    // Different const parameter types
    void passByValue(int value);                    // No const needed for by-value
    void passByConstValue(const int value);         // Rarely used
    void passByReference(int& ref);                 // Can modify
    void passByConstReference(const int& constRef); // Cannot modify
    void passByPointer(int* ptr);                   // Can modify through pointer
    void passByConstPointer(const int* constPtr);   // Cannot modify through pointer
    void passByPointerToConst(int* const ptr);      // Cannot reassign pointer
    void passByConstPointerToConst(const int* const ptr); // Neither modify nor reassign
};

// 4. Const return types
class ConstReturnDemo {
private:
    std::string name;
    int value;
    
public:
    ConstReturnDemo(const std::string& n, int v);
    
    // Const return by value (usually not needed)
    const int getValue() const;
    
    // Const reference return (common pattern)
    const std::string& getName() const;
    
    // Non-const reference return
    std::string& getNameRef();
    
    // Const pointer return
    const int* getValuePtr() const;
};

// 5. Demonstrating const_cast
class ConstCastDemo {
private:
    mutable bool cached;
    mutable double cachedResult;
    std::string data;
    
public:
    ConstCastDemo(const std::string& d);
    
    // Function that needs to modify mutable members in const context
    double expensiveCalculation() const;
    
    // Function showing const_cast usage (should be rare)
    void demonstrateConstCast() const;
};

// Function prototypes for demonstrations
void demonstrateConstVariables();
void demonstrateConstMemberFunctions();
void demonstrateConstOverloading();
void demonstrateConstParameters();
void demonstrateConstReturnTypes();
void demonstrateMutableKeyword();
void demonstrateConstCast();
void demonstrateLogicalVsBitwiseConst();

int main() {
    std::cout << "=== Const Correctness Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateConstVariables();
    demonstrateConstMemberFunctions();
    demonstrateConstOverloading();
    demonstrateConstParameters();
    demonstrateConstReturnTypes();
    demonstrateMutableKeyword();
    demonstrateConstCast();
    demonstrateLogicalVsBitwiseConst();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateConstVariables() {
    std::cout << "1. Const Variables:\n";
    
    const int constInt = 42;
    // constInt = 50; // Error: cannot modify const variable
    
    int normalInt = 10;
    const int& constRef = normalInt;
    // constRef = 20; // Error: cannot modify through const reference
    
    const int* constPtr = &normalInt;
    // *constPtr = 30; // Error: cannot modify through const pointer
    
    int* const ptrConst = &normalInt;
    *ptrConst = 40; // OK: can modify value
    // ptrConst = &constInt; // Error: cannot reassign const pointer
    
    // TODO: Show different const scenarios
    
    std::cout << "---\n\n";
}

void demonstrateConstMemberFunctions() {
    std::cout << "2. Const Member Functions:\n";
    
    BankAccount account("12345", 1000.0);
    const BankAccount constAccount("67890", 2000.0);
    
    // TODO: Show const member function calls
    // const objects can only call const member functions
    
    std::cout << "---\n\n";
}

void demonstrateConstOverloading() {
    std::cout << "3. Const Overloading:\n";
    
    StringContainer container("Hello World");
    const StringContainer constContainer("Const Hello");
    
    // TODO: Show how const and non-const versions are called
    // Non-const object calls non-const version
    // Const object calls const version
    
    std::cout << "---\n\n";
}

void demonstrateConstParameters() {
    std::cout << "4. Const Parameters:\n";
    
    ConstParameterDemo demo;
    int value = 42;
    
    // TODO: Show different parameter passing methods
    // Show which ones can modify the argument
    
    std::cout << "---\n\n";
}

void demonstrateConstReturnTypes() {
    std::cout << "5. Const Return Types:\n";
    
    ConstReturnDemo demo("Test", 100);
    const ConstReturnDemo constDemo("ConstTest", 200);
    
    // TODO: Show const return type usage
    // When to return const vs non-const
    
    std::cout << "---\n\n";
}

void demonstrateMutableKeyword() {
    std::cout << "6. Mutable Keyword:\n";
    
    const BankAccount account("MUTABLE", 5000.0);
    
    // TODO: Show how mutable members can be modified in const functions
    // Logical const vs bitwise const
    
    std::cout << "---\n\n";
}

void demonstrateConstCast() {
    std::cout << "7. const_cast Usage:\n";
    
    const ConstCastDemo demo("ConstCast Data");
    
    // TODO: Show const_cast usage (should be rare and carefully considered)
    // When it might be needed
    // Dangers of const_cast
    
    std::cout << "---\n\n";
}

void demonstrateLogicalVsBitwiseConst() {
    std::cout << "8. Logical vs Bitwise Const:\n";
    
    // TODO: Explain the difference
    // Bitwise const: no bit in the object changes
    // Logical const: object's observable state doesn't change
    // mutable keyword enables logical const
    
    std::cout << "---\n\n";
}

// TODO: Implement all class methods

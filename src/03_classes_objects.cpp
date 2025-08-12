/*
 * Classes and Objects - Interview Topics
 * 
 * Key Topics to Cover:
 * - Class definition and object creation
 * - Constructors and destructors
 * - Member variables and functions
 * - Access specifiers (private, protected, public)
 * - Static members
 * - Default constructor, copy constructor, assignment operator
 * - Rule of Three/Five/Zero
 */

#include <iostream>
#include <string>

// TODO: Implement these classes

// 1. Basic Class Structure
class Person {
private:
    std::string name;
    int age;
    static int personCount;  // TODO: Implement static member
    
public:
    // TODO: Implement constructors
    Person();  // Default constructor
    Person(const std::string& name, int age);  // Parameterized constructor
    Person(const Person& other);  // Copy constructor
    
    // TODO: Implement assignment operator
    Person& operator=(const Person& other);
    
    // TODO: Implement destructor
    ~Person();
    
    // TODO: Implement member functions
    void displayInfo() const;
    void setAge(int newAge);
    int getAge() const;
    const std::string& getName() const;
    
    // TODO: Implement static member functions
    static int getPersonCount();
    static void displayPersonCount();
};

// 2. Rule of Three/Five Demonstration
class ResourceManager {
private:
    int* data;
    size_t size;
    
public:
    // TODO: Implement Rule of Five
    ResourceManager(size_t size);           // Constructor
    ~ResourceManager();                      // Destructor
    ResourceManager(const ResourceManager& other);  // Copy constructor
    ResourceManager& operator=(const ResourceManager& other);  // Copy assignment
    ResourceManager(ResourceManager&& other) noexcept;  // Move constructor
    ResourceManager& operator=(ResourceManager&& other) noexcept;  // Move assignment
    
    // TODO: Utility functions
    void display() const;
    size_t getSize() const;
    void setValue(size_t index, int value);
};

// 3. Access Specifiers Demo
class AccessDemo {
private:
    int privateVar;
    
protected:
    int protectedVar;
    
public:
    int publicVar;
    
    AccessDemo();
    
    // TODO: Implement methods showing access levels
    void demonstrateAccess();
    void setPrivateVar(int value);
    int getPrivateVar() const;
};

// 4. Static Members Demo
class BankAccount {
private:
    std::string accountNumber;
    double balance;
    static double interestRate;  // TODO: Implement static member
    static int totalAccounts;    // TODO: Implement static counter
    
public:
    BankAccount(const std::string& accNum, double initialBalance);
    ~BankAccount();
    
    // TODO: Implement member functions
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    
    // TODO: Implement static functions
    static void setInterestRate(double rate);
    static double getInterestRate();
    static int getTotalAccounts();
};

// 5. Const Correctness in Classes
class ConstDemo {
private:
    int value;
    mutable int cacheValue;  // TODO: Demonstrate mutable keyword
    
public:
    ConstDemo(int val);
    
    // TODO: Implement const and non-const versions
    int getValue() const;
    void setValue(int val);
    void expensiveOperation() const;  // Uses mutable member
    
    // TODO: Const overloading
    int& getValueRef();              // Non-const version
    const int& getValueRef() const;  // Const version
};

// Function prototypes for demonstrations
void demonstrateBasicClass();
void demonstrateRuleOfFive();
void demonstrateAccessSpecifiers();
void demonstrateStaticMembers();
void demonstrateConstCorrectness();
void demonstrateObjectLifetime();

int main() {
    std::cout << "=== Classes and Objects Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicClass();
    demonstrateRuleOfFive();
    demonstrateAccessSpecifiers();
    demonstrateStaticMembers();
    demonstrateConstCorrectness();
    demonstrateObjectLifetime();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicClass() {
    std::cout << "1. Basic Class Usage:\n";
    // Create Person objects using different constructors
    // Show copy constructor and assignment operator
    std::cout << "---\n\n";
}

void demonstrateRuleOfFive() {
    std::cout << "2. Rule of Three/Five:\n";
    // Create ResourceManager objects
    // Show deep copy vs shallow copy
    // Demonstrate move semantics
    std::cout << "---\n\n";
}

void demonstrateAccessSpecifiers() {
    std::cout << "3. Access Specifiers:\n";
    // Show public, private, protected access
    std::cout << "---\n\n";
}

void demonstrateStaticMembers() {
    std::cout << "4. Static Members:\n";
    // Create multiple BankAccount objects
    // Show static variable sharing
    std::cout << "---\n\n";
}

void demonstrateConstCorrectness() {
    std::cout << "5. Const Correctness:\n";
    // Create const and non-const objects
    // Show const member function usage
    std::cout << "---\n\n";
}

void demonstrateObjectLifetime() {
    std::cout << "6. Object Lifetime:\n";
    // Show constructor/destructor call order
    // Stack vs heap object creation
    std::cout << "---\n\n";
}

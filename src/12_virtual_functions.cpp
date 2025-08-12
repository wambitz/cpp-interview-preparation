/*
 * Virtual Functions - Interview Topics
 * 
 * Key Topics to Cover:
 * - Virtual function mechanism
 * - Virtual table (vtable) concept
 * - Pure virtual functions
 * - Virtual destructors
 * - Virtual function performance
 * - Override and final keywords
 */

#include <iostream>
#include <memory>

// TODO: Implement these classes and functions

// 1. Basic Virtual Function Demonstration
class Animal {
public:
    // TODO: Implement virtual function
    virtual void makeSound() const;
    
    // TODO: Implement virtual destructor
    virtual ~Animal();
};

class Dog : public Animal {
public:
    // TODO: Override makeSound (use override keyword)
    void makeSound() const override;
};

class Cat : public Animal {
public:
    // TODO: Override makeSound (use override keyword)
    void makeSound() const override;
};

// 2. Pure Virtual Function (Abstract Base Class)
class Shape {
public:
    // TODO: Make this pure virtual
    virtual double area() const = 0;
    virtual void draw() const = 0;
    
    // TODO: Virtual destructor for abstract class
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h);
    
    // TODO: Implement pure virtual functions
    double area() const override;
    void draw() const override;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r);
    
    // TODO: Implement pure virtual functions
    double area() const override;
    void draw() const override;
};

// 3. Virtual Destructor Necessity Demo
class Base {
public:
    Base();
    // TODO: Make destructor virtual (comment/uncomment to see difference)
    virtual ~Base();
};

class Derived : public Base {
private:
    int* data;
public:
    Derived();
    ~Derived();
};

// 4. Final keyword demonstration
class FinalClass final {
public:
    virtual void method();
};

// TODO: Try to inherit from FinalClass (should cause compile error)
// class CannotInherit : public FinalClass { };

class BaseWithFinalMethod {
public:
    virtual void normalMethod();
    virtual void finalMethod() final;
    virtual ~BaseWithFinalMethod() = default;
};

class DerivedFromBase : public BaseWithFinalMethod {
public:
    void normalMethod() override;
    // TODO: Try to override finalMethod (should cause compile error)
    // void finalMethod() override;
};

// Function prototypes for demonstrations
void demonstrateVirtualFunctions();
void demonstratePureVirtualFunctions();
void demonstrateVirtualDestructor();
void demonstrateFinalKeyword();
void demonstrateVirtualCallResolution();

int main() {
    std::cout << "=== Virtual Functions Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateVirtualFunctions();
    demonstratePureVirtualFunctions();
    demonstrateVirtualDestructor();
    demonstrateFinalKeyword();
    demonstrateVirtualCallResolution();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateVirtualFunctions() {
    std::cout << "1. Virtual Function Demonstration:\n";
    // Create Animal pointers pointing to Dog and Cat objects
    // Show polymorphic behavior
    std::cout << "---\n\n";
}

void demonstratePureVirtualFunctions() {
    std::cout << "2. Pure Virtual Functions (Abstract Classes):\n";
    // Create Shape pointers pointing to Rectangle and Circle
    // Show that you cannot instantiate Shape directly
    std::cout << "---\n\n";
}

void demonstrateVirtualDestructor() {
    std::cout << "3. Virtual Destructor Necessity:\n";
    // Show what happens with and without virtual destructor
    // Use smart pointers to demonstrate proper cleanup
    std::cout << "---\n\n";
}

void demonstrateFinalKeyword() {
    std::cout << "4. Final Keyword:\n";
    // Show final class and final method usage
    std::cout << "---\n\n";
}

void demonstrateVirtualCallResolution() {
    std::cout << "5. Virtual Function Call Resolution:\n";
    // Demonstrate early vs late binding
    // Show vtable concept in action
    std::cout << "---\n\n";
}

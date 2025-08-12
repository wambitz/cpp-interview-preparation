/*
 * Polymorphism - Interview Topics
 * 
 * Key Topics to Cover:
 * - Runtime vs compile-time polymorphism
 * - Virtual functions and vtable
 * - Pure virtual functions and abstract classes
 * - Function overriding vs overloading
 * - Virtual destructors
 * - Dynamic binding
 */

#include <iostream>
#include <vector>
#include <memory>

// TODO: Implement these classes

// 1. Abstract Base Class (Pure Virtual Functions)
class Shape {
protected:
    std::string name;
    
public:
    Shape(const std::string& name);
    virtual ~Shape() = default;
    
    // Pure virtual functions
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;
    
    // Non-pure virtual function
    virtual void displayInfo() const;
    const std::string& getName() const;
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h);
    
    double area() const override;
    double perimeter() const override;
    void draw() const override;
    void displayInfo() const override;
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r);
    
    double area() const override;
    double perimeter() const override;
    void draw() const override;
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
    
public:
    Triangle(double s1, double s2, double s3);
    
    double area() const override;
    double perimeter() const override;
    void draw() const override;
};

// 2. Compile-time Polymorphism (Function Overloading)
class MathOperations {
public:
    // Function overloading - compile-time polymorphism
    int add(int a, int b);
    double add(double a, double b);
    std::string add(const std::string& a, const std::string& b);
    
    // Template function - compile-time polymorphism
    template<typename T>
    T multiply(T a, T b);
};

// 3. Runtime Polymorphism with Virtual Functions
class Animal {
protected:
    std::string species;
    
public:
    Animal(const std::string& species);
    virtual ~Animal();
    
    virtual void makeSound() const;
    virtual void move() const;
    virtual void eat() const;
    
    const std::string& getSpecies() const;
};

class Dog : public Animal {
public:
    Dog();
    ~Dog();
    
    void makeSound() const override;
    void move() const override;
    void eat() const override;
    
    void wagTail() const;  // Dog-specific method
};

class Cat : public Animal {
public:
    Cat();
    ~Cat();
    
    void makeSound() const override;
    void move() const override;
    void eat() const override;
    
    void purr() const;  // Cat-specific method
};

class Bird : public Animal {
public:
    Bird();
    ~Bird();
    
    void makeSound() const override;
    void move() const override;
    void eat() const override;
    
    void fly() const;  // Bird-specific method
};

// 4. Virtual Destructor Demonstration
class Base {
protected:
    int* data;
    
public:
    Base();
    virtual ~Base();  // Virtual destructor is crucial
    
    virtual void doSomething() const;
};

class Derived : public Base {
private:
    double* moreData;
    
public:
    Derived();
    ~Derived();
    
    void doSomething() const override;
    void derivedSpecific() const;
};

// Function prototypes for demonstrations
void demonstrateAbstractClasses();
void demonstrateCompileTimePolymorphism();
void demonstrateRuntimePolymorphism();
void demonstrateVirtualDestructor();
void demonstratePolymorphicContainers();
void demonstrateDynamicBinding();
void demonstrateOverridingVsOverloading();

int main() {
    std::cout << "=== Polymorphism Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateAbstractClasses();
    demonstrateCompileTimePolymorphism();
    demonstrateRuntimePolymorphism();
    demonstrateVirtualDestructor();
    demonstratePolymorphicContainers();
    demonstrateDynamicBinding();
    demonstrateOverridingVsOverloading();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateAbstractClasses() {
    std::cout << "1. Abstract Classes and Pure Virtual Functions:\n";
    // Cannot instantiate Shape directly
    // Create concrete shapes and use polymorphically
    
    std::cout << "---\n\n";
}

void demonstrateCompileTimePolymorphism() {
    std::cout << "2. Compile-time Polymorphism:\n";
    // Function overloading
    // Template instantiation
    // Resolved at compile time
    
    std::cout << "---\n\n";
}

void demonstrateRuntimePolymorphism() {
    std::cout << "3. Runtime Polymorphism:\n";
    // Virtual function calls
    // Dynamic dispatch through vtable
    // Resolved at runtime
    
    std::cout << "---\n\n";
}

void demonstrateVirtualDestructor() {
    std::cout << "4. Virtual Destructor:\n";
    // Show proper cleanup with virtual destructor
    // Compare with non-virtual destructor problems
    
    std::cout << "---\n\n";
}

void demonstratePolymorphicContainers() {
    std::cout << "5. Polymorphic Containers:\n";
    // Store different derived objects in base pointer container
    // Process them polymorphically
    
    std::cout << "---\n\n";
}

void demonstrateDynamicBinding() {
    std::cout << "6. Dynamic Binding:\n";
    // Show early vs late binding
    // Virtual function call mechanism
    
    std::cout << "---\n\n";
}

void demonstrateOverridingVsOverloading() {
    std::cout << "7. Overriding vs Overloading:\n";
    // Show the difference between the two concepts
    // Function signatures and virtual keyword
    
    std::cout << "---\n\n";
}

// TODO: Implement all the class methods
Shape::Shape(const std::string& name) : name(name) {}

void Shape::displayInfo() const {
    std::cout << "Shape: " << name << ", Area: " << area() 
              << ", Perimeter: " << perimeter() << "\n";
}

const std::string& Shape::getName() const {
    return name;
}

Rectangle::Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::draw() const {
    std::cout << "Drawing a rectangle " << width << "x" << height << "\n";
}

void Rectangle::displayInfo() const {
    std::cout << "Rectangle: " << width << "x" << height 
              << ", Area: " << area() << ", Perimeter: " << perimeter() << "\n";
}

// TODO: Continue implementing other classes...

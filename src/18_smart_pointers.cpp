/*
 * Smart Pointers - Interview Topics
 * 
 * Key Topics to Cover:
 * - unique_ptr, shared_ptr, weak_ptr
 * - RAII principle with smart pointers
 * - Circular reference problem
 * - Custom deleters
 * - Performance implications
 * - When to use each type
 */

#include <iostream>
#include <memory>
#include <vector>

// TODO: Implement these classes for demonstrations

// 1. Basic Resource Class for Testing
class Resource {
private:
    std::string name;
    int id;
    static int resourceCount;
    
public:
    Resource(const std::string& name, int id);
    ~Resource();
    
    void doWork() const;
    const std::string& getName() const;
    int getId() const;
    static int getResourceCount();
};

// 2. Custom Deleter Example
class FileHandle {
private:
    std::string filename;
    
public:
    FileHandle(const std::string& filename);
    ~FileHandle();
    
    void write(const std::string& data);
    void read();
};

// Custom deleter function
struct FileDeleter {
    void operator()(FileHandle* ptr) const;
};

// 3. Circular Reference Problem Demo
class Parent;
class Child;

class Parent {
private:
    std::string name;
    std::vector<std::shared_ptr<Child>> children;
    
public:
    Parent(const std::string& name);
    ~Parent();
    
    void addChild(std::shared_ptr<Child> child);
    void showChildren() const;
    const std::string& getName() const;
};

class Child {
private:
    std::string name;
    std::weak_ptr<Parent> parent;  // TODO: Use weak_ptr to break cycle
    
public:
    Child(const std::string& name);
    ~Child();
    
    void setParent(std::shared_ptr<Parent> parent);
    void showParent() const;
    const std::string& getName() const;
};

// 4. Factory Pattern with Smart Pointers
class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h);
    void draw() const override;
    double area() const override;
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r);
    void draw() const override;
    double area() const override;
};

// TODO: Implement factory functions
std::unique_ptr<Shape> createRectangle(double width, double height);
std::unique_ptr<Shape> createCircle(double radius);

// Function prototypes for demonstrations
void demonstrateUniquePtr();
void demonstrateSharedPtr();
void demonstrateWeakPtr();
void demonstrateCustomDeleter();
void demonstrateCircularReference();
void demonstrateFactoryPattern();
void demonstratePerformanceComparison();

int main() {
    std::cout << "=== Smart Pointers Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateUniquePtr();
    demonstrateSharedPtr();
    demonstrateWeakPtr();
    demonstrateCustomDeleter();
    demonstrateCircularReference();
    demonstrateFactoryPattern();
    demonstratePerformanceComparison();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateUniquePtr() {
    std::cout << "1. unique_ptr Usage:\n";
    // Create unique_ptr with make_unique
    // Show transfer of ownership with std::move
    // Demonstrate automatic cleanup
    std::cout << "---\n\n";
}

void demonstrateSharedPtr() {
    std::cout << "2. shared_ptr Usage:\n";
    // Create shared_ptr with make_shared
    // Show reference counting
    // Multiple owners scenario
    std::cout << "---\n\n";
}

void demonstrateWeakPtr() {
    std::cout << "3. weak_ptr Usage:\n";
    // Create weak_ptr from shared_ptr
    // Check if object still exists with lock()
    // Show non-owning reference
    std::cout << "---\n\n";
}

void demonstrateCustomDeleter() {
    std::cout << "4. Custom Deleters:\n";
    // Use custom deleter with unique_ptr
    // Show specialized cleanup behavior
    std::cout << "---\n\n";
}

void demonstrateCircularReference() {
    std::cout << "5. Circular Reference Problem:\n";
    // Create Parent-Child relationship
    // Show memory leak with shared_ptr cycle
    // Solve with weak_ptr
    std::cout << "---\n\n";
}

void demonstrateFactoryPattern() {
    std::cout << "6. Factory Pattern with Smart Pointers:\n";
    // Use factory functions to create objects
    // Store in containers of smart pointers
    std::cout << "---\n\n";
}

void demonstratePerformanceComparison() {
    std::cout << "7. Performance Considerations:\n";
    // Compare raw pointer vs smart pointer overhead
    // Show when to use each type
    std::cout << "---\n\n";
}

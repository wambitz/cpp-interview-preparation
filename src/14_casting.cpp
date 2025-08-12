/*
 * Casting in C++ - Interview Topics
 * 
 * Key Topics to Cover:
 * - C-style casting vs C++ casting
 * - static_cast, dynamic_cast, const_cast, reinterpret_cast
 * - Safe vs unsafe casting
 * - Polymorphic casting with dynamic_cast
 * - Const correctness with const_cast
 * - Low-level casting with reinterpret_cast
 */

#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>

// TODO: Implement these classes for casting demonstrations

// Base class hierarchy for polymorphic casting
class Shape {
protected:
    std::string name;
    
public:
    Shape(const std::string& n) : name(n) {}
    virtual ~Shape() = default;  // Virtual destructor for polymorphism
    
    virtual void draw() const = 0;
    virtual double area() const = 0;
    virtual std::string getName() const { return name; }
    
    // Virtual function to identify type
    virtual std::string getType() const { return "Shape"; }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(const std::string& n, double r) : Shape(n), radius(r) {}
    
    void draw() const override {
        std::cout << "Drawing circle: " << name << " with radius " << radius << "\n";
    }
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    std::string getType() const override { return "Circle"; }
    
    // Circle-specific method
    double getRadius() const { return radius; }
    void setRadius(double r) { radius = r; }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(const std::string& n, double w, double h) : Shape(n), width(w), height(h) {}
    
    void draw() const override {
        std::cout << "Drawing rectangle: " << name << " " << width << "x" << height << "\n";
    }
    
    double area() const override {
        return width * height;
    }
    
    std::string getType() const override { return "Rectangle"; }
    
    // Rectangle-specific methods
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    void resize(double w, double h) { width = w; height = h; }
};

// Non-polymorphic classes for static_cast demonstration
class Base {
protected:
    int value;
    
public:
    Base(int v = 0) : value(v) {}
    virtual ~Base() = default;
    
    int getValue() const { return value; }
    void setValue(int v) { value = v; }
    
    virtual void print() const {
        std::cout << "Base value: " << value << "\n";
    }
};

class Derived : public Base {
private:
    std::string extra;
    
public:
    Derived(int v = 0, const std::string& e = "") : Base(v), extra(e) {}
    
    const std::string& getExtra() const { return extra; }
    void setExtra(const std::string& e) { extra = e; }
    
    void print() const override {
        std::cout << "Derived value: " << value << ", extra: " << extra << "\n";
    }
};

// Function prototypes for demonstrations
void demonstrateStaticCast();
void demonstrateDynamicCast();
void demonstrateConstCast();
void demonstrateReinterpretCast();
void demonstrateCStyleCast();
void demonstrateCastSafety();
void demonstratePolymorphicCasting();
void demonstrateNumericCasting();
void demonstrateCastingBestPractices();

int main() {
    std::cout << "=== C++ Casting Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateStaticCast();
    demonstrateDynamicCast();
    demonstrateConstCast();
    demonstrateReinterpretCast();
    demonstrateCStyleCast();
    demonstrateCastSafety();
    demonstratePolymorphicCasting();
    demonstrateNumericCasting();
    demonstrateCastingBestPractices();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateStaticCast() {
    std::cout << "1. static_cast Examples:\n";
    
    // TODO: Show static_cast usage
    
    // Numeric conversions
    double pi = 3.14159;
    int intPi = static_cast<int>(pi);
    std::cout << "double to int: " << pi << " -> " << intPi << "\n";
    
    // Pointer conversions in inheritance hierarchy
    Derived derived(42, "Hello");
    Base* basePtr = static_cast<Base*>(&derived);  // Upcast (safe)
    basePtr->print();
    
    // Downcast (potentially unsafe, but we know the type)
    Base* basePtrToBase = &derived;
    Derived* derivedPtr = static_cast<Derived*>(basePtrToBase);
    derivedPtr->print();
    
    // Void pointer casting
    void* voidPtr = static_cast<void*>(&derived);
    Derived* backToDerived = static_cast<Derived*>(voidPtr);
    backToDerived->print();
    
    // Enum conversions
    enum Color { RED = 0, GREEN = 1, BLUE = 2 };
    int colorValue = static_cast<int>(GREEN);
    Color colorFromInt = static_cast<Color>(1);
    std::cout << "Enum to int: " << colorValue << ", int to enum: " << colorFromInt << "\n";
    
    std::cout << "---\n\n";
}

void demonstrateDynamicCast() {
    std::cout << "2. dynamic_cast Examples:\n";
    
    // TODO: Show dynamic_cast with polymorphic types
    
    // Create objects
    std::unique_ptr<Shape> circle = std::make_unique<Circle>("Circle1", 5.0);
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>("Rect1", 10.0, 20.0);
    
    // Store in base pointer array
    Shape* shapes[] = {circle.get(), rectangle.get()};
    
    for (int i = 0; i < 2; ++i) {
        std::cout << "Shape " << i << ": " << shapes[i]->getType() << "\n";
        
        // Try to cast to Circle
        Circle* circlePtr = dynamic_cast<Circle*>(shapes[i]);
        if (circlePtr) {
            std::cout << "  -> Is a Circle with radius: " << circlePtr->getRadius() << "\n";
        }
        
        // Try to cast to Rectangle
        Rectangle* rectPtr = dynamic_cast<Rectangle*>(shapes[i]);
        if (rectPtr) {
            std::cout << "  -> Is a Rectangle " << rectPtr->getWidth() << "x" << rectPtr->getHeight() << "\n";
        }
    }
    
    // dynamic_cast with references (throws on failure)
    try {
        Shape& shapeRef = *circle;
        Circle& circleRef = dynamic_cast<Circle&>(shapeRef);  // Success
        std::cout << "Reference cast succeeded: " << circleRef.getRadius() << "\n";
        
        Rectangle& rectRef = dynamic_cast<Rectangle&>(shapeRef);  // Throws
        std::cout << "This line won't execute\n";
        
    } catch (const std::bad_cast& e) {
        std::cout << "dynamic_cast failed: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateConstCast() {
    std::cout << "3. const_cast Examples:\n";
    
    // TODO: Show const_cast usage (and warnings about misuse)
    
    const int constValue = 100;
    const int* constPtr = &constValue;
    
    // Remove const (DANGEROUS if original was truly const)
    int* modifiablePtr = const_cast<int*>(constPtr);
    std::cout << "Original const value: " << *constPtr << "\n";
    
    // Safe example: removing const from originally non-const data
    int originallyNonConst = 42;
    const int* constPtrToNonConst = &originallyNonConst;
    int* backToNonConst = const_cast<int*>(constPtrToNonConst);
    *backToNonConst = 84;  // This is safe
    std::cout << "Modified originally non-const: " << originallyNonConst << "\n";
    
    std::cout << "WARNING: const_cast should be used very carefully!\n";
    
    std::cout << "---\n\n";
}

void demonstrateReinterpretCast() {
    std::cout << "4. reinterpret_cast Examples:\n";
    
    // TODO: Show reinterpret_cast (low-level, dangerous casting)
    
    // WARNING: reinterpret_cast is very dangerous and platform-dependent
    
    // Casting between pointer types
    int intValue = 0x12345678;
    int* intPtr = &intValue;
    
    // Reinterpret as char array to examine bytes
    char* charPtr = reinterpret_cast<char*>(intPtr);
    std::cout << "Integer " << std::hex << intValue << " as bytes: ";
    for (size_t i = 0; i < sizeof(int); ++i) {
        std::cout << std::hex << static_cast<unsigned char>(charPtr[i]) << " ";
    }
    std::cout << std::dec << "\n";
    
    // Casting pointer to integer (for debugging/logging)
    std::uintptr_t ptrAsInt = reinterpret_cast<std::uintptr_t>(intPtr);
    std::cout << "Pointer address as integer: " << std::hex << ptrAsInt << std::dec << "\n";
    
    std::cout << "WARNING: reinterpret_cast should be used very carefully!\n";
    
    std::cout << "---\n\n";
}

void demonstrateCStyleCast() {
    std::cout << "5. C-Style Cast (Not Recommended):\n";
    
    // TODO: Show C-style casting and why it's problematic
    
    double value = 42.7;
    
    // C-style cast (chooses among static_cast, const_cast, reinterpret_cast)
    int intValue = (int)value;  // Equivalent to static_cast<int>(value)
    std::cout << "C-style cast: " << value << " -> " << intValue << "\n";
    
    // Problems with C-style casts:
    std::cout << "Problems with C-style casts:\n";
    std::cout << "1. Too powerful - can perform unsafe conversions silently\n";
    std::cout << "2. Hard to search for in code\n";
    std::cout << "3. Unclear intent - what type of cast was intended?\n";
    std::cout << "4. No compile-time checking of safety\n";
    
    std::cout << "---\n\n";
}

void demonstrateCastSafety() {
    std::cout << "6. Cast Safety Comparison:\n";
    
    // TODO: Compare safety of different casting methods
    
    std::cout << "Cast safety ranking (safest to most dangerous):\n";
    std::cout << "1. static_cast: Compile-time checked, predictable conversions\n";
    std::cout << "2. dynamic_cast: Runtime type checking, fails safely\n";
    std::cout << "3. const_cast: Removes const/volatile, can be misused\n";
    std::cout << "4. reinterpret_cast: No type checking, very dangerous\n";
    std::cout << "5. C-style cast: Combines all above, unpredictable\n";
    
    std::cout << "---\n\n";
}

void demonstratePolymorphicCasting() {
    std::cout << "7. Polymorphic Casting Patterns:\n";
    
    // TODO: Show common polymorphic casting patterns
    
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>("C1", 3.0));
    shapes.push_back(std::make_unique<Rectangle>("R1", 4.0, 5.0));
    
    // Pattern: Type-specific processing
    std::cout << "Processing shapes by type:\n";
    for (const auto& shape : shapes) {
        if (auto* circle = dynamic_cast<Circle*>(shape.get())) {
            circle->setRadius(circle->getRadius() * 1.1);
            std::cout << "Scaled circle radius\n";
        } else if (auto* rect = dynamic_cast<Rectangle*>(shape.get())) {
            rect->resize(rect->getWidth() * 1.1, rect->getHeight() * 1.1);
            std::cout << "Scaled rectangle dimensions\n";
        }
    }
    
    std::cout << "---\n\n";
}

void demonstrateNumericCasting() {
    std::cout << "8. Numeric Casting:\n";
    
    // TODO: Show numeric conversions and potential issues
    
    // Safe numeric conversions
    int small = 42;
    long long big = static_cast<long long>(small);  // Widening conversion
    std::cout << "Safe widening: " << small << " -> " << big << "\n";
    
    // Potentially unsafe narrowing conversions
    long long bigValue = 1000000000000LL;
    int narrowed = static_cast<int>(bigValue);  // May truncate
    std::cout << "Narrowing conversion: " << bigValue << " -> " << narrowed << "\n";
    
    // Signed/unsigned conversions
    int negative = -100;
    unsigned int positive = static_cast<unsigned int>(negative);
    std::cout << "Signed to unsigned: " << negative << " -> " << positive << "\n";
    
    std::cout << "---\n\n";
}

void demonstrateCastingBestPractices() {
    std::cout << "9. Casting Best Practices:\n";
    
    // TODO: List best practices for casting
    
    std::cout << "Best practices:\n";
    std::cout << "1. Prefer C++ casts over C-style casts\n";
    std::cout << "2. Use static_cast for safe, predictable conversions\n";
    std::cout << "3. Use dynamic_cast for safe polymorphic downcasting\n";
    std::cout << "4. Avoid const_cast unless absolutely necessary\n";
    std::cout << "5. Avoid reinterpret_cast except for low-level code\n";
    std::cout << "6. Consider alternatives to casting:\n";
    std::cout << "   - Virtual functions instead of downcasting\n";
    std::cout << "   - Templates for type-safe generic code\n";
    std::cout << "   - Proper inheritance design\n";
    std::cout << "7. Always check dynamic_cast results\n";
    std::cout << "8. Document why casts are necessary\n";
    
    std::cout << "---\n\n";
}

// TODO: Implement any additional helper functions

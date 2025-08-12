/*
 * Namespaces - Interview Topics
 * 
 * Key Topics to Cover:
 * - Namespace declaration and usage
 * - using declarations and directives
 * - Nested namespaces
 * - Anonymous namespaces
 * - Namespace aliases
 * - ADL (Argument Dependent Lookup)
 */

#include <iostream>
#include <string>

// TODO: Implement these namespaces and functions

// 1. Basic namespace declarations
namespace Graphics {
    class Point {
    private:
        double x, y;
    public:
        Point(double x = 0, double y = 0);
        void display() const;
        double getX() const { return x; }
        double getY() const { return y; }
    };
    
    class Rectangle {
    private:
        Point topLeft, bottomRight;
    public:
        Rectangle(const Point& tl, const Point& br);
        void draw() const;
        double area() const;
    };
    
    void drawLine(const Point& start, const Point& end);
}

namespace Math {
    const double PI = 3.14159265359;
    
    double square(double x);
    double cube(double x);
    double factorial(int n);
    
    namespace Advanced {
        double sin(double x);
        double cos(double x);
        double sqrt(double x);
    }
}

// 2. Anonymous namespace (internal linkage)
namespace {
    int internalCounter = 0;
    
    void internalFunction() {
        std::cout << "This function has internal linkage\n";
    }
    
    class InternalClass {
    public:
        void doSomething() const {
            std::cout << "Internal class method\n";
        }
    };
}

// 3. ADL (Argument Dependent Lookup) demonstration
namespace ADLDemo {
    class MyClass {
    private:
        int value;
    public:
        MyClass(int v) : value(v) {}
        int getValue() const { return value; }
    };
    
    // Functions in same namespace as MyClass
    void print(const MyClass& obj) {
        std::cout << "ADL: MyClass value = " << obj.getValue() << "\n";
    }
    
    MyClass operator+(const MyClass& a, const MyClass& b) {
        return MyClass(a.getValue() + b.getValue());
    }
}

// 4. Namespace with function overloading
namespace Utility {
    void process(int value);
    void process(double value);
    void process(const std::string& value);
    
    template<typename T>
    void process(const T& value);
}

// Function prototypes for demonstrations
void demonstrateBasicNamespaces();
void demonstrateUsingDeclarations();
void demonstrateUsingDirectives();
void demonstrateNestedNamespaces();
void demonstrateAnonymousNamespaces();
void demonstrateNamespaceAliases();
void demonstrateADL();
void demonstrateNamespaceResolution();

int main() {
    std::cout << "=== Namespaces Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicNamespaces();
    demonstrateUsingDeclarations();
    demonstrateUsingDirectives();
    demonstrateNestedNamespaces();
    demonstrateAnonymousNamespaces();
    demonstrateNamespaceAliases();
    demonstrateADL();
    demonstrateNamespaceResolution();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicNamespaces() {
    std::cout << "1. Basic Namespace Usage:\n";
    
    // Use fully qualified names
    Graphics::Point p1(1.0, 2.0);
    Graphics::Point p2(3.0, 4.0);
    
    // TODO: Show namespace usage
    // Fully qualified names
    // Scope resolution operator ::
    
    std::cout << "---\n\n";
}

void demonstrateUsingDeclarations() {
    std::cout << "2. Using Declarations:\n";
    
    using Graphics::Point;  // Bring specific name into scope
    using Math::PI;         // Bring constant into scope
    
    Point p(5.0, 6.0);      // Can use Point directly
    double circumference = 2 * PI * 5.0;  // Can use PI directly
    
    // TODO: Show using declarations
    // Selective importing of names
    // Scope of using declaration
    
    std::cout << "---\n\n";
}

void demonstrateUsingDirectives() {
    std::cout << "3. Using Directives:\n";
    
    {
        using namespace Math;  // Bring entire namespace into scope
        
        double result1 = square(5.0);     // Can use square directly
        double result2 = cube(3.0);       // Can use cube directly
        double pi = PI;                   // Can use PI directly
        
        // TODO: Show using directive
        // All names from namespace become available
        // Potential naming conflicts
    }
    
    std::cout << "---\n\n";
}

void demonstrateNestedNamespaces() {
    std::cout << "4. Nested Namespaces:\n";
    
    // Access nested namespace
    double result = Math::Advanced::sqrt(16.0);
    
    // Using declaration for nested namespace
    using Math::Advanced::sin;
    double sineValue = sin(Math::PI / 2);
    
    // TODO: Show nested namespace usage
    // Multiple levels of nesting
    // Accessing deeply nested names
    
    std::cout << "---\n\n";
}

void demonstrateAnonymousNamespaces() {
    std::cout << "5. Anonymous Namespaces:\n";
    
    // Use anonymous namespace functions/classes
    internalFunction();
    
    InternalClass obj;
    obj.doSomething();
    
    internalCounter++;
    std::cout << "Internal counter: " << internalCounter << "\n";
    
    // TODO: Show anonymous namespace benefits
    // Internal linkage alternative to static
    // File-scope privacy
    
    std::cout << "---\n\n";
}

void demonstrateNamespaceAliases() {
    std::cout << "6. Namespace Aliases:\n";
    
    // Create aliases for long namespace names
    namespace Gfx = Graphics;
    namespace MathAdv = Math::Advanced;
    
    Gfx::Point p(10.0, 20.0);
    double sqrtResult = MathAdv::sqrt(25.0);
    
    // TODO: Show namespace aliases
    // Shortening long names
    // Making code more readable
    
    std::cout << "---\n\n";
}

void demonstrateADL() {
    std::cout << "7. Argument Dependent Lookup (ADL):\n";
    
    ADLDemo::MyClass obj1(10);
    ADLDemo::MyClass obj2(20);
    
    // ADL allows calling without namespace qualification
    print(obj1);  // Finds ADLDemo::print through ADL
    
    ADLDemo::MyClass result = obj1 + obj2;  // Finds operator+ through ADL
    print(result);
    
    // TODO: Show ADL mechanism
    // How compiler finds functions
    // Koenig lookup
    
    std::cout << "---\n\n";
}

void demonstrateNamespaceResolution() {
    std::cout << "8. Namespace Resolution:\n";
    
    // Show resolution conflicts and solutions
    using namespace Math;
    using namespace Utility;
    
    // If there are conflicts, use qualified names
    Math::square(5.0);
    Utility::process(42);
    
    // TODO: Show conflict resolution
    // Ambiguity resolution
    // Explicit qualification
    
    std::cout << "---\n\n";
}

// TODO: Implement all the namespace functions and classes

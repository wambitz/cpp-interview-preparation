/*
 * Function Overloading - Interview Topics
 * 
 * Key Topics to Cover:
 * - Function overloading rules
 * - Overloading by parameter type, count, order
 * - const overloading
 * - Reference vs value overloading
 * - Template function overloading
 * - Overload resolution process
 * - Ambiguity resolution
 */

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

// TODO: Implement these overloaded function examples

// 1. Basic function overloading by parameter count
void print();
void print(int value);
void print(int value1, int value2);
void print(int value1, int value2, int value3);

// 2. Overloading by parameter type
void display(int value);
void display(double value);
void display(const std::string& value);
void display(char value);
void display(bool value);

// 3. Overloading by parameter order
void process(int x, double y);
void process(double x, int y);
void process(const std::string& str, int num);
void process(int num, const std::string& str);

// 4. Const overloading (common in classes)
class ConstOverload {
private:
    std::vector<int> data;
    
public:
    ConstOverload(const std::vector<int>& values);
    
    // Non-const version - allows modification
    int& at(size_t index);
    
    // Const version - read-only access
    const int& at(size_t index) const;
    
    // Non-const version
    int& operator[](size_t index);
    
    // Const version
    const int& operator[](size_t index) const;
    
    // Non-const version returns iterator
    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();
    
    // Const versions
    std::vector<int>::const_iterator begin() const;
    std::vector<int>::const_iterator end() const;
    
    void print() const;
};

// 5. Reference vs value overloading
void setValue(int value);        // Pass by value
void setValue(int& value);       // Pass by reference
void setValue(const int& value); // Pass by const reference
void setValue(int&& value);      // Pass by rvalue reference

// 6. Pointer overloading
void handleData(int* data);
void handleData(const int* data);
void handleData(int* const data);
void handleData(const int* const data);

// 7. Template function overloading
template<typename T>
void templateFunc(T value);

template<typename T>
void templateFunc(T* ptr);

template<typename T>
void templateFunc(const T& ref);

// Specialization for specific types
template<>
void templateFunc<std::string>(std::string value);

// 8. Class with comprehensive overloading
class Calculator {
public:
    // Overloading by parameter count
    int add(int a);
    int add(int a, int b);
    int add(int a, int b, int c);
    
    // Overloading by parameter type
    double add(double a, double b);
    float add(float a, float b);
    
    // Overloading with different return types (not allowed - show why)
    // int multiply(int a, int b);
    // double multiply(int a, int b);  // ERROR: Cannot overload based on return type
    
    // Proper way: different parameter types
    int multiply(int a, int b);
    double multiply(double a, double b);
    
    // Overloading with default parameters (can cause ambiguity)
    void compute(int x, int y = 0);
    void compute(int x);  // This would be ambiguous with above
    
    // Better approach
    void computeWithDefault(int x, int y = 0);
    void computeSingle(int x);
};

// 9. Namespace overloading
namespace MathOps {
    int max(int a, int b);
    double max(double a, double b);
    std::string max(const std::string& a, const std::string& b);
}

namespace StringOps {
    std::string concat(const std::string& a, const std::string& b);
    std::string concat(const std::string& a, const std::string& b, const std::string& c);
    std::string concat(const std::vector<std::string>& strings);
}

// 10. Function objects and operator overloading
class Adder {
private:
    int base;
    
public:
    Adder(int b);
    
    // Function call operator overloading
    int operator()(int value);
    int operator()(int a, int b);
    double operator()(double a, double b);
};

// Function prototypes for demonstrations
void demonstrateBasicOverloading();
void demonstrateTypeOverloading();
void demonstrateOrderOverloading();
void demonstrateConstOverloading();
void demonstrateReferenceOverloading();
void demonstrateTemplateOverloading();
void demonstrateOverloadResolution();
void demonstrateAmbiguity();
void demonstrateOverloadingBestPractices();

int main() {
    std::cout << "=== Function Overloading Examples ===

";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicOverloading();
    demonstrateTypeOverloading();
    demonstrateOrderOverloading();
    demonstrateConstOverloading();
    demonstrateReferenceOverloading();
    demonstrateTemplateOverloading();
    demonstrateOverloadResolution();
    demonstrateAmbiguity();
    demonstrateOverloadingBestPractices();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicOverloading() {
    std::cout << "1. Basic Function Overloading by Parameter Count:
";
    
    // TODO: Show overloading by number of parameters
    print();                    // Calls print()
    print(42);                  // Calls print(int)
    print(10, 20);             // Calls print(int, int)
    print(1, 2, 3);            // Calls print(int, int, int)
    
    std::cout << "---

";
}

void demonstrateTypeOverloading() {
    std::cout << "2. Function Overloading by Parameter Type:
";
    
    // TODO: Show overloading by parameter types
    display(42);                    // Calls display(int)
    display(3.14);                  // Calls display(double)
    display("Hello");               // Calls display(const std::string&)
    display('A');                   // Calls display(char)
    display(true);                  // Calls display(bool)
    
    std::cout << "---

";
}

void demonstrateOrderOverloading() {
    std::cout << "3. Function Overloading by Parameter Order:
";
    
    // TODO: Show overloading by parameter order
    process(10, 3.14);              // Calls process(int, double)
    process(2.71, 20);              // Calls process(double, int)
    process("text", 100);           // Calls process(const std::string&, int)
    process(200, "data");           // Calls process(int, const std::string&)
    
    std::cout << "---

";
}

void demonstrateConstOverloading() {
    std::cout << "4. Const Function Overloading:
";
    
    // TODO: Show const vs non-const overloading
    ConstOverload obj({10, 20, 30, 40, 50});
    const ConstOverload constObj({1, 2, 3, 4, 5});
    
    // Non-const object can call both versions
    int& ref = obj[0];              // Calls non-const operator[]
    ref = 999;                      // Can modify
    
    // Const object can only call const versions
    const int& constRef = constObj[0];  // Calls const operator[]
    // constRef = 100;              // ERROR: Cannot modify
    
    std::cout << "Non-const object: ";
    obj.print();
    std::cout << "Const object: ";
    constObj.print();
    
    std::cout << "---

";
}

void demonstrateReferenceOverloading() {
    std::cout << "5. Reference vs Value Overloading:
";
    
    // TODO: Show different reference type overloading
    int value = 42;
    const int constValue = 100;
    
    setValue(value);                // Which version gets called?
    setValue(constValue);           // Which version gets called?
    setValue(200);                  // Which version gets called?
    setValue(std::move(value));     // Which version gets called?
    
    std::cout << "Overload resolution depends on argument type
";
    
    std::cout << "---

";
}

void demonstrateTemplateOverloading() {
    std::cout << "6. Template Function Overloading:
";
    
    // TODO: Show template overloading
    int intVal = 42;
    int* intPtr = &intVal;
    std::string str = "Hello";
    
    templateFunc(intVal);           // templateFunc<int>(T)
    templateFunc(intPtr);           // templateFunc<int>(T*)
    templateFunc(str);              // Specialized version for string
    
    std::cout << "---

";
}

void demonstrateOverloadResolution() {
    std::cout << "7. Overload Resolution Process:
";
    
    // TODO: Explain overload resolution steps
    std::cout << "Overload resolution follows these steps:
";
    std::cout << "1. Name lookup
";
    std::cout << "2. Template argument deduction (if applicable)
";
    std::cout << "3. Viable function selection
";
    std::cout << "4. Best match selection
";
    std::cout << "5. Access checking
";
    
    Calculator calc;
    
    // Exact match preferred
    calc.add(5, 10);                // Exact match: add(int, int)
    calc.add(5.0, 10.0);           // Exact match: add(double, double)
    
    // Implicit conversion if needed
    calc.add(5, 10.0);             // Calls add(double, double) with conversion
    
    std::cout << "---

";
}

void demonstrateAmbiguity() {
    std::cout << "8. Overloading Ambiguity:
";
    
    // TODO: Show ambiguous cases and how to resolve them
    std::cout << "Ambiguous cases:
";
    std::cout << "- Multiple conversions possible
";
    std::cout << "- Template vs non-template functions
";
    std::cout << "- Default parameters creating ambiguity
";
    
    // Example of potential ambiguity
    // void func(int x, double y = 0.0);
    // void func(int x);
    // func(5);  // Ambiguous - could match either
    
    std::cout << "Resolution strategies:
";
    std::cout << "- Use explicit casts
";
    std::cout << "- Rename functions
";
    std::cout << "- Use different parameter counts
";
    
    std::cout << "---

";
}

void demonstrateOverloadingBestPractices() {
    std::cout << "9. Function Overloading Best Practices:
";
    
    // TODO: List best practices
    std::cout << "Best practices:
";
    std::cout << "1. Overload functions that perform the same operation
";
    std::cout << "2. Keep parameter names consistent across overloads
";
    std::cout << "3. Avoid overloading with similar parameter types
";
    std::cout << "4. Be careful with default parameters
";
    std::cout << "5. Consider const overloading for class members
";
    std::cout << "6. Use enable_if for template overloading
";
    std::cout << "7. Document complex overload sets
";
    
    // Example of good overloading
    MathOps::max(5, 10);
    MathOps::max(5.5, 10.3);
    MathOps::max(std::string("abc"), std::string("def"));
    
    StringOps::concat("Hello", "World");
    StringOps::concat("A", "B", "C");
    
    std::cout << "---

";
}

// TODO: Implement all overloaded functions and class methods

// Basic overloading implementations
void print() {
    std::cout << "print() called
";
}

void print(int value) {
    std::cout << "print(int): " << value << "
";
}

void print(int value1, int value2) {
    std::cout << "print(int, int): " << value1 << ", " << value2 << "
";
}

void print(int value1, int value2, int value3) {
    std::cout << "print(int, int, int): " << value1 << ", " << value2 << ", " << value3 << "
";
}

// Type overloading implementations
void display(int value) {
    std::cout << "display(int): " << value << "
";
}

void display(double value) {
    std::cout << "display(double): " << value << "
";
}

void display(const std::string& value) {
    std::cout << "display(string): " << value << "
";
}

void display(char value) {
    std::cout << "display(char): " << value << "
";
}

void display(bool value) {
    std::cout << "display(bool): " << (value ? "true" : "false") << "
";
}

// TODO: Implement remaining functions...

/*
 * Operator Overloading - Interview Topics
 * 
 * Key Topics to Cover:
 * - Arithmetic operators (+, -, *, /)
 * - Comparison operators (==, !=, <, >)
 * - Assignment operators (=, +=, -=)
 * - Stream operators (<<, >>)
 * - Subscript operator []
 * - Function call operator ()
 * - Member vs non-member operator functions
 */

#include <iostream>
#include <string>
#include <vector>

// TODO: Implement these classes

// 1. Complex number class demonstrating arithmetic operators
class Complex {
private:
    double real, imag;
    
public:
    Complex(double r = 0.0, double i = 0.0);
    
    // Arithmetic operators (member functions)
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    
    // Compound assignment operators
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);
    
    // Unary operators
    Complex operator-() const;                    // Negation
    Complex& operator++();                        // Pre-increment
    Complex operator++(int);                     // Post-increment
    
    // Comparison operators
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    
    // Member access
    double getReal() const { return real; }
    double getImag() const { return imag; }
    
    // Friend functions for stream operators
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

// 2. Vector-like class demonstrating subscript and function call operators
class MyVector {
private:
    std::vector<int> data;
    
public:
    MyVector(size_t size = 0, int defaultValue = 0);
    MyVector(std::initializer_list<int> list);
    
    // Subscript operators
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    // Function call operator (makes object callable)
    int operator()(size_t index) const;          // Read access
    void operator()(size_t index, int value);    // Write access
    
    // Assignment operator
    MyVector& operator=(const MyVector& other);
    
    // Comparison operators
    bool operator==(const MyVector& other) const;
    bool operator!=(const MyVector& other) const;
    
    // Utility functions
    size_t size() const { return data.size(); }
    void push_back(int value) { data.push_back(value); }
    
    // Stream output
    friend std::ostream& operator<<(std::ostream& os, const MyVector& vec);
};

// 3. String class demonstrating various operators
class MyString {
private:
    char* str;
    size_t len;
    
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);             // Copy constructor
    MyString(MyString&& other) noexcept;         // Move constructor
    ~MyString();
    
    // Assignment operators
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    MyString& operator=(const char* s);
    
    // Arithmetic operators
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    
    // Subscript operators
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    
    // Comparison operators
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    
    // Conversion operator
    operator const char*() const;
    
    // Utility functions
    size_t length() const { return len; }
    const char* c_str() const { return str; }
    
    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
    friend std::istream& operator>>(std::istream& is, MyString& s);
};

// 4. Smart pointer class demonstrating pointer-like operators
template<typename T>
class SmartPtr {
private:
    T* ptr;
    
public:
    explicit SmartPtr(T* p = nullptr);
    ~SmartPtr();
    
    // Copy operations (deleted to make it unique-like)
    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;
    
    // Move operations
    SmartPtr(SmartPtr&& other) noexcept;
    SmartPtr& operator=(SmartPtr&& other) noexcept;
    
    // Pointer-like operators
    T& operator*() const;
    T* operator->() const;
    
    // Boolean conversion
    explicit operator bool() const;
    
    // Release ownership
    T* release();
    void reset(T* p = nullptr);
    T* get() const { return ptr; }
};

// Function prototypes for demonstrations
void demonstrateArithmeticOperators();
void demonstrateComparisonOperators();
void demonstrateAssignmentOperators();
void demonstrateStreamOperators();
void demonstrateSubscriptOperator();
void demonstrateFunctionCallOperator();
void demonstrateUnaryOperators();
void demonstrateConversionOperators();

int main() {
    std::cout << "=== Operator Overloading Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateArithmeticOperators();
    demonstrateComparisonOperators();
    demonstrateAssignmentOperators();
    demonstrateStreamOperators();
    demonstrateSubscriptOperator();
    demonstrateFunctionCallOperator();
    demonstrateUnaryOperators();
    demonstrateConversionOperators();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateArithmeticOperators() {
    std::cout << "1. Arithmetic Operators (+, -, *, /):\n";
    
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    
    // TODO: Show arithmetic operations
    // c1 + c2, c1 - c2, c1 * c2, c1 / c2
    // Compound assignments: +=, -=, *=, /=
    
    std::cout << "---\n\n";
}

void demonstrateComparisonOperators() {
    std::cout << "2. Comparison Operators (==, !=, <, >):\n";
    
    MyString s1("Apple");
    MyString s2("Banana");
    MyString s3("Apple");
    
    // TODO: Show comparison operations
    // ==, !=, <, >, <=, >=
    
    std::cout << "---\n\n";
}

void demonstrateAssignmentOperators() {
    std::cout << "3. Assignment Operators (=, +=, -=):\n";
    
    MyString str1("Hello");
    MyString str2("World");
    
    // TODO: Show assignment operations
    // Copy assignment, move assignment
    // Compound assignments
    
    std::cout << "---\n\n";
}

void demonstrateStreamOperators() {
    std::cout << "4. Stream Operators (<< and >>):\n";
    
    Complex c(2.5, 3.7);
    MyVector vec{1, 2, 3, 4, 5};
    
    // TODO: Show stream operations
    // Output with <<
    // Input with >> (if implemented)
    
    std::cout << "---\n\n";
}

void demonstrateSubscriptOperator() {
    std::cout << "5. Subscript Operator []:\n";
    
    MyVector vec{10, 20, 30, 40, 50};
    const MyVector constVec{1, 2, 3};
    
    // TODO: Show subscript operations
    // Read and write access
    // Const vs non-const versions
    
    std::cout << "---\n\n";
}

void demonstrateFunctionCallOperator() {
    std::cout << "6. Function Call Operator ():\n";
    
    MyVector vec{100, 200, 300};
    
    // TODO: Show function call operator
    // Making objects callable like functions
    
    std::cout << "---\n\n";
}

void demonstrateUnaryOperators() {
    std::cout << "7. Unary Operators (++, --, -, +):\n";
    
    Complex c(1.0, 2.0);
    
    // TODO: Show unary operations
    // Pre/post increment, negation
    
    std::cout << "---\n\n";
}

void demonstrateConversionOperators() {
    std::cout << "8. Conversion Operators:\n";
    
    MyString str("Hello");
    SmartPtr<int> ptr(new int(42));
    
    // TODO: Show conversion operations
    // Implicit and explicit conversions
    // Boolean conversion
    
    std::cout << "---\n\n";
}

// TODO: Implement all class methods

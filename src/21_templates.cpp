/*
 * Templates - Interview Topics
 * 
 * Key Topics to Cover:
 * - Function templates
 * - Class templates
 * - Template specialization
 * - Template instantiation
 * - SFINAE (Substitution Failure Is Not An Error)
 * - Variadic templates
 * - Template metaprogramming basics
 */

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

// TODO: Implement these template functions

// 1. Basic Function Templates
template<typename T>
T maximum(T a, T b);

template<typename T>
void swapValues(T& a, T& b);

// Multiple template parameters
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b);

// 2. Function Template Specialization
template<typename T>
void print(const T& value);

// Specialization for const char*
template<>
void print<const char*>(const char* const& value);

// Specialization for std::string
template<>
void print<std::string>(const std::string& value);

// 3. Class Templates
template<typename T, size_t Size = 10>
class Stack {
private:
    T data[Size];
    size_t top;
    
public:
    Stack();
    
    bool push(const T& item);
    bool pop(T& item);
    bool peek(T& item) const;
    bool isEmpty() const;
    bool isFull() const;
    size_t size() const;
    size_t capacity() const;
};

// 4. Class Template Specialization
template<typename T>
class Container {
private:
    T* data;
    size_t size_;
    size_t capacity_;
    
public:
    Container(size_t initial_capacity = 10);
    ~Container();
    
    void add(const T& item);
    T& get(size_t index);
    size_t size() const;
    void print() const;
};

// Specialization for bool
template<>
class Container<bool> {
private:
    std::vector<bool> data;
    
public:
    Container(size_t initial_capacity = 10);
    
    void add(bool item);
    bool get(size_t index) const;
    size_t size() const;
    void print() const;
};

// 5. Variadic Templates
template<typename T>
void printAll(const T& value);

template<typename T, typename... Args>
void printAll(const T& first, const Args&... args);

// Variadic template class
template<typename... Types>
class Tuple;

template<>
class Tuple<> {
public:
    static constexpr size_t size() { return 0; }
};

template<typename Head, typename... Tail>
class Tuple<Head, Tail...> {
private:
    Head head;
    Tuple<Tail...> tail;
    
public:
    Tuple(const Head& h, const Tail&... t);
    
    const Head& getHead() const;
    const Tuple<Tail...>& getTail() const;
    
    static constexpr size_t size() { return 1 + Tuple<Tail...>::size(); }
};

// 6. SFINAE Example
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
processNumber(T value);

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
processNumber(T value);

// 7. Template Metaprogramming
template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static constexpr int value = 1;
};

// Type traits example
template<typename T>
struct IsPointer {
    static constexpr bool value = false;
};

template<typename T>
struct IsPointer<T*> {
    static constexpr bool value = true;
};

// Function prototypes for demonstrations
void demonstrateFunctionTemplates();
void demonstrateClassTemplates();
void demonstrateTemplateSpecialization();
void demonstrateVariadicTemplates();
void demonstrateSFINAE();
void demonstrateTemplateMetaprogramming();
void demonstrateTemplateInstantiation();

int main() {
    std::cout << "=== Templates Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateFunctionTemplates();
    demonstrateClassTemplates();
    demonstrateTemplateSpecialization();
    demonstrateVariadicTemplates();
    demonstrateSFINAE();
    demonstrateTemplateMetaprogramming();
    demonstrateTemplateInstantiation();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateFunctionTemplates() {
    std::cout << "1. Function Templates:\n";
    // Use maximum and swapValues with different types
    // Show template argument deduction
    
    std::cout << "---\n\n";
}

void demonstrateClassTemplates() {
    std::cout << "2. Class Templates:\n";
    // Create Stack instances with different types
    // Show template parameter usage
    
    std::cout << "---\n\n";
}

void demonstrateTemplateSpecialization() {
    std::cout << "3. Template Specialization:\n";
    // Show function and class template specialization
    // Compare generic vs specialized behavior
    
    std::cout << "---\n\n";
}

void demonstrateVariadicTemplates() {
    std::cout << "4. Variadic Templates:\n";
    // Use printAll with different numbers of arguments
    // Create Tuple instances
    
    std::cout << "---\n\n";
}

void demonstrateSFINAE() {
    std::cout << "5. SFINAE:\n";
    // Call processNumber with different types
    // Show how SFINAE enables/disables templates
    
    std::cout << "---\n\n";
}

void demonstrateTemplateMetaprogramming() {
    std::cout << "6. Template Metaprogramming:\n";
    // Use Factorial and IsPointer at compile time
    // Show compile-time computation
    
    std::cout << "---\n\n";
}

void demonstrateTemplateInstantiation() {
    std::cout << "7. Template Instantiation:\n";
    // Show explicit vs implicit instantiation
    // Template instantiation process
    
    std::cout << "---\n\n";
}

// TODO: Implement all template functions and methods

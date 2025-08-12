/*
 * Exception Handling - Interview Topics
 * 
 * Key Topics to Cover:
 * - try, catch, throw statements
 * - Exception types and inheritance
 * - Stack unwinding
 * - RAII and exceptions
 * - noexcept specifier
 * - Custom exception classes
 * - Exception safety guarantees
 */

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <memory>
#include <vector>

// TODO: Implement these custom exception classes

// 1. Custom exception hierarchy
class CustomException : public std::exception {
protected:
    std::string message;
    
public:
    CustomException(const std::string& msg);
    const char* what() const noexcept override;
};

class MathException : public CustomException {
public:
    MathException(const std::string& msg);
};

class DivideByZeroException : public MathException {
public:
    DivideByZeroException();
};

class InvalidInputException : public CustomException {
private:
    int invalidValue;
    
public:
    InvalidInputException(const std::string& msg, int value);
    int getInvalidValue() const noexcept;
};

// 2. Class demonstrating RAII with exceptions
class RAIIResource {
private:
    std::string name;
    int* data;
    bool acquired;
    
public:
    RAIIResource(const std::string& resourceName);
    ~RAIIResource();
    
    void acquire();
    void release();
    void doWork();
    
    // Copy operations deleted to prevent issues
    RAIIResource(const RAIIResource&) = delete;
    RAIIResource& operator=(const RAIIResource&) = delete;
};

// 3. Exception safety demonstration class
class ExceptionSafeContainer {
private:
    std::vector<std::unique_ptr<int>> data;
    
public:
    // Basic guarantee: no resource leaks
    void addItemBasic(int value);
    
    // Strong guarantee: commit or rollback
    void addItemStrong(int value);
    
    // No-throw guarantee
    size_t size() const noexcept;
    void clear() noexcept;
    
    void display() const;
};

// 4. Functions with different exception specifications
class NoexceptDemo {
public:
    // Functions that don't throw
    int add(int a, int b) noexcept;
    int multiply(int a, int b) noexcept(true);
    
    // Functions that might throw
    double divide(double a, double b);
    double safeDivide(double a, double b) noexcept(false);
    
    // Conditionally noexcept
    template<typename T>
    void swap(T& a, T& b) noexcept(std::is_nothrow_move_constructible_v<T>);
};

// Function prototypes for demonstrations
void demonstrateBasicExceptions();
void demonstrateExceptionTypes();
void demonstrateCustomExceptions();
void demonstrateStackUnwinding();
void demonstrateRAIIWithExceptions();
void demonstrateExceptionSafety();
void demonstrateNoexceptSpecifier();
void demonstrateExceptionBestPractices();

int main() {
    std::cout << "=== Exception Handling Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    try {
        demonstrateBasicExceptions();
        demonstrateExceptionTypes();
        demonstrateCustomExceptions();
        demonstrateStackUnwinding();
        demonstrateRAIIWithExceptions();
        demonstrateExceptionSafety();
        demonstrateNoexceptSpecifier();
        demonstrateExceptionBestPractices();
    } catch (const std::exception& e) {
        std::cout << "Caught exception in main: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Caught unknown exception in main\n";
    }
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicExceptions() {
    std::cout << "1. Basic Exception Handling:\n";
    
    try {
        // TODO: Show basic try-catch blocks
        // throw different types of exceptions
        // catch by value, reference, const reference
        
        throw std::runtime_error("Basic exception example");
        
    } catch (const std::runtime_error& e) {
        std::cout << "Caught runtime_error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Caught std::exception: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Caught unknown exception\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateExceptionTypes() {
    std::cout << "2. Standard Exception Types:\n";
    
    // TODO: Show different standard exceptions
    // std::runtime_error, std::logic_error
    // std::invalid_argument, std::out_of_range
    // std::bad_alloc, std::bad_cast
    
    try {
        std::vector<int> vec(5);
        vec.at(10) = 42;  // Should throw std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateCustomExceptions() {
    std::cout << "3. Custom Exception Classes:\n";
    
    try {
        // TODO: Use custom exception classes
        // Show exception inheritance hierarchy
        // Demonstrate additional data in exceptions
        
        throw DivideByZeroException();
        
    } catch (const DivideByZeroException& e) {
        std::cout << "Caught DivideByZeroException: " << e.what() << "\n";
    } catch (const MathException& e) {
        std::cout << "Caught MathException: " << e.what() << "\n";
    } catch (const CustomException& e) {
        std::cout << "Caught CustomException: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateStackUnwinding() {
    std::cout << "4. Stack Unwinding:\n";
    
    // TODO: Show how stack unwinding works
    // Destructors called during exception propagation
    // Demonstrate with RAII objects
    
    try {
        RAIIResource resource1("Resource1");
        RAIIResource resource2("Resource2");
        
        // Throw exception to trigger unwinding
        throw std::runtime_error("Triggering stack unwinding");
        
    } catch (const std::exception& e) {
        std::cout << "Exception caught, resources should be cleaned up\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateRAIIWithExceptions() {
    std::cout << "5. RAII and Exception Safety:\n";
    
    // TODO: Show how RAII ensures cleanup even with exceptions
    // Compare with manual resource management
    
    try {
        RAIIResource resource("RAII Resource");
        resource.acquire();
        resource.doWork();
        // Exception here should still clean up properly
        throw std::runtime_error("Exception during work");
        
    } catch (const std::exception& e) {
        std::cout << "RAII ensures cleanup: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateExceptionSafety() {
    std::cout << "6. Exception Safety Guarantees:\n";
    
    ExceptionSafeContainer container;
    
    try {
        // TODO: Show different safety levels
        // Basic guarantee: no resource leaks
        // Strong guarantee: commit or rollback
        // No-throw guarantee: never throws
        
        container.addItemBasic(10);
        container.addItemStrong(20);
        
    } catch (const std::exception& e) {
        std::cout << "Exception in container operation: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateNoexceptSpecifier() {
    std::cout << "7. Noexcept Specifier:\n";
    
    NoexceptDemo demo;
    
    // TODO: Show noexcept usage
    // Functions that guarantee not to throw
    // Conditional noexcept
    // Performance implications
    
    std::cout << "add(5, 3) = " << demo.add(5, 3) << "\n";
    
    try {
        demo.divide(10, 0);  // May throw
    } catch (const std::exception& e) {
        std::cout << "Division exception: " << e.what() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateExceptionBestPractices() {
    std::cout << "8. Exception Best Practices:\n";
    
    // TODO: Show best practices
    // Catch by const reference
    // Use standard exceptions when appropriate
    // Don't throw in destructors
    // Use RAII for resource management
    // Prefer noexcept when possible
    
    std::cout << "Best practices demonstrated throughout examples\n";
    std::cout << "---\n\n";
}

// TODO: Implement all class methods
CustomException::CustomException(const std::string& msg) : message(msg) {}

const char* CustomException::what() const noexcept {
    return message.c_str();
}

MathException::MathException(const std::string& msg) : CustomException("Math Error: " + msg) {}

DivideByZeroException::DivideByZeroException() : MathException("Division by zero") {}

InvalidInputException::InvalidInputException(const std::string& msg, int value) 
    : CustomException(msg), invalidValue(value) {}

int InvalidInputException::getInvalidValue() const noexcept {
    return invalidValue;
}

RAIIResource::RAIIResource(const std::string& resourceName) 
    : name(resourceName), data(nullptr), acquired(false) {
    std::cout << "RAIIResource " << name << " created\n";
}

RAIIResource::~RAIIResource() {
    if (acquired) {
        release();
    }
    std::cout << "RAIIResource " << name << " destroyed\n";
}

void RAIIResource::acquire() {
    if (!acquired) {
        data = new int[100];  // Simulate resource acquisition
        acquired = true;
        std::cout << "Resource " << name << " acquired\n";
    }
}

void RAIIResource::release() {
    if (acquired) {
        delete[] data;
        data = nullptr;
        acquired = false;
        std::cout << "Resource " << name << " released\n";
    }
}

void RAIIResource::doWork() {
    if (!acquired) {
        acquire();
    }
    std::cout << "Resource " << name << " doing work\n";
    // Simulate work that might throw
}

// TODO: Implement remaining class methods...

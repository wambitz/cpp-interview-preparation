/*
 * Static Keyword - Interview Topics
 * 
 * Key Topics to Cover:
 * - Static variables in functions
 * - Static class members (data and functions)
 * - Static local variables vs global variables
 * - Static initialization order
 * - Static storage duration
 * - Static in different contexts
 */

#include <iostream>
#include <string>
#include <vector>

// TODO: Implement these examples demonstrating static keyword usage

// 1. Static variables in functions
int regularCounter();
int staticCounter();
void demonstrateStaticFunctionVars();

// 2. Class with static members
class StaticMemberClass {
private:
    static int instanceCount;           // Static data member
    static const int maxInstances;     // Static const data member
    static std::string className;      // Static string member
    
    int instanceId;
    std::string name;
    
public:
    StaticMemberClass(const std::string& n);
    ~StaticMemberClass();
    
    // Static member functions
    static int getInstanceCount();
    static void setClassName(const std::string& name);
    static const std::string& getClassName();
    static void printClassInfo();
    
    // Static function with template
    template<typename T>
    static void staticTemplate(T value);
    
    // Non-static members
    void printInstanceInfo() const;
    int getId() const;
    const std::string& getName() const;
    
    // Static vs non-static method comparison
    void nonStaticMethod();
    static void staticMethod();
};

// Static member definitions (required for non-const static members)
// TODO: Define these in implementation

// 3. Singleton pattern using static
class Singleton {
private:
    static Singleton* instance;
    static bool destroyed;
    
    int value;
    std::string data;
    
    // Private constructor
    Singleton(int val = 0, const std::string& str = "");
    
    // Private destructor
    ~Singleton();
    
    // Disable copy operations
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
public:
    static Singleton& getInstance();
    static void destroyInstance();
    
    void setValue(int val);
    int getValue() const;
    void setData(const std::string& str);
    const std::string& getData() const;
    
    void printInfo() const;
};

// 4. Static initialization demonstration
class StaticInitOrder {
private:
    static int staticVar1;
    static int staticVar2;
    static std::vector<int> staticVector;
    
public:
    StaticInitOrder();
    
    static void initializeStatics();
    static void printStatics();
    static int getStaticVar1();
    static int getStaticVar2();
};

// 5. Static in namespaces
namespace StaticNamespace {
    static int internalVar = 100;      // Internal linkage
    extern int externalVar;            // External linkage
    
    static void internalFunction();    // Internal linkage
    void externalFunction();           // External linkage
    
    class NamespaceClass {
    private:
        static int staticInClass;
        
    public:
        static void classStaticMethod();
        static int getStaticValue();
    };
}

// 6. Static storage duration examples
class StorageDurationDemo {
private:
    static const int staticConstInt;           // Static const
    static constexpr int staticConstexprInt;   // Static constexpr
    static inline int staticInlineInt;         // Static inline (C++17)
    
public:
    void demonstrateStorageDuration();
    static void staticDemonstration();
};

// 7. Static with templates
template<typename T>
class StaticTemplate {
private:
    static int templateStaticVar;
    static T templateStaticValue;
    
public:
    static void setStaticVar(int val);
    static int getStaticVar();
    static void setStaticValue(const T& val);
    static T getStaticValue();
    
    static void printTemplateStatics();
};

// Template static member definitions
template<typename T>
int StaticTemplate<T>::templateStaticVar = 0;

template<typename T>
T StaticTemplate<T>::templateStaticValue = T{};

// 8. Local static with threading implications
class ThreadSafeStatic {
public:
    static int& getStaticCounter();
    static std::string& getStaticString();
    
    // C++11 thread-safe static initialization
    static ThreadSafeStatic& getInstance();
    
private:
    ThreadSafeStatic() = default;
    int data = 42;
    
public:
    void processData();
    int getData() const;
};

// Function prototypes for demonstrations
void demonstrateStaticFunctionVariables();
void demonstrateStaticClassMembers();
void demonstrateSingletonPattern();
void demonstrateStaticInitialization();
void demonstrateStaticLinkage();
void demonstrateStaticStorageDuration();
void demonstrateStaticTemplates();
void demonstrateThreadSafeStatics();
void demonstrateStaticBestPractices();

int main() {
    std::cout << "=== Static Keyword Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateStaticFunctionVariables();
    demonstrateStaticClassMembers();
    demonstrateSingletonPattern();
    demonstrateStaticInitialization();
    demonstrateStaticLinkage();
    demonstrateStaticStorageDuration();
    demonstrateStaticTemplates();
    demonstrateThreadSafeStatics();
    demonstrateStaticBestPractices();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateStaticFunctionVariables() {
    std::cout << "1. Static Variables in Functions:\n";
    
    // TODO: Show difference between static and non-static local variables
    std::cout << "Regular counter calls:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Call " << i + 1 << ": " << regularCounter() << "\n";
    }
    
    std::cout << "\nStatic counter calls:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Call " << i + 1 << ": " << staticCounter() << "\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateStaticClassMembers() {
    std::cout << "2. Static Class Members:\n";
    
    // TODO: Show static data and function members
    std::cout << "Initial instance count: " << StaticMemberClass::getInstanceCount() << "\n";
    
    StaticMemberClass::setClassName("MyClass");
    StaticMemberClass::printClassInfo();
    
    {
        StaticMemberClass obj1("Object1");
        StaticMemberClass obj2("Object2");
        StaticMemberClass obj3("Object3");
        
        std::cout << "After creating 3 objects: " << StaticMemberClass::getInstanceCount() << "\n";
        
        obj1.printInstanceInfo();
        obj2.printInstanceInfo();
        
        // Static template function
        StaticMemberClass::staticTemplate(42);
        StaticMemberClass::staticTemplate(std::string("Hello"));
        
    } // Objects destroyed here
    
    std::cout << "After objects destroyed: " << StaticMemberClass::getInstanceCount() << "\n";
    
    std::cout << "---\n\n";
}

void demonstrateSingletonPattern() {
    std::cout << "3. Singleton Pattern with Static:\n";
    
    // TODO: Show singleton usage
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    
    std::cout << "Are s1 and s2 the same instance? " << (&s1 == &s2 ? "Yes" : "No") << "\n";
    
    s1.setValue(100);
    s1.setData("Singleton Data");
    
    std::cout << "s1 data: ";
    s1.printInfo();
    std::cout << "s2 data: ";
    s2.printInfo();
    
    // Both refer to the same object
    s2.setValue(200);
    std::cout << "After changing s2, s1 data: ";
    s1.printInfo();
    
    std::cout << "---\n\n";
}

void demonstrateStaticInitialization() {
    std::cout << "4. Static Initialization:\n";
    
    // TODO: Show static initialization order and timing
    std::cout << "Before initialization:\n";
    StaticInitOrder::printStatics();
    
    StaticInitOrder::initializeStatics();
    
    std::cout << "After initialization:\n";
    StaticInitOrder::printStatics();
    
    // Create instances to see initialization
    StaticInitOrder obj1;
    StaticInitOrder obj2;
    
    std::cout << "---\n\n";
}

void demonstrateStaticLinkage() {
    std::cout << "5. Static Linkage:\n";
    
    // TODO: Show internal vs external linkage
    std::cout << "Static (internal linkage) variable in namespace: ";
    StaticNamespace::internalFunction();
    
    std::cout << "External linkage function: ";
    StaticNamespace::externalFunction();
    
    StaticNamespace::NamespaceClass::classStaticMethod();
    
    std::cout << "---\n\n";
}

void demonstrateStaticStorageDuration() {
    std::cout << "6. Static Storage Duration:\n";
    
    // TODO: Show different types of static storage
    StorageDurationDemo demo;
    demo.demonstrateStorageDuration();
    
    StorageDurationDemo::staticDemonstration();
    
    std::cout << "---\n\n";
}

void demonstrateStaticTemplates() {
    std::cout << "7. Static with Templates:\n";
    
    // TODO: Show static members in template classes
    StaticTemplate<int>::setStaticVar(100);
    StaticTemplate<int>::setStaticValue(42);
    
    StaticTemplate<std::string>::setStaticVar(200);
    StaticTemplate<std::string>::setStaticValue("Hello");
    
    std::cout << "Int template statics:\n";
    StaticTemplate<int>::printTemplateStatics();
    
    std::cout << "String template statics:\n";
    StaticTemplate<std::string>::printTemplateStatics();
    
    // Each template instantiation has its own static variables
    std::cout << "Different template instantiations have separate static variables\n";
    
    std::cout << "---\n\n";
}

void demonstrateThreadSafeStatics() {
    std::cout << "8. Thread-Safe Static Initialization:\n";
    
    // TODO: Show C++11 thread-safe static initialization
    ThreadSafeStatic& instance1 = ThreadSafeStatic::getInstance();
    ThreadSafeStatic& instance2 = ThreadSafeStatic::getInstance();
    
    std::cout << "Thread-safe singleton instances are same: " 
              << (&instance1 == &instance2 ? "Yes" : "No") << "\n";
    
    // Static local variables are thread-safe since C++11
    int& counter1 = ThreadSafeStatic::getStaticCounter();
    int& counter2 = ThreadSafeStatic::getStaticCounter();
    
    counter1++;
    std::cout << "Counter value: " << counter2 << "\n";
    
    std::cout << "---\n\n";
}

void demonstrateStaticBestPractices() {
    std::cout << "9. Static Keyword Best Practices:\n";
    
    // TODO: List best practices for static usage
    std::cout << "Best practices:\n";
    std::cout << "1. Use static for class-wide data/functions\n";
    std::cout << "2. Prefer static local variables over global variables\n";
    std::cout << "3. Initialize static const members in class definition\n";
    std::cout << "4. Be aware of static initialization order fiasco\n";
    std::cout << "5. Use static for internal linkage in namespaces\n";
    std::cout << "6. Consider thread safety with static variables\n";
    std::cout << "7. Document static member lifetimes\n";
    
    std::cout << "\nCommon pitfalls:\n";
    std::cout << "- Static initialization order between translation units\n";
    std::cout << "- Memory not freed for static objects\n";
    std::cout << "- Thread safety issues in multi-threaded code\n";
    std::cout << "- Hidden dependencies through static state\n";
    
    std::cout << "---\n\n";
}

// TODO: Implement all function definitions and static member definitions

// Function implementations
int regularCounter() {
    int count = 0;  // Reset every call
    return ++count;
}

int staticCounter() {
    static int count = 0;  // Persists between calls
    return ++count;
}

// TODO: Implement remaining class methods and static member definitions...

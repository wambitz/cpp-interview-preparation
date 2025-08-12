/*
 * Copy Semantics - Interview Topics
 * 
 * Key Topics to Cover:
 * - Copy constructor and copy assignment
 * - Deep vs shallow copy
 * - Rule of Three
 * - Copy semantics with resources
 * - Copy optimization (RVO)
 * - Copy vs Move semantics
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <memory>

// TODO: Implement these classes demonstrating different copy semantics

// 1. Simple copy class (value semantics)
class SimpleClass {
private:
    int value;
    std::string name;
    
public:
    SimpleClass(int val = 0, const std::string& n = "");
    
    // Copy constructor
    SimpleClass(const SimpleClass& other);
    
    // Copy assignment operator
    SimpleClass& operator=(const SimpleClass& other);
    
    // Destructor
    ~SimpleClass();
    
    // Getters
    int getValue() const;
    const std::string& getName() const;
    
    // Setters
    void setValue(int val);
    void setName(const std::string& n);
    
    void print() const;
};

// 2. Resource-owning class requiring deep copy
class DynamicArray {
private:
    int* data;
    size_t size;
    size_t capacity;
    
public:
    DynamicArray(size_t cap = 10);
    
    // Copy constructor (deep copy)
    DynamicArray(const DynamicArray& other);
    
    // Copy assignment operator (deep copy)
    DynamicArray& operator=(const DynamicArray& other);
    
    // Destructor
    ~DynamicArray();
    
    void push_back(int value);
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    
    size_t getSize() const;
    size_t getCapacity() const;
    
    void print() const;
    
private:
    void resize();
    void cleanup();
    void copyFrom(const DynamicArray& other);
};

// 3. Class demonstrating shallow vs deep copy issues
class BadCopyClass {
private:
    char* buffer;
    size_t length;
    
public:
    BadCopyClass(const char* str);
    
    // BROKEN: Default copy constructor would do shallow copy
    // We'll provide both bad and good versions
    
    // Destructor
    ~BadCopyClass();
    
    const char* getString() const;
    size_t getLength() const;
    void print() const;
};

class GoodCopyClass {
private:
    char* buffer;
    size_t length;
    
public:
    GoodCopyClass(const char* str);
    
    // Proper copy constructor (deep copy)
    GoodCopyClass(const GoodCopyClass& other);
    
    // Proper copy assignment operator
    GoodCopyClass& operator=(const GoodCopyClass& other);
    
    // Destructor
    ~GoodCopyClass();
    
    const char* getString() const;
    size_t getLength() const;
    void print() const;
    
private:
    void copyFrom(const GoodCopyClass& other);
    void cleanup();
};

// 4. Class with copy-only semantics (non-movable)
class CopyOnlyClass {
private:
    std::unique_ptr<int[]> data;
    size_t size;
    
public:
    CopyOnlyClass(size_t s);
    
    // Copy operations
    CopyOnlyClass(const CopyOnlyClass& other);
    CopyOnlyClass& operator=(const CopyOnlyClass& other);
    
    // Explicitly delete move operations
    CopyOnlyClass(CopyOnlyClass&&) = delete;
    CopyOnlyClass& operator=(CopyOnlyClass&&) = delete;
    
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    size_t getSize() const;
    void print() const;
};

// 5. Smart copy class with reference counting (shared ownership)
class SharedData {
private:
    struct DataBlock {
        std::vector<int> values;
        int refCount;
        
        DataBlock(const std::vector<int>& vals) : values(vals), refCount(1) {}
    };
    
    DataBlock* dataPtr;
    
public:
    SharedData(const std::vector<int>& values);
    
    // Copy constructor (shares data)
    SharedData(const SharedData& other);
    
    // Copy assignment operator
    SharedData& operator=(const SharedData& other);
    
    // Destructor
    ~SharedData();
    
    // Copy-on-write modification
    void modify(size_t index, int value);
    
    const std::vector<int>& getData() const;
    int getRefCount() const;
    void print() const;
    
private:
    void release();
    void detach(); // For copy-on-write
};

// Function prototypes for demonstrations
void demonstrateSimpleCopy();
void demonstrateDeepCopy();
void demonstrateShallowCopyProblems();
void demonstrateCopyOptimization();
void demonstrateRuleOfThree();
void demonstrateCopySemantics();
void demonstrateCopyOnlyClasses();
void demonstrateSharedCopy();
void compareCopyVsMove();

int main() {
    std::cout << "=== Copy Semantics Examples ===

";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateSimpleCopy();
    demonstrateDeepCopy();
    demonstrateShallowCopyProblems();
    demonstrateCopyOptimization();
    demonstrateRuleOfThree();
    demonstrateCopySemantics();
    demonstrateCopyOnlyClasses();
    demonstrateSharedCopy();
    compareCopyVsMove();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateSimpleCopy() {
    std::cout << "1. Simple Copy Semantics:
";
    
    // TODO: Show basic copy constructor and assignment
    SimpleClass obj1(42, "Original");
    std::cout << "Original: ";
    obj1.print();
    
    // Copy constructor
    SimpleClass obj2 = obj1;
    std::cout << "Copy constructed: ";
    obj2.print();
    
    // Copy assignment
    SimpleClass obj3;
    obj3 = obj1;
    std::cout << "Copy assigned: ";
    obj3.print();
    
    // Modify original to show independence
    obj1.setValue(100);
    obj1.setName("Modified");
    
    std::cout << "After modifying original:
";
    std::cout << "Original: ";
    obj1.print();
    std::cout << "Copy: ";
    obj2.print();
    
    std::cout << "---

";
}

void demonstrateDeepCopy() {
    std::cout << "2. Deep Copy with Dynamic Memory:
";
    
    // TODO: Show deep copy necessity with dynamic memory
    DynamicArray arr1(5);
    arr1.push_back(10);
    arr1.push_back(20);
    arr1.push_back(30);
    
    std::cout << "Original array: ";
    arr1.print();
    
    // Deep copy
    DynamicArray arr2 = arr1;
    std::cout << "Copied array: ";
    arr2.print();
    
    // Modify original
    arr1.push_back(40);
    arr1[0] = 999;
    
    std::cout << "After modifying original:
";
    std::cout << "Original: ";
    arr1.print();
    std::cout << "Copy: ";
    arr2.print();
    
    std::cout << "---

";
}

void demonstrateShallowCopyProblems() {
    std::cout << "3. Shallow Copy Problems:
";
    
    // TODO: Show problems with shallow copy
    std::cout << "Demonstrating why shallow copy is dangerous with raw pointers
";
    std::cout << "This would cause double deletion if we used default copy constructor
";
    
    // Instead, show the proper implementation
    GoodCopyClass good1("Hello World");
    GoodCopyClass good2 = good1;
    
    std::cout << "Good copy implementation:
";
    std::cout << "Original: ";
    good1.print();
    std::cout << "Copy: ";
    good2.print();
    
    std::cout << "Both objects can be safely destroyed
";
    
    std::cout << "---

";
}

void demonstrateCopyOptimization() {
    std::cout << "4. Copy Optimization (RVO/NRVO):
";
    
    // TODO: Show Return Value Optimization
    auto createObject = []() -> SimpleClass {
        return SimpleClass(100, "RVO Test");
    };
    
    // RVO eliminates copy here
    SimpleClass obj = createObject();
    std::cout << "RVO object: ";
    obj.print();
    
    std::cout << "Note: Modern compilers optimize away unnecessary copies
";
    
    std::cout << "---

";
}

void demonstrateRuleOfThree() {
    std::cout << "5. Rule of Three:
";
    
    // TODO: Explain and demonstrate Rule of Three
    std::cout << "Rule of Three: If you need one of these, you probably need all three:
";
    std::cout << "1. Destructor
";
    std::cout << "2. Copy constructor
";
    std::cout << "3. Copy assignment operator
";
    
    std::cout << "DynamicArray class implements all three:
";
    
    DynamicArray* arr = new DynamicArray(3);
    arr->push_back(1);
    arr->push_back(2);
    
    DynamicArray arr2 = *arr;  // Copy constructor
    DynamicArray arr3(5);
    arr3 = *arr;              // Copy assignment
    
    delete arr;               // Destructor called
    
    std::cout << "All operations completed safely
";
    
    std::cout << "---

";
}

void demonstrateCopySemantics() {
    std::cout << "6. Copy Semantics Behavior:
";
    
    // TODO: Show different copy scenarios
    std::cout << "Copy by value (expensive for large objects):
";
    
    auto passByValue = [](DynamicArray arr) {
        std::cout << "Inside function: ";
        arr.print();
    };
    
    auto passByReference = [](const DynamicArray& arr) {
        std::cout << "By reference: ";
        arr.print();
    };
    
    DynamicArray original(3);
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);
    
    std::cout << "Passing by value (triggers copy):
";
    passByValue(original);
    
    std::cout << "Passing by reference (no copy):
";
    passByReference(original);
    
    std::cout << "---

";
}

void demonstrateCopyOnlyClasses() {
    std::cout << "7. Copy-Only Classes:
";
    
    // TODO: Show classes that can only be copied, not moved
    CopyOnlyClass obj1(5);
    obj1[0] = 10;
    obj1[1] = 20;
    
    std::cout << "Original: ";
    obj1.print();
    
    // Can copy
    CopyOnlyClass obj2 = obj1;
    std::cout << "Copy: ";
    obj2.print();
    
    // Cannot move (would cause compile error)
    // CopyOnlyClass obj3 = std::move(obj1); // Error!
    
    std::cout << "This class explicitly disables move semantics
";
    
    std::cout << "---

";
}

void demonstrateSharedCopy() {
    std::cout << "8. Shared Copy (Reference Counting):
";
    
    // TODO: Show copy with shared ownership
    SharedData data1({1, 2, 3, 4, 5});
    std::cout << "Original data: ";
    data1.print();
    
    // Copy shares the data
    SharedData data2 = data1;
    std::cout << "After copy - Ref count: " << data1.getRefCount() << "
";
    
    // Copy-on-write: modifying one doesn't affect the other
    data2.modify(0, 999);
    
    std::cout << "After modification:
";
    std::cout << "Data1: ";
    data1.print();
    std::cout << "Data2: ";
    data2.print();
    
    std::cout << "---

";
}

void compareCopyVsMove() {
    std::cout << "9. Copy vs Move Semantics:
";
    
    // TODO: Compare copy and move operations
    std::cout << "Copy semantics:
";
    std::cout << "- Creates independent copy of data
";
    std::cout << "- Original object remains valid
";
    std::cout << "- More expensive for large objects
";
    std::cout << "- Safe for all scenarios
";
    
    std::cout << "
Move semantics:
";
    std::cout << "- Transfers ownership of resources
";
    std::cout << "- Original object becomes invalid
";
    std::cout << "- More efficient for large objects
";
    std::cout << "- Requires careful design
";
    
    std::cout << "---

";
}

// TODO: Implement all class methods

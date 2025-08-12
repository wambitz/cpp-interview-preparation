/*
 * Memory Management - Interview Topics
 * 
 * Key Topics to Cover:
 * - Stack vs Heap memory
 * - new/delete operators
 * - malloc/free vs new/delete
 * - Memory leaks and how to avoid them
 * - Dynamic arrays
 * - Placement new
 * - Memory alignment
 */

#include <iostream>
#include <new>
#include <cstdlib>

// TODO: Implement these classes and functions

// 1. Stack vs Heap Demonstration
class StackObject {
private:
    int data[1000];  // Large stack object
    
public:
    StackObject(int value);
    ~StackObject();
    void display() const;
};

class HeapObject {
private:
    int* data;
    size_t size;
    
public:
    HeapObject(size_t size, int value);
    ~HeapObject();
    void display() const;
    size_t getSize() const;
};

// 2. Memory Leak Demonstration
class LeakyClass {
private:
    int* data;
    
public:
    LeakyClass(size_t size);
    ~LeakyClass();  // TODO: Implement proper cleanup
    
    void reallocate(size_t newSize);  // Potential leak source
    void display() const;
};

// 3. RAII Memory Management
class RAIIMemory {
private:
    int* data;
    size_t size;
    
public:
    RAIIMemory(size_t size);
    ~RAIIMemory();
    
    // Rule of Five
    RAIIMemory(const RAIIMemory& other);
    RAIIMemory& operator=(const RAIIMemory& other);
    RAIIMemory(RAIIMemory&& other) noexcept;
    RAIIMemory& operator=(RAIIMemory&& other) noexcept;
    
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    size_t getSize() const;
};

// 4. Placement New Demonstration
class PlacementDemo {
private:
    int value;
    
public:
    PlacementDemo(int val);
    ~PlacementDemo();
    
    void display() const;
    int getValue() const;
};

// 5. Custom Memory Allocator (Simple)
class SimpleAllocator {
private:
    static constexpr size_t POOL_SIZE = 1024;
    static char memoryPool[POOL_SIZE];
    static size_t currentOffset;
    
public:
    static void* allocate(size_t size);
    static void deallocate(void* ptr);
    static void reset();
    static size_t getBytesUsed();
};

// Function prototypes
void demonstrateStackVsHeap();
void demonstrateNewDelete();
void demonstrateMallocVsNew();
void demonstrateMemoryLeaks();
void demonstrateDynamicArrays();
void demonstratePlacementNew();
void demonstrateMemoryAlignment();
void demonstrateCustomAllocator();

int main() {
    std::cout << "=== Memory Management Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateStackVsHeap();
    demonstrateNewDelete();
    demonstrateMallocVsNew();
    demonstrateMemoryLeaks();
    demonstrateDynamicArrays();
    demonstratePlacementNew();
    demonstrateMemoryAlignment();
    demonstrateCustomAllocator();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateStackVsHeap() {
    std::cout << "1. Stack vs Heap Memory:\n";
    // Create objects on stack and heap
    // Show lifetime and performance differences
    std::cout << "---\n\n";
}

void demonstrateNewDelete() {
    std::cout << "2. new/delete Operators:\n";
    // Basic new/delete usage
    // Array new/delete
    // Show proper pairing
    std::cout << "---\n\n";
}

void demonstrateMallocVsNew() {
    std::cout << "3. malloc/free vs new/delete:\n";
    // Compare C-style and C++ memory management
    // Show constructor/destructor differences
    std::cout << "---\n\n";
}

void demonstrateMemoryLeaks() {
    std::cout << "4. Memory Leaks:\n";
    // Show common leak scenarios
    // Demonstrate RAII solution
    std::cout << "---\n\n";
}

void demonstrateDynamicArrays() {
    std::cout << "5. Dynamic Arrays:\n";
    // Create dynamic arrays
    // Show 2D array allocation
    std::cout << "---\n\n";
}

void demonstratePlacementNew() {
    std::cout << "6. Placement New:\n";
    // Use placement new syntax
    // Manual constructor/destructor calls
    std::cout << "---\n\n";
}

void demonstrateMemoryAlignment() {
    std::cout << "7. Memory Alignment:\n";
    // Show memory alignment concepts
    // Use alignof and alignas
    std::cout << "---\n\n";
}

void demonstrateCustomAllocator() {
    std::cout << "8. Custom Allocator:\n";
    // Use simple memory pool
    // Show allocation patterns
    std::cout << "---\n\n";
}

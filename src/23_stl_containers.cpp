/*
 * STL Containers - Interview Topics
 * 
 * Key Topics to Cover:
 * - Vector, list, deque
 * - Set, map, unordered_set, unordered_map
 * - Stack, queue, priority_queue
 * - Iterators and their categories
 * - Container adaptors
 * - Time complexities of operations
 */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>

// TODO: Implement these helper functions and classes

// Custom comparator for demonstrating set/map with custom ordering
struct Person {
    std::string name;
    int age;
    
    Person(const std::string& n, int a) : name(n), age(a) {}
    
    bool operator<(const Person& other) const {
        return age < other.age;  // Sort by age
    }
    
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Custom hash function for unordered containers
struct PersonHash {
    std::size_t operator()(const Person& p) const {
        return std::hash<std::string>()(p.name) ^ std::hash<int>()(p.age);
    }
};

// Function prototypes for demonstrations
void demonstrateSequenceContainers();
void demonstrateAssociativeContainers();
void demonstrateUnorderedContainers();
void demonstrateContainerAdaptors();
void demonstrateIterators();
void demonstrateAlgorithms();
void demonstratePerformanceComparison();
void demonstrateContainerChoice();

int main() {
    std::cout << "=== STL Containers Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateSequenceContainers();
    demonstrateAssociativeContainers();
    demonstrateUnorderedContainers();
    demonstrateContainerAdaptors();
    demonstrateIterators();
    demonstrateAlgorithms();
    demonstratePerformanceComparison();
    demonstrateContainerChoice();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateSequenceContainers() {
    std::cout << "1. Sequence Containers (vector, list, deque):\n";
    
    // Vector demonstration
    std::vector<int> vec = {1, 2, 3, 4, 5};
    // TODO: Show vector operations
    // - push_back, pop_back
    // - random access with []
    // - iterators
    // - capacity vs size
    // - reserve and resize
    
    // List demonstration
    std::list<int> lst = {10, 20, 30, 40, 50};
    // TODO: Show list operations
    // - push_front, push_back
    // - bidirectional iterators only
    // - splice operations
    // - no random access
    
    // Deque demonstration
    std::deque<int> deq = {100, 200, 300};
    // TODO: Show deque operations
    // - push_front and push_back
    // - random access
    // - memory layout differences from vector
    
    std::cout << "---\n\n";
}

void demonstrateAssociativeContainers() {
    std::cout << "2. Associative Containers (set, map):\n";
    
    // Set demonstration
    std::set<int> intSet = {3, 1, 4, 1, 5, 9, 2, 6};
    // TODO: Show set operations
    // - automatic sorting
    // - no duplicates
    // - find, insert, erase
    // - lower_bound, upper_bound
    
    // Map demonstration
    std::map<std::string, int> ageMap;
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 35;
    // TODO: Show map operations
    // - key-value pairs
    // - automatic sorting by key
    // - [] operator vs insert
    // - find operations
    
    // Custom comparator with Person
    std::set<Person> personSet;
    personSet.emplace("John", 25);
    personSet.emplace("Jane", 30);
    personSet.emplace("Bob", 20);
    // TODO: Show custom comparator usage
    
    std::cout << "---\n\n";
}

void demonstrateUnorderedContainers() {
    std::cout << "3. Unordered Containers (hash-based):\n";
    
    // Unordered set demonstration
    std::unordered_set<std::string> wordSet = {"apple", "banana", "cherry", "apple"};
    // TODO: Show unordered_set operations
    // - O(1) average case operations
    // - hash table implementation
    // - no ordering guarantees
    // - bucket operations
    
    // Unordered map demonstration
    std::unordered_map<std::string, int> wordCount;
    std::vector<std::string> words = {"hello", "world", "hello", "cpp", "world"};
    // TODO: Count word frequency using unordered_map
    
    // Custom hash with Person
    std::unordered_set<Person, PersonHash> personHashSet;
    // TODO: Show custom hash function usage
    
    std::cout << "---\n\n";
}

void demonstrateContainerAdaptors() {
    std::cout << "4. Container Adaptors (stack, queue, priority_queue):\n";
    
    // Stack demonstration
    std::stack<int> stk;
    // TODO: Show stack operations
    // - push, pop, top
    // - LIFO behavior
    // - underlying container (deque by default)
    
    // Queue demonstration
    std::queue<std::string> que;
    // TODO: Show queue operations
    // - push, pop, front, back
    // - FIFO behavior
    
    // Priority queue demonstration
    std::priority_queue<int> pq;
    // TODO: Show priority queue operations
    // - max heap by default
    // - custom comparator for min heap
    // - top element is always the largest
    
    std::cout << "---\n\n";
}

void demonstrateIterators() {
    std::cout << "5. Iterator Categories:\n";
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {10, 20, 30, 40, 50};
    
    // TODO: Show different iterator categories
    // - Random access iterators (vector)
    // - Bidirectional iterators (list, set, map)
    // - Forward iterators (unordered containers)
    // - Input/Output iterators
    
    // TODO: Show iterator operations
    // - begin(), end()
    // - advance(), distance()
    // - iterator arithmetic
    // - const iterators
    // - reverse iterators
    
    std::cout << "---\n\n";
}

void demonstrateAlgorithms() {
    std::cout << "6. STL Algorithms with Containers:\n";
    
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    // TODO: Show common algorithms
    // - std::sort
    // - std::find
    // - std::count
    // - std::transform
    // - std::copy
    // - std::for_each
    // - std::accumulate
    
    std::cout << "---\n\n";
}

void demonstratePerformanceComparison() {
    std::cout << "7. Performance Characteristics:\n";
    
    // TODO: Show time complexity comparisons
    // Vector: O(1) random access, O(n) insertion/deletion in middle
    // List: O(1) insertion/deletion anywhere, O(n) access
    // Set/Map: O(log n) operations
    // Unordered Set/Map: O(1) average case operations
    
    // TODO: Demonstrate when to use each container
    // Memory usage patterns
    // Cache friendliness
    
    std::cout << "---\n\n";
}

void demonstrateContainerChoice() {
    std::cout << "8. Choosing the Right Container:\n";
    
    // TODO: Show decision tree for container selection
    // - Need random access? -> vector or deque
    // - Need frequent insertion/deletion in middle? -> list
    // - Need sorted data? -> set or map
    // - Need fast lookup? -> unordered_set or unordered_map
    // - Need LIFO/FIFO? -> stack or queue
    
    std::cout << "---\n\n";
}

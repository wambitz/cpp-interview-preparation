# C++ Interview Preparation

This repository contains comprehensive C++ interview preparation materials focusing on language features rather than data structures and algorithms.

## Project Structure

```
Study/
├── CMakeLists.txt          # Build configuration
├── README.md              # This file
├── build/                 # Build directory (created after cmake)
└── src/                   # Source files directory (26 numbered topics)
    ├── 01_basics.cpp
    ├── 02_pointers_references.cpp
    ├── 03_classes_objects.cpp
    └── ... (01-26 topic files total)
```

## Building the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Running Individual Topics

Each topic can be compiled and run separately (numbered by complexity):

```bash
# Start with the fundamentals
./01_basics
./02_pointers_references
./03_classes_objects

# Progress through complexity
./10_inheritance
./21_templates
./26_multithreading
```

## Topics Covered (Ordered by Complexity: 01-26)

All 25 files now have comprehensive implementation structures with classes, demonstration functions, and TODO implementation points.

### **Fundamentals (01-04)**
- **01_basics.cpp** - Data types, variables, functions, scope, parameter passing
- **02_pointers_references.cpp** - Pointer operations, references, function pointers, pointer arithmetic
- **03_classes_objects.cpp** - Constructors, destructors, Rule of 3/5, static members
- **04_const_correctness.cpp** - Const variables, member functions, const parameters

### **Functions & Operators (05-06)**
- **05_function_overloading.cpp** - Overload resolution, const overloading, templates
- **06_operator_overloading.cpp** - Arithmetic, comparison, stream operators, best practices

### **Memory & Storage (07-09)**
- **07_memory_management.cpp** - Stack/heap, new/delete, memory leaks, RAII principles
- **08_static_keyword.cpp** - Static variables, members, linkage, initialization order
- **09_namespaces.cpp** - Namespace usage, ADL, anonymous namespaces, aliases

### **Advanced OOP (10-14)**
- **10_inheritance.cpp** - Single/multiple inheritance, diamond problem, access levels
- **11_polymorphism.cpp** - Runtime vs compile-time polymorphism, virtual dispatch
- **12_virtual_functions.cpp** - Virtual functions, vtables, pure virtual, final keyword
- **13_friend_functions.cpp** - Friend functions and classes, breaking encapsulation
- **14_casting.cpp** - static_cast, dynamic_cast, const_cast, reinterpret_cast, safety

### **Object Semantics (15-17)**
- **15_copy_semantics.cpp** - Copy constructors, assignment operators, deep/shallow copy
- **16_exception_handling.cpp** - try/catch, custom exceptions, exception safety, RAII
- **17_raii.cpp** - Resource management, automatic cleanup, scope guards

### **Modern C++ (18-20)**
- **18_smart_pointers.cpp** - unique_ptr, shared_ptr, weak_ptr, custom deleters
- **19_move_semantics.cpp** - Move constructors, perfect forwarding, RVO, rvalue references
- **20_auto_decltype.cpp** - Type deduction, auto keyword, decltype, decltype(auto)

### **Generic Programming (21-23)**
- **21_templates.cpp** - Function/class templates, specialization, variadic templates, SFINAE
- **22_lambda_functions.cpp** - Lambda syntax, captures, generic lambdas, closures
- **23_stl_containers.cpp** - Vector, map, set, iterators, algorithms, container selection

### **System Level (24-26)**
- **24_preprocessor.cpp** - Macros, header guards, conditional compilation, alternatives
- **25_file_io.cpp** - File streams, error handling, binary operations, RAII file handling
- **26_multithreading.cpp** - std::thread, mutex, condition variables, atomics, synchronization

## 🎯 Implementation Pattern

Each file contains:
- **Complete class hierarchies** with realistic interview scenarios
- **Comprehensive demonstration functions** that showcase each concept progressively
- **Specific TODO implementation points** marking exactly what needs to be coded
- **Progressive examples** from basic to advanced usage patterns
- **Interview-focused scenarios** covering the most commonly asked questions

## 🚀 Study Approach

### **Recommended Learning Path:**
1. **Start with fundamentals (01-04)** - Build solid foundation
2. **Progress through numbered sequence** - Each topic builds on previous ones
3. **Implement TODO sections** - Fill in class methods and demonstration functions
4. **Test your implementations** - Compile and run each executable
5. **Practice explaining concepts** - Prepare for verbal explanations

### **Build and Test Individual Topics:**
```bash
# Work on specific complexity levels
make 01_basics && ./01_basics                    # Foundation
make 10_inheritance && ./10_inheritance          # OOP concepts  
make 18_smart_pointers && ./18_smart_pointers    # Modern C++
make 26_multithreading && ./26_multithreading    # Advanced topics

# Or build everything (some will have linking errors = your TODO list!)
make
```

## Interview Focus Areas

### **High Priority (Most Commonly Asked) - Topics 01-17**
1. **Classes and Objects (03)** - Constructor/destructor, Rule of 3/5/0
2. **Inheritance & Polymorphism (10-12)** - Virtual functions, inheritance hierarchies  
3. **Memory Management (07, 17, 18)** - Stack vs heap, RAII, smart pointers
4. **Const Correctness (04)** - const member functions, const parameters
5. **Move Semantics (19)** - rvalue references, move constructors, perfect forwarding

### **Medium Priority - Topics 05-09, 13-16, 20-23**
1. **Function & Operator Overloading (05-06)** - Overload resolution, best practices
2. **Exception Handling (16)** - Exception safety, RAII integration
3. **Templates & STL (21, 23)** - Basic template usage, container selection
4. **Copy Semantics (15)** - Deep vs shallow copy, assignment operators
5. **Modern C++ Features (20, 22)** - auto, decltype, lambdas

### **Advanced Topics - Topics 24-26**
1. **Multithreading (26)** - Basic thread safety, synchronization primitives
2. **System Programming (24-25)** - Preprocessor, file I/O
3. **Template Metaprogramming (21)** - Advanced template techniques, SFINAE

## 📚 Study Strategy

### **Week 1: Foundation (01-09)**
- Master basic language features and memory concepts
- Focus on getting comfortable with pointers, classes, and const correctness

### **Week 2: OOP Mastery (10-17)** 
- Deep dive into inheritance, polymorphism, and object lifecycle
- Understand RAII and exception safety patterns

### **Week 3: Modern C++ (18-23)**
- Learn smart pointers, move semantics, and template basics
- Practice with STL containers and lambda functions

### **Week 4: Advanced Topics (24-26)**
- Cover system-level programming and multithreading basics
- Focus on practical interview scenarios

## Common Interview Questions

- Explain the difference between stack and heap
- What is RAII and why is it important?
- When would you use a virtual destructor?
- Explain move semantics and when to use it
- What's the difference between const and constexpr?
- How do smart pointers work internally?
- Explain the Rule of Three/Five/Zero

Good luck with your interview preparation!

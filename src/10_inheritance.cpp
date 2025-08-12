/*
 * Inheritance - Interview Topics
 * 
 * Key Topics to Cover:
 * - Single and multiple inheritance
 * - Public, protected, private inheritance
 * - Constructor/destructor order in inheritance
 * - Diamond problem and virtual inheritance
 * - Base class initialization
 * - Slicing problem
 */

#include <iostream>
#include <string>

// TODO: Implement these classes

// 1. Basic Single Inheritance
class Animal {
protected:
    std::string name;
    int age;
    
public:
    Animal(const std::string& name, int age);
    virtual ~Animal();
    
    virtual void makeSound() const;
    virtual void move() const;
    void sleep() const;
    
    const std::string& getName() const;
    int getAge() const;
};

class Dog : public Animal {
private:
    std::string breed;
    
public:
    Dog(const std::string& name, int age, const std::string& breed);
    ~Dog();
    
    void makeSound() const override;
    void move() const override;
    void fetch() const;  // Dog-specific method
    
    const std::string& getBreed() const;
};

// 2. Different Access Levels in Inheritance
class Vehicle {
protected:
    std::string make;
    int year;
    
public:
    Vehicle(const std::string& make, int year);
    virtual ~Vehicle() = default;
    
    virtual void start() const;
    void displayInfo() const;
};

class PublicCar : public Vehicle {
public:
    PublicCar(const std::string& make, int year);
    void start() const override;
    void accessDemo() const;
};

class ProtectedCar : protected Vehicle {
public:
    ProtectedCar(const std::string& make, int year);
    void start() const override;
    void accessDemo() const;
};

class PrivateCar : private Vehicle {
public:
    PrivateCar(const std::string& make, int year);
    void start() const override;
    void accessDemo() const;
};

// 3. Multiple Inheritance
class Flyable {
protected:
    double maxAltitude;
    
public:
    Flyable(double altitude);
    virtual ~Flyable() = default;
    
    virtual void fly() const;
    double getMaxAltitude() const;
};

class Swimmable {
protected:
    double maxDepth;
    
public:
    Swimmable(double depth);
    virtual ~Swimmable() = default;
    
    virtual void swim() const;
    double getMaxDepth() const;
};

class Duck : public Animal, public Flyable, public Swimmable {
public:
    Duck(const std::string& name, int age, double altitude, double depth);
    ~Duck();
    
    void makeSound() const override;
    void move() const override;
    void fly() const override;
    void swim() const override;
};

// 4. Diamond Problem Demonstration
class Device {
protected:
    std::string deviceId;
    
public:
    Device(const std::string& id);
    virtual ~Device() = default;
    
    virtual void powerOn() const;
    const std::string& getId() const;
};

class InputDevice : virtual public Device {
protected:
    std::string inputType;
    
public:
    InputDevice(const std::string& id, const std::string& type);
    virtual void processInput() const;
};

class OutputDevice : virtual public Device {
protected:
    std::string outputType;
    
public:
    OutputDevice(const std::string& id, const std::string& type);
    virtual void produceOutput() const;
};

class IODevice : public InputDevice, public OutputDevice {
public:
    IODevice(const std::string& id, const std::string& inType, const std::string& outType);
    
    void processInput() const override;
    void produceOutput() const override;
    void processIO() const;
};

// Function prototypes for demonstrations
void demonstrateSingleInheritance();
void demonstrateAccessLevels();
void demonstrateMultipleInheritance();
void demonstrateDiamondProblem();
void demonstrateConstructorOrder();
void demonstrateSlicingProblem();
void demonstrateVirtualInheritance();

int main() {
    std::cout << "=== Inheritance Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateSingleInheritance();
    demonstrateAccessLevels();
    demonstrateMultipleInheritance();
    demonstrateDiamondProblem();
    demonstrateConstructorOrder();
    demonstrateSlicingProblem();
    demonstrateVirtualInheritance();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateSingleInheritance() {
    std::cout << "1. Single Inheritance:\n";
    // Create Animal and Dog objects
    // Show inheritance relationship
    // Demonstrate method overriding
    
    std::cout << "---\n\n";
}

void demonstrateAccessLevels() {
    std::cout << "2. Access Levels in Inheritance:\n";
    // Show public, protected, private inheritance
    // Demonstrate what's accessible in each case
    
    std::cout << "---\n\n";
}

void demonstrateMultipleInheritance() {
    std::cout << "3. Multiple Inheritance:\n";
    // Create Duck object inheriting from multiple bases
    // Show how multiple interfaces are combined
    
    std::cout << "---\n\n";
}

void demonstrateDiamondProblem() {
    std::cout << "4. Diamond Problem:\n";
    // Create IODevice showing diamond inheritance
    // Show how virtual inheritance solves the problem
    
    std::cout << "---\n\n";
}

void demonstrateConstructorOrder() {
    std::cout << "5. Constructor/Destructor Order:\n";
    // Show the order of constructor and destructor calls
    // Base before derived for construction
    // Reverse order for destruction
    
    std::cout << "---\n\n";
}

void demonstrateSlicingProblem() {
    std::cout << "6. Object Slicing Problem:\n";
    // Show what happens when derived object is assigned to base
    // Demonstrate loss of derived-specific data
    
    std::cout << "---\n\n";
}

void demonstrateVirtualInheritance() {
    std::cout << "7. Virtual Inheritance:\n";
    // Show how virtual inheritance prevents duplicate base classes
    // Compare with and without virtual inheritance
    
    std::cout << "---\n\n";
}

// TODO: Implement all the class methods
Animal::Animal(const std::string& name, int age) : name(name), age(age) {
    std::cout << "Animal constructor: " << name << "\n";
}

Animal::~Animal() {
    std::cout << "Animal destructor: " << name << "\n";
}

void Animal::makeSound() const {
    std::cout << name << " makes a generic animal sound\n";
}

void Animal::move() const {
    std::cout << name << " moves around\n";
}

void Animal::sleep() const {
    std::cout << name << " is sleeping\n";
}

const std::string& Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

Dog::Dog(const std::string& name, int age, const std::string& breed) 
    : Animal(name, age), breed(breed) {
    std::cout << "Dog constructor: " << name << " (" << breed << ")\n";
}

Dog::~Dog() {
    std::cout << "Dog destructor: " << name << "\n";
}

void Dog::makeSound() const {
    std::cout << name << " barks: Woof! Woof!\n";
}

void Dog::move() const {
    std::cout << name << " runs on four legs\n";
}

void Dog::fetch() const {
    std::cout << name << " fetches the ball\n";
}

const std::string& Dog::getBreed() const {
    return breed;
}

// TODO: Continue implementing all other class methods...

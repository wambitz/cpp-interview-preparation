/*
 * Friend Functions and Classes - Interview Topics
 * 
 * Key Topics to Cover:
 * - Friend function declaration and definition
 * - Friend class concept and usage
 * - Access to private and protected members
 * - Friend vs member function trade-offs
 * - Operator overloading with friend functions
 * - Friend function best practices and when to use
 * - Forward declarations with friends
 */

#include <iostream>
#include <string>
#include <ostream>
#include <istream>

// TODO: Implement these classes demonstrating friend concepts

// Forward declarations
class Vector3D;
class Matrix;
class BankAccount;

// 1. Basic friend function example
class Point {
private:
    double x, y;
    
public:
    Point(double x = 0, double y = 0);
    
    // Friend function declaration
    friend double distance(const Point& p1, const Point& p2);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend Point operator+(const Point& p1, const Point& p2);
    
    // Friend class declaration
    friend class GeometryCalculator;
    
    // Member functions for comparison
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    
    // Member function version of distance calculation
    double distanceTo(const Point& other) const;
    
    void display() const;
};

// 2. Friend class that can access private members of Point
class GeometryCalculator {
public:
    // Can access private members of Point because it's a friend
    static double calculateArea(const Point& p1, const Point& p2, const Point& p3);
    static Point getCentroid(const Point& p1, const Point& p2, const Point& p3);
    static bool isCollinear(const Point& p1, const Point& p2, const Point& p3);
    static void analyzeTriangle(const Point& p1, const Point& p2, const Point& p3);
    
    // Function showing direct access to private members
    static void debugPoint(const Point& p);
};

// 3. Complex number class with friend operators
class Complex {
private:
    double real, imag;
    
public:
    Complex(double r = 0, double i = 0);
    
    // Friend operator overloads (binary operators work better as friends)
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator*(const Complex& c1, const Complex& c2);
    friend Complex operator/(const Complex& c1, const Complex& c2);
    
    // Comparison operators as friends
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend bool operator!=(const Complex& c1, const Complex& c2);
    
    // Stream operators as friends
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
    
    // Friend function for special operations
    friend double magnitude(const Complex& c);
    friend Complex conjugate(const Complex& c);
    friend double phase(const Complex& c);
    
    // Member functions for comparison
    Complex add(const Complex& other) const;
    void print() const;
    
    // Getters
    double getReal() const;
    double getImag() const;
};

// 4. Matrix class with Vector3D friend relationship
class Vector3D {
private:
    double x, y, z;
    
public:
    Vector3D(double x = 0, double y = 0, double z = 0);
    
    // Friend functions
    friend double dot(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D cross(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator*(const Matrix& m, const Vector3D& v);  // Matrix-vector multiplication
    
    // Friend class
    friend class Matrix;
    
    // Friend operator overloads
    friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator*(double scalar, const Vector3D& v);
    friend Vector3D operator*(const Vector3D& v, double scalar);
    
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);
    
    // Member functions
    double magnitude() const;
    Vector3D normalize() const;
    void display() const;
    
    double getX() const;
    double getY() const;
    double getZ() const;
};

class Matrix {
private:
    double data[3][3];
    
public:
    Matrix();
    Matrix(double values[3][3]);
    
    // Friend function for matrix-vector multiplication
    friend Vector3D operator*(const Matrix& m, const Vector3D& v);
    
    // Friend class that can access private matrix data
    friend class MatrixAnalyzer;
    
    // Member functions
    void setElement(int row, int col, double value);
    double getElement(int row, int col) const;
    void display() const;
    Matrix transpose() const;
};

// 5. Bank account example showing practical friend usage
class BankAccount {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;
    
public:
    BankAccount(const std::string& account, const std::string& owner, double initialBalance = 0);
    
    // Friend function for transfers between accounts
    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
    friend void auditAccounts(const BankAccount& acc1, const BankAccount& acc2);
    
    // Friend class for banking operations
    friend class BankManager;
    
    // Member functions
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    const std::string& getAccountNumber() const;
    const std::string& getOwnerName() const;
    
    void displayInfo() const;
};

class BankManager {
public:
    // Can access private members of BankAccount
    static void generateReport(const BankAccount& account);
    static bool verifyAccount(const BankAccount& account);
    static void emergencyFreeze(BankAccount& account);
    static double calculateInterest(const BankAccount& account, double rate);
};

// Function prototypes for demonstrations
void demonstrateBasicFriendFunctions();
void demonstrateFriendClasses();
void demonstrateFriendOperators();
void demonstrateComplexFriendOperations();
void demonstrateFriendVsMember();
void demonstratePracticalFriendUsage();
void demonstrateFriendBestPractices();

int main() {
    std::cout << "=== Friend Functions and Classes Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicFriendFunctions();
    demonstrateFriendClasses();
    demonstrateFriendOperators();
    demonstrateComplexFriendOperations();
    demonstrateFriendVsMember();
    demonstratePracticalFriendUsage();
    demonstrateFriendBestPractices();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicFriendFunctions() {
    std::cout << "1. Basic Friend Functions:\n";
    
    Point p1(3, 4);
    Point p2(0, 0);
    
    // Using friend function to access private members
    double dist = distance(p1, p2);
    std::cout << "Distance between points: " << dist << "\n";
    
    // Compare with member function
    double distMember = p1.distanceTo(p2);
    std::cout << "Distance using member function: " << distMember << "\n";
    
    // Using friend operator overloads
    std::cout << "Point p1: " << p1 << "\n";
    std::cout << "Point p2: " << p2 << "\n";
    
    Point p3 = p1 + p2;
    std::cout << "p1 + p2 = " << p3 << "\n";
    
    // TODO: Show friend function advantages
    // Direct access to private members
    // Natural syntax for binary operations
    // Symmetric operations
    
    std::cout << "---\n\n";
}

void demonstrateFriendClasses() {
    std::cout << "2. Friend Classes:\n";
    
    Point p1(1, 1);
    Point p2(4, 5);
    Point p3(7, 2);
    
    // Friend class can access private members
    GeometryCalculator::debugPoint(p1);
    
    double area = GeometryCalculator::calculateArea(p1, p2, p3);
    std::cout << "Triangle area: " << area << "\n";
    
    Point centroid = GeometryCalculator::getCentroid(p1, p2, p3);
    std::cout << "Triangle centroid: " << centroid << "\n";
    
    bool collinear = GeometryCalculator::isCollinear(p1, p2, p3);
    std::cout << "Points are collinear: " << (collinear ? "Yes" : "No") << "\n";
    
    GeometryCalculator::analyzeTriangle(p1, p2, p3);
    
    // TODO: Show friend class benefits
    // Multiple functions need access to private data
    // Logical grouping of related operations
    // Better encapsulation than individual friend functions
    
    std::cout << "---\n\n";
}

void demonstrateFriendOperators() {
    std::cout << "3. Friend Operator Overloading:\n";
    
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";
    
    // Friend operators provide natural syntax
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;
    
    std::cout << "c1 + c2 = " << sum << "\n";
    std::cout << "c1 - c2 = " << diff << "\n";
    std::cout << "c1 * c2 = " << product << "\n";
    std::cout << "c1 / c2 = " << quotient << "\n";
    
    // Comparison operators
    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << "\n";
    std::cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << "\n";
    
    // Friend functions for mathematical operations
    std::cout << "Magnitude of c1: " << magnitude(c1) << "\n";
    std::cout << "Conjugate of c1: " << conjugate(c1) << "\n";
    std::cout << "Phase of c1: " << phase(c1) << " radians\n";
    
    // TODO: Show why operators work better as friends
    // Symmetric operations (a + b same as b + a)
    // Type conversions work naturally
    // Stream operators must be friends
    
    std::cout << "---\n\n";
}

void demonstrateComplexFriendOperations() {
    std::cout << "4. Complex Friend Operations:\n";
    
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    
    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";
    
    // Friend functions for vector operations
    double dotProduct = dot(v1, v2);
    Vector3D crossProduct = cross(v1, v2);
    
    std::cout << "Dot product: " << dotProduct << "\n";
    std::cout << "Cross product: " << crossProduct << "\n";
    
    // Friend operators
    Vector3D sum = v1 + v2;
    Vector3D scaled = 2.5 * v1;
    
    std::cout << "v1 + v2 = " << sum << "\n";
    std::cout << "2.5 * v1 = " << scaled << "\n";
    
    // Matrix-vector multiplication using friend
    Matrix m;
    Vector3D result = m * v1;
    std::cout << "Matrix * v1 = " << result << "\n";
    
    std::cout << "---\n\n";
}

void demonstrateFriendVsMember() {
    std::cout << "5. Friend vs Member Function Comparison:\n";
    
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    // Member function approach
    Complex memberSum = c1.add(c2);
    std::cout << "Member function add: ";
    memberSum.print();
    
    // Friend function approach
    Complex friendSum = c1 + c2;
    std::cout << "Friend operator: " << friendSum << "\n";
    
    std::cout << "\nComparison:\n";
    std::cout << "Member functions:\n";
    std::cout << "- Natural for unary operations\n";
    std::cout << "- Access to 'this' pointer\n";
    std::cout << "- Asymmetric syntax (obj.func(arg))\n";
    
    std::cout << "\nFriend functions:\n";
    std::cout << "- Natural for binary operations\n";
    std::cout << "- Symmetric syntax (func(obj1, obj2))\n";
    std::cout << "- Enable type conversions on left operand\n";
    std::cout << "- Required for stream operators\n";
    
    std::cout << "---\n\n";
}

void demonstratePracticalFriendUsage() {
    std::cout << "6. Practical Friend Usage:\n";
    
    BankAccount account1("12345", "Alice", 1000.0);
    BankAccount account2("67890", "Bob", 500.0);
    
    std::cout << "Initial account states:\n";
    account1.displayInfo();
    account2.displayInfo();
    
    // Friend function for transfer operation
    bool success = transfer(account1, account2, 300.0);
    std::cout << "\nTransfer " << (success ? "successful" : "failed") << "\n";
    
    std::cout << "After transfer:\n";
    account1.displayInfo();
    account2.displayInfo();
    
    // Friend class operations
    BankManager::generateReport(account1);
    bool valid = BankManager::verifyAccount(account2);
    std::cout << "Account verification: " << (valid ? "Valid" : "Invalid") << "\n";
    
    double interest = BankManager::calculateInterest(account1, 0.05);
    std::cout << "Interest calculation: $" << interest << "\n";
    
    // Friend function for auditing
    auditAccounts(account1, account2);
    
    std::cout << "---\n\n";
}

void demonstrateFriendBestPractices() {
    std::cout << "7. Friend Function Best Practices:\n";
    
    std::cout << "When to use friend functions:\n";
    std::cout << "1. Binary operators that need access to private data\n";
    std::cout << "2. Stream operators (<< and >>)\n";
    std::cout << "3. Operations that need symmetric access to multiple objects\n";
    std::cout << "4. Functions that conceptually belong to the class but need special access\n";
    
    std::cout << "\nWhen to use friend classes:\n";
    std::cout << "1. Tightly coupled classes that need mutual access\n";
    std::cout << "2. Implementation classes that support a public interface\n";
    std::cout << "3. Test classes that need to verify internal state\n";
    
    std::cout << "\nBest practices:\n";
    std::cout << "1. Use friends sparingly - they break encapsulation\n";
    std::cout << "2. Prefer member functions when possible\n";
    std::cout << "3. Document why friend access is necessary\n";
    std::cout << "4. Consider if public interface can be improved instead\n";
    std::cout << "5. Friends are not inherited or mutual\n";
    std::cout << "6. Forward declare classes when needed for friend declarations\n";
    
    std::cout << "---\n\n";
}

// TODO: Implement all class methods and friend functions

// Point class implementation
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }
void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

double Point::distanceTo(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx*dx + dy*dy);
}

void Point::display() const {
    std::cout << "(" << x << ", " << y << ")";
}

// Friend functions for Point
double distance(const Point& p1, const Point& p2) {
    // Direct access to private members
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx*dx + dy*dy);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

// GeometryCalculator friend class implementation
double GeometryCalculator::calculateArea(const Point& p1, const Point& p2, const Point& p3) {
    // Using shoelace formula with direct access to private members
    return 0.5 * std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
}

Point GeometryCalculator::getCentroid(const Point& p1, const Point& p2, const Point& p3) {
    return Point((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
}

bool GeometryCalculator::isCollinear(const Point& p1, const Point& p2, const Point& p3) {
    // Check if area is essentially zero
    return calculateArea(p1, p2, p3) < 1e-9;
}

void GeometryCalculator::analyzeTriangle(const Point& p1, const Point& p2, const Point& p3) {
    double area = calculateArea(p1, p2, p3);
    Point centroid = getCentroid(p1, p2, p3);
    bool collinear = isCollinear(p1, p2, p3);
    
    std::cout << "Triangle analysis:\n";
    std::cout << "  Area: " << area << "\n";
    std::cout << "  Centroid: " << centroid << "\n";
    std::cout << "  Collinear: " << (collinear ? "Yes" : "No") << "\n";
}

void GeometryCalculator::debugPoint(const Point& p) {
    std::cout << "Debug Point - Direct access to private: x=" << p.x << ", y=" << p.y << "\n";
}

// Complex class implementation
Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

Complex Complex::add(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

void Complex::print() const {
    std::cout << real << " + " << imag << "i\n";
}

// Friend functions for Complex
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(c1.real * c2.real - c1.imag * c2.imag,
                   c1.real * c2.imag + c1.imag * c2.real);
}

Complex operator/(const Complex& c1, const Complex& c2) {
    double denominator = c2.real * c2.real + c2.imag * c2.imag;
    return Complex((c1.real * c2.real + c1.imag * c2.imag) / denominator,
                   (c1.imag * c2.real - c1.real * c2.imag) / denominator);
}

bool operator==(const Complex& c1, const Complex& c2) {
    return (c1.real == c2.real) && (c1.imag == c2.imag);
}

bool operator!=(const Complex& c1, const Complex& c2) {
    return !(c1 == c2);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

double magnitude(const Complex& c) {
    return std::sqrt(c.real * c.real + c.imag * c.imag);
}

Complex conjugate(const Complex& c) {
    return Complex(c.real, -c.imag);
}

double phase(const Complex& c) {
    return std::atan2(c.imag, c.real);
}

// Vector3D implementation
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }

double Vector3D::magnitude() const {
    return std::sqrt(x*x + y*y + z*z);
}

Vector3D Vector3D::normalize() const {
    double mag = magnitude();
    if (mag > 0) {
        return Vector3D(x/mag, y/mag, z/mag);
    }
    return Vector3D(0, 0, 0);
}

void Vector3D::display() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}

// Friend functions for Vector3D
double dot(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D cross(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.y * v2.z - v1.z * v2.y,
                    v1.z * v2.x - v1.x * v2.z,
                    v1.x * v2.y - v1.y * v2.x);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3D operator*(double scalar, const Vector3D& v) {
    return Vector3D(scalar * v.x, scalar * v.y, scalar * v.z);
}

Vector3D operator*(const Vector3D& v, double scalar) {
    return scalar * v;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

// Matrix implementation
Matrix::Matrix() {
    // Initialize identity matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

Matrix::Matrix(double values[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            data[i][j] = values[i][j];
        }
    }
}

void Matrix::setElement(int row, int col, double value) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        data[row][col] = value;
    }
}

double Matrix::getElement(int row, int col) const {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return data[row][col];
    }
    return 0.0;
}

void Matrix::display() const {
    for (int i = 0; i < 3; ++i) {
        std::cout << "[";
        for (int j = 0; j < 3; ++j) {
            std::cout << data[i][j];
            if (j < 2) std::cout << ", ";
        }
        std::cout << "]\n";
    }
}

Matrix Matrix::transpose() const {
    Matrix result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.data[i][j] = data[j][i];
        }
    }
    return result;
}

// Friend function for Matrix-Vector multiplication
Vector3D operator*(const Matrix& m, const Vector3D& v) {
    return Vector3D(
        m.data[0][0] * v.x + m.data[0][1] * v.y + m.data[0][2] * v.z,
        m.data[1][0] * v.x + m.data[1][1] * v.y + m.data[1][2] * v.z,
        m.data[2][0] * v.x + m.data[2][1] * v.y + m.data[2][2] * v.z
    );
}

// BankAccount implementation
BankAccount::BankAccount(const std::string& account, const std::string& owner, double initialBalance)
    : accountNumber(account), ownerName(owner), balance(initialBalance) {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

double BankAccount::getBalance() const { return balance; }
const std::string& BankAccount::getAccountNumber() const { return accountNumber; }
const std::string& BankAccount::getOwnerName() const { return ownerName; }

void BankAccount::displayInfo() const {
    std::cout << "Account: " << accountNumber << ", Owner: " << ownerName 
              << ", Balance: $" << balance << "\n";
}

// Friend functions for BankAccount
bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        return true;
    }
    return false;
}

void auditAccounts(const BankAccount& acc1, const BankAccount& acc2) {
    std::cout << "Audit Report:\n";
    std::cout << "  Account 1: " << acc1.accountNumber << " - $" << acc1.balance << "\n";
    std::cout << "  Account 2: " << acc2.accountNumber << " - $" << acc2.balance << "\n";
    std::cout << "  Total funds: $" << (acc1.balance + acc2.balance) << "\n";
}

// BankManager friend class implementation
void BankManager::generateReport(const BankAccount& account) {
    std::cout << "Bank Report:\n";
    std::cout << "  Account Number: " << account.accountNumber << "\n";
    std::cout << "  Owner: " << account.ownerName << "\n";
    std::cout << "  Current Balance: $" << account.balance << "\n";
}

bool BankManager::verifyAccount(const BankAccount& account) {
    // Direct access to private members for verification
    return !account.accountNumber.empty() && 
           !account.ownerName.empty() && 
           account.balance >= 0;
}

void BankManager::emergencyFreeze(BankAccount& account) {
    std::cout << "Emergency freeze on account " << account.accountNumber << "\n";
    // Could set internal flags, etc.
}

double BankManager::calculateInterest(const BankAccount& account, double rate) {
    return account.balance * rate;
}

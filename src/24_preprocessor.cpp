/*
 * Preprocessor - Interview Topics
 * 
 * Key Topics to Cover:
 * - #define macros and function-like macros
 * - #include directive and header guards
 * - #ifdef, #ifndef, #endif conditional compilation
 * - #pragma directives
 * - Predefined macros (__FILE__, __LINE__, __DATE__, etc.)
 * - Macro stringization and token pasting
 * - Macro pitfalls and modern alternatives
 * - Debug vs Release builds
 */

#include <iostream>
#include <string>
#include <cassert>

// TODO: Demonstrate various preprocessor features

// 1. Simple object-like macros
#define PI 3.14159
#define MAX_SIZE 1000
#define COMPANY_NAME "TechCorp"
#define VERSION_MAJOR 2
#define VERSION_MINOR 1

// 2. Function-like macros
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Dangerous macro (shows common pitfalls)
#define BAD_SQUARE(x) x * x

// Multi-line macro
#define SWAP(type, a, b) do { \
    type temp = a; \
    a = b; \
    b = temp; \
} while(0)

// 3. Stringization and token pasting
#define STRINGIFY(x) #x
#define CONCAT(a, b) a##b
#define MAKE_FUNCTION(name) void function_##name() { \
    std::cout << "Function " << #name << " called\n"; \
}

// Create functions using macros
MAKE_FUNCTION(alpha)
MAKE_FUNCTION(beta)
MAKE_FUNCTION(gamma)

// 4. Conditional compilation
#define DEBUG_MODE 1
#define FEATURE_ENABLED 1

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(msg) std::cout << "[DEBUG] " << msg << "\n"
    #define ASSERT_CHECK(condition) assert(condition)
#else
    #define DEBUG_PRINT(msg)
    #define ASSERT_CHECK(condition)
#endif

// Platform-specific compilation
#ifdef _WIN32
    #define PLATFORM "Windows"
    #define PATH_SEPARATOR "\\"
#elif defined(__linux__)
    #define PLATFORM "Linux"
    #define PATH_SEPARATOR "/"
#elif defined(__APPLE__)
    #define PLATFORM "macOS"
    #define PATH_SEPARATOR "/"
#else
    #define PLATFORM "Unknown"
    #define PATH_SEPARATOR "/"
#endif

// 5. Predefined macros demonstration
void showPredefinedMacros() {
    std::cout << "=== Predefined Macros ===\n";
    std::cout << "File: " << __FILE__ << "\n";
    std::cout << "Line: " << __LINE__ << "\n";
    std::cout << "Date: " << __DATE__ << "\n";
    std::cout << "Time: " << __TIME__ << "\n";
    std::cout << "Function: " << __func__ << "\n";
    
    #ifdef __cplusplus
        std::cout << "C++ Standard: " << __cplusplus << "\n";
    #endif
    
    #ifdef __GNUC__
        std::cout << "GCC Version: " << __GNUC__ << "." << __GNUC_MINOR__ << "\n";
    #endif
    
    std::cout << "Platform: " << PLATFORM << "\n";
    std::cout << "---\n\n";
}

// 6. Macro debugging and inspection
#define DEBUG_VAR(var) std::cout << #var << " = " << var << " (line " << __LINE__ << ")\n"

// 7. Classes demonstrating preprocessor usage
class ConfigurableClass {
private:
    #if FEATURE_ENABLED
        std::string featureData;
    #endif
    
    int baseValue;
    
public:
    ConfigurableClass(int value);
    
    void processData();
    
    #if FEATURE_ENABLED
        void enabledFeature();
        void setFeatureData(const std::string& data);
    #endif
    
    void displayInfo() const;
};

// 8. Macro alternatives using modern C++
namespace ModernAlternatives {
    // Instead of #define PI 3.14159
    constexpr double pi = 3.14159;
    
    // Instead of function-like macros
    constexpr double square(double x) { return x * x; }
    constexpr double max(double a, double b) { return a > b ? a : b; }
    
    // Template alternative to type-generic macros
    template<typename T>
    constexpr T abs(T x) { return x < 0 ? -x : x; }
    
    // Inline function alternative
    inline void debugPrint(const std::string& msg) {
        #ifdef DEBUG_MODE
            std::cout << "[DEBUG] " << msg << "\n";
        #endif
    }
}

// Function prototypes for demonstrations
void demonstrateBasicMacros();
void demonstrateMacroPitfalls();
void demonstrateConditionalCompilation();
void demonstrateStringizationAndPasting();
void demonstrateMacroDebugging();
void demonstrateHeaderGuards();
void demonstratePragmaDirectives();
void demonstrateModernAlternatives();
void demonstratePreprocessorBestPractices();

int main() {
    std::cout << "=== Preprocessor Examples ===\n\n";
    
    // Show predefined macros first
    showPredefinedMacros();
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicMacros();
    demonstrateMacroPitfalls();
    demonstrateConditionalCompilation();
    demonstrateStringizationAndPasting();
    demonstrateMacroDebugging();
    demonstrateHeaderGuards();
    demonstratePragmaDirectives();
    demonstrateModernAlternatives();
    demonstratePreprocessorBestPractices();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicMacros() {
    std::cout << "1. Basic Macro Usage:\n";
    
    // Object-like macros
    std::cout << "PI = " << PI << "\n";
    std::cout << "MAX_SIZE = " << MAX_SIZE << "\n";
    std::cout << "Company: " << COMPANY_NAME << "\n";
    std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "\n";
    
    // Function-like macros
    int x = 5;
    std::cout << "SQUARE(" << x << ") = " << SQUARE(x) << "\n";
    std::cout << "MAX(10, 20) = " << MAX(10, 20) << "\n";
    std::cout << "ABS(-15) = " << ABS(-15) << "\n";
    
    // Multi-statement macro
    int a = 10, b = 20;
    std::cout << "Before swap: a=" << a << ", b=" << b << "\n";
    SWAP(int, a, b);
    std::cout << "After swap: a=" << a << ", b=" << b << "\n";
    
    // TODO: Show macro expansion process
    // Explain how preprocessor works
    // Show macro vs function differences
    
    std::cout << "---\n\n";
}

void demonstrateMacroPitfalls() {
    std::cout << "2. Macro Pitfalls:\n";
    
    // Side effects with function-like macros
    int counter = 5;
    std::cout << "counter = " << counter << "\n";
    
    // This increments counter twice!
    int result1 = SQUARE(++counter);
    std::cout << "SQUARE(++counter) = " << result1 << ", counter = " << counter << "\n";
    
    // Precedence issues
    int result2 = BAD_SQUARE(2 + 3);  // Expands to 2 + 3 * 2 + 3 = 11, not 25!
    std::cout << "BAD_SQUARE(2 + 3) = " << result2 << " (should be 25)\n";
    
    int result3 = SQUARE(2 + 3);      // Correctly expands to ((2 + 3) * (2 + 3)) = 25
    std::cout << "SQUARE(2 + 3) = " << result3 << " (correct)\n";
    
    // TODO: Show other pitfalls
    // Lack of type checking
    // Debugging difficulties
    // Name collisions
    // Unexpected behavior
    
    std::cout << "Common pitfalls:\n";
    std::cout << "- Multiple evaluation of arguments\n";
    std::cout << "- Operator precedence issues\n";
    std::cout << "- No type checking\n";
    std::cout << "- Debugging difficulties\n";
    std::cout << "- Namespace pollution\n";
    
    std::cout << "---\n\n";
}

void demonstrateConditionalCompilation() {
    std::cout << "3. Conditional Compilation:\n";
    
    #if DEBUG_MODE
        std::cout << "Debug mode is enabled\n";
        DEBUG_PRINT("This is a debug message");
    #else
        std::cout << "Release mode\n";
    #endif
    
    #if FEATURE_ENABLED
        std::cout << "Special feature is enabled\n";
    #else
        std::cout << "Special feature is disabled\n";
    #endif
    
    // Platform-specific code
    std::cout << "Running on: " << PLATFORM << "\n";
    std::cout << "Path separator: " << PATH_SEPARATOR << "\n";
    
    // Compiler-specific features
    #ifdef __GNUC__
        std::cout << "Compiled with GCC\n";
    #elif defined(_MSC_VER)
        std::cout << "Compiled with Microsoft Visual C++\n";
    #elif defined(__clang__)
        std::cout << "Compiled with Clang\n";
    #endif
    
    // Version checking
    #if __cplusplus >= 201703L
        std::cout << "C++17 or later features available\n";
    #elif __cplusplus >= 201402L
        std::cout << "C++14 features available\n";
    #elif __cplusplus >= 201103L
        std::cout << "C++11 features available\n";
    #endif
    
    std::cout << "---\n\n";
}

void demonstrateStringizationAndPasting() {
    std::cout << "4. Stringization and Token Pasting:\n";
    
    // Stringization operator (#)
    int value = 42;
    std::cout << STRINGIFY(value) << " = " << value << "\n";
    std::cout << STRINGIFY(PI) << " = " << PI << "\n";
    
    // Token pasting operator (##)
    int var1 = 10;
    int var2 = 20;
    
    // This would create variable names dynamically
    #define ACCESS_VAR(num) var##num
    
    std::cout << "var1 = " << ACCESS_VAR(1) << "\n";
    std::cout << "var2 = " << ACCESS_VAR(2) << "\n";
    
    // Function creation with macros
    function_alpha();
    function_beta();
    function_gamma();
    
    // Create enum values
    #define MAKE_ENUM(name, value) name = value
    
    enum Status {
        MAKE_ENUM(IDLE, 0),
        MAKE_ENUM(RUNNING, 1),
        MAKE_ENUM(STOPPED, 2)
    };
    
    std::cout << "Status values: " << IDLE << ", " << RUNNING << ", " << STOPPED << "\n";
    
    std::cout << "---\n\n";
}

void demonstrateMacroDebugging() {
    std::cout << "5. Macro Debugging:\n";
    
    int x = 10;
    double y = 3.14;
    std::string name = "Example";
    
    // Debug macro that shows variable name and value
    DEBUG_VAR(x);
    DEBUG_VAR(y);
    DEBUG_VAR(name);
    
    // Conditional debugging
    #ifdef DEBUG_MODE
        std::cout << "Debug information available\n";
        ASSERT_CHECK(x > 0);
        ASSERT_CHECK(y > 0);
    #endif
    
    // Function entry/exit tracing
    #define TRACE_FUNCTION() std::cout << "Entering " << __func__ << " at line " << __LINE__ << "\n"
    
    auto testFunction = []() {
        TRACE_FUNCTION();
        std::cout << "Inside test function\n";
    };
    
    testFunction();
    
    std::cout << "---\n\n";
}

void demonstrateHeaderGuards() {
    std::cout << "6. Header Guards (Conceptual):\n";
    
    std::cout << "Traditional header guards:\n";
    std::cout << "#ifndef MY_HEADER_H\n";
    std::cout << "#define MY_HEADER_H\n";
    std::cout << "// header content\n";
    std::cout << "#endif // MY_HEADER_H\n\n";
    
    std::cout << "Modern pragma once:\n";
    std::cout << "#pragma once\n";
    std::cout << "// header content\n\n";
    
    std::cout << "Include guard benefits:\n";
    std::cout << "- Prevents multiple inclusion\n";
    std::cout << "- Avoids redefinition errors\n";
    std::cout << "- Improves compilation time\n";
    
    std::cout << "---\n\n";
}

void demonstratePragmaDirectives() {
    std::cout << "7. Pragma Directives:\n";
    
    std::cout << "Common pragma directives:\n";
    std::cout << "#pragma once - Include guard\n";
    std::cout << "#pragma pack - Structure packing\n";
    std::cout << "#pragma warning - Compiler warnings\n";
    std::cout << "#pragma omp - OpenMP directives\n";
    
    // Example of pragma usage (compiler-specific)
    #pragma message("Compiling preprocessor examples")
    
    // Disable specific warnings (MSVC example)
    #ifdef _MSC_VER
        #pragma warning(push)
        #pragma warning(disable: 4996)  // Disable deprecated function warning
        // Use deprecated function here
        #pragma warning(pop)
    #endif
    
    std::cout << "---\n\n";
}

void demonstrateModernAlternatives() {
    std::cout << "8. Modern C++ Alternatives to Macros:\n";
    
    // Constexpr instead of #define
    std::cout << "Using constexpr instead of macros:\n";
    std::cout << "ModernAlternatives::pi = " << ModernAlternatives::pi << "\n";
    std::cout << "ModernAlternatives::square(5) = " << ModernAlternatives::square(5) << "\n";
    std::cout << "ModernAlternatives::max(10, 20) = " << ModernAlternatives::max(10, 20) << "\n";
    
    // Template functions
    std::cout << "ModernAlternatives::abs(-15) = " << ModernAlternatives::abs(-15) << "\n";
    std::cout << "ModernAlternatives::abs(-3.14) = " << ModernAlternatives::abs(-3.14) << "\n";
    
    // Inline functions for debugging
    ModernAlternatives::debugPrint("Modern debug message");
    
    // Enum class instead of #define constants
    enum class Color { RED, GREEN, BLUE };
    Color color = Color::RED;
    
    // Namespace for grouping constants
    namespace Constants {
        constexpr int maxConnections = 100;
        constexpr double epsilon = 1e-9;
    }
    
    std::cout << "Constants::maxConnections = " << Constants::maxConnections << "\n";
    
    std::cout << "Advantages of modern alternatives:\n";
    std::cout << "- Type safety\n";
    std::cout << "- Scope respect\n";
    std::cout << "- Better debugging\n";
    std::cout << "- Template compatibility\n";
    std::cout << "- Compile-time evaluation\n";
    
    std::cout << "---\n\n";
}

void demonstratePreprocessorBestPractices() {
    std::cout << "9. Preprocessor Best Practices:\n";
    
    std::cout << "Best practices:\n";
    std::cout << "1. Use ALL_CAPS for macro names\n";
    std::cout << "2. Wrap multi-token replacements in parentheses\n";
    std::cout << "3. Use do-while(0) for multi-statement macros\n";
    std::cout << "4. Prefer const/constexpr over #define for constants\n";
    std::cout << "5. Use inline functions instead of function-like macros\n";
    std::cout << "6. Use #pragma once instead of traditional header guards\n";
    std::cout << "7. Be careful with side effects in macro arguments\n";
    std::cout << "8. Use conditional compilation sparingly\n";
    std::cout << "9. Document complex macro usage\n";
    std::cout << "10. Consider templates for generic programming\n";
    
    std::cout << "\nWhen to use macros:\n";
    std::cout << "- Conditional compilation\n";
    std::cout << "- Stringization and token pasting\n";
    std::cout << "- Platform-specific code\n";
    std::cout << "- Debug/release differences\n";
    std::cout << "- Code generation (sparingly)\n";
    
    std::cout << "\nWhen to avoid macros:\n";
    std::cout << "- Simple constants (use const/constexpr)\n";
    std::cout << "- Simple functions (use inline functions)\n";
    std::cout << "- Type-generic code (use templates)\n";
    std::cout << "- Complex logic (use regular functions)\n";
    
    std::cout << "---\n\n";
}

// TODO: Implement class methods
ConfigurableClass::ConfigurableClass(int value) : baseValue(value) {
    #if FEATURE_ENABLED
        featureData = "Default feature data";
    #endif
}

void ConfigurableClass::processData() {
    DEBUG_PRINT("Processing data...");
    
    std::cout << "Base value: " << baseValue << "\n";
    
    #if FEATURE_ENABLED
        std::cout << "Feature data: " << featureData << "\n";
    #else
        std::cout << "Feature not available\n";
    #endif
}

#if FEATURE_ENABLED
void ConfigurableClass::enabledFeature() {
    std::cout << "Special feature is running\n";
}

void ConfigurableClass::setFeatureData(const std::string& data) {
    featureData = data;
}
#endif

void ConfigurableClass::displayInfo() const {
    std::cout << "ConfigurableClass info:\n";
    std::cout << "  Base value: " << baseValue << "\n";
    
    #if FEATURE_ENABLED
        std::cout << "  Feature enabled: Yes\n";
        std::cout << "  Feature data: " << featureData << "\n";
    #else
        std::cout << "  Feature enabled: No\n";
    #endif
    
    std::cout << "  Compiled on: " << __DATE__ << " " << __TIME__ << "\n";
    std::cout << "  Platform: " << PLATFORM << "\n";
}

/*
 * RAII (Resource Acquisition Is Initialization) - Interview Topics
 * 
 * Key Topics to Cover:
 * - RAII principle and benefits
 * - Constructor/destructor pairing
 * - Automatic resource management
 * - RAII with files, memory, locks
 * - Custom RAII classes
 * - Exception safety with RAII
 */

#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

// TODO: Implement these RAII wrapper classes

// 1. File RAII wrapper
class FileRAII {
private:
    std::fstream file;
    std::string filename;
    bool isOpen;
    
public:
    FileRAII(const std::string& filename, std::ios::openmode mode);
    ~FileRAII();
    
    // Delete copy operations to prevent issues
    FileRAII(const FileRAII&) = delete;
    FileRAII& operator=(const FileRAII&) = delete;
    
    // Enable move operations
    FileRAII(FileRAII&& other) noexcept;
    FileRAII& operator=(FileRAII&& other) noexcept;
    
    bool write(const std::string& data);
    std::string read();
    bool isFileOpen() const;
    const std::string& getFilename() const;
};

// 2. Memory RAII wrapper (simplified unique_ptr)
template<typename T>
class MemoryRAII {
private:
    T* ptr;
    
public:
    explicit MemoryRAII(T* p = nullptr);
    ~MemoryRAII();
    
    // Delete copy operations
    MemoryRAII(const MemoryRAII&) = delete;
    MemoryRAII& operator=(const MemoryRAII&) = delete;
    
    // Move operations
    MemoryRAII(MemoryRAII&& other) noexcept;
    MemoryRAII& operator=(MemoryRAII&& other) noexcept;
    
    T& operator*() const;
    T* operator->() const;
    T* get() const;
    T* release();
    void reset(T* p = nullptr);
    explicit operator bool() const;
};

// 3. Lock RAII wrapper
class LockRAII {
private:
    std::mutex& mtx;
    bool locked;
    
public:
    explicit LockRAII(std::mutex& m);
    ~LockRAII();
    
    // Non-copyable, non-movable
    LockRAII(const LockRAII&) = delete;
    LockRAII& operator=(const LockRAII&) = delete;
    LockRAII(LockRAII&&) = delete;
    LockRAII& operator=(LockRAII&&) = delete;
    
    void unlock();
    void lock();
    bool isLocked() const;
};

// 4. Database Connection RAII (simulated)
class DatabaseRAII {
private:
    std::string connectionString;
    bool connected;
    
public:
    DatabaseRAII(const std::string& connStr);
    ~DatabaseRAII();
    
    bool connect();
    void disconnect();
    bool executeQuery(const std::string& query);
    bool isConnected() const;
    
    // Non-copyable but movable
    DatabaseRAII(const DatabaseRAII&) = delete;
    DatabaseRAII& operator=(const DatabaseRAII&) = delete;
    DatabaseRAII(DatabaseRAII&& other) noexcept;
    DatabaseRAII& operator=(DatabaseRAII&& other) noexcept;
};

// 5. Resource pool RAII
class ResourcePool {
private:
    std::vector<std::string> availableResources;
    std::vector<std::string> usedResources;
    std::mutex poolMutex;
    
public:
    ResourcePool(const std::vector<std::string>& resources);
    
    class ResourceHandle {
    private:
        ResourcePool& pool;
        std::string resource;
        bool valid;
        
    public:
        ResourceHandle(ResourcePool& p, const std::string& res);
        ~ResourceHandle();
        
        // Non-copyable but movable
        ResourceHandle(const ResourceHandle&) = delete;
        ResourceHandle& operator=(const ResourceHandle&) = delete;
        ResourceHandle(ResourceHandle&& other) noexcept;
        ResourceHandle& operator=(ResourceHandle&& other) noexcept;
        
        const std::string& getResource() const;
        bool isValid() const;
    };
    
    ResourceHandle acquireResource();
    void releaseResource(const std::string& resource);
    size_t availableCount() const;
};

// Function prototypes for demonstrations
void demonstrateFileRAII();
void demonstrateMemoryRAII();
void demonstrateLockRAII();
void demonstrateExceptionSafety();
void demonstrateResourceLifecycle();
void demonstrateRAIIBenefits();
void demonstrateRAIIPatterns();
void demonstrateRAIIWithStandardLibrary();

int main() {
    std::cout << "=== RAII Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateFileRAII();
    demonstrateMemoryRAII();
    demonstrateLockRAII();
    demonstrateExceptionSafety();
    demonstrateResourceLifecycle();
    demonstrateRAIIBenefits();
    demonstrateRAIIPatterns();
    demonstrateRAIIWithStandardLibrary();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateFileRAII() {
    std::cout << "1. File RAII:\n";
    
    try {
        FileRAII file("test.txt", std::ios::out);
        
        // TODO: Show automatic file management
        // File is automatically opened in constructor
        // File is automatically closed in destructor
        // Exception safety guaranteed
        
        file.write("Hello RAII World!");
        
        // File automatically closed when scope ends
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
        // File still properly closed due to RAII
    }
    
    std::cout << "---\n\n";
}

void demonstrateMemoryRAII() {
    std::cout << "2. Memory RAII:\n";
    
    try {
        MemoryRAII<int> ptr(new int(42));
        
        // TODO: Show automatic memory management
        // Memory automatically deallocated in destructor
        // No memory leaks even with exceptions
        
        std::cout << "Value: " << *ptr << "\n";
        
        // Simulate exception
        // throw std::runtime_error("Test exception");
        
        // Memory automatically freed when scope ends
        
    } catch (const std::exception& e) {
        std::cout << "Exception caught, memory still freed\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateLockRAII() {
    std::cout << "3. Lock RAII:\n";
    
    std::mutex mtx;
    
    try {
        LockRAII lock(mtx);
        
        // TODO: Show automatic lock management
        // Mutex locked in constructor
        // Mutex unlocked in destructor
        // Exception safety for synchronization
        
        std::cout << "Critical section work...\n";
        
        // Simulate exception
        // throw std::runtime_error("Exception in critical section");
        
        // Lock automatically released when scope ends
        
    } catch (const std::exception& e) {
        std::cout << "Exception in critical section, lock still released\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateExceptionSafety() {
    std::cout << "4. Exception Safety with RAII:\n";
    
    // TODO: Show how RAII provides exception safety
    // Compare RAII vs manual resource management
    // Show guaranteed cleanup
    
    try {
        DatabaseRAII db("connection_string");
        MemoryRAII<std::vector<int>> data(new std::vector<int>{1, 2, 3, 4, 5});
        
        // Do work that might throw
        throw std::runtime_error("Simulated error");
        
    } catch (const std::exception& e) {
        std::cout << "All resources cleaned up automatically\n";
    }
    
    std::cout << "---\n\n";
}

void demonstrateResourceLifecycle() {
    std::cout << "5. Resource Lifecycle Management:\n";
    
    // TODO: Show resource lifecycle with RAII
    // Acquisition in constructor
    // Release in destructor
    // Move semantics for transfer
    
    {
        std::cout << "Creating resource pool...\n";
        ResourcePool pool({"Resource1", "Resource2", "Resource3"});
        
        {
            std::cout << "Acquiring resource...\n";
            auto handle = pool.acquireResource();
            std::cout << "Using resource: " << handle.getResource() << "\n";
            
            // Resource automatically returned when handle goes out of scope
        }
        std::cout << "Resource returned to pool\n";
        
        // Pool cleaned up when it goes out of scope
    }
    std::cout << "Pool destroyed\n";
    
    std::cout << "---\n\n";
}

void demonstrateRAIIBenefits() {
    std::cout << "6. RAII Benefits:\n";
    
    // TODO: Highlight RAII benefits:
    // 1. No resource leaks
    // 2. Exception safety
    // 3. Deterministic cleanup
    // 4. Clear ownership semantics
    // 5. Reduced complexity
    
    std::cout << "RAII Benefits:\n";
    std::cout << "- No resource leaks\n";
    std::cout << "- Exception safety\n";
    std::cout << "- Deterministic cleanup\n";
    std::cout << "- Clear ownership semantics\n";
    
    std::cout << "---\n\n";
}

void demonstrateRAIIPatterns() {
    std::cout << "7. Common RAII Patterns:\n";
    
    // TODO: Show common RAII patterns
    // Scope guards
    // Resource handles
    // Smart pointers
    // Lock guards
    
    std::cout << "---\n\n";
}

void demonstrateRAIIWithStandardLibrary() {
    std::cout << "8. RAII in Standard Library:\n";
    
    // TODO: Show standard library RAII examples
    // std::unique_ptr, std::shared_ptr
    // std::lock_guard, std::unique_lock
    // std::fstream
    // std::vector (manages dynamic array)
    
    {
        std::unique_ptr<int> ptr = std::make_unique<int>(100);
        std::lock_guard<std::mutex> lock(/* some mutex */);
        std::vector<int> vec{1, 2, 3, 4, 5};
        
        // All resources automatically managed
    }
    
    std::cout << "---\n\n";
}

// TODO: Implement all class methods

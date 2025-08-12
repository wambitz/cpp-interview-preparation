/*
 * Multithreading - Interview Topics
 * 
 * Key Topics to Cover:
 * - std::thread creation and management
 * - Mutex and lock_guard
 * - Condition variables
 * - Atomic operations
 * - Thread synchronization
 * - Race conditions and deadlocks
 * - Thread-safe containers
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>
#include <queue>
#include <future>
#include <chrono>

// TODO: Implement these classes and functions

// 1. Basic thread demonstration
class ThreadBasics {
public:
    static void simpleTask(int id, const std::string& message);
    static void taskWithParameters(int start, int end, int& result);
    
    void memberFunction(int value);
    
private:
    int memberData = 0;
};

// 2. Thread-safe counter with mutex
class ThreadSafeCounter {
private:
    mutable std::mutex mtx;
    int count;
    
public:
    ThreadSafeCounter(int initial = 0);
    
    void increment();
    void decrement();
    int getValue() const;
    void add(int value);
};

// 3. Producer-Consumer pattern with condition variables
class ProducerConsumer {
private:
    std::queue<int> buffer;
    std::mutex bufferMutex;
    std::condition_variable notEmpty;
    std::condition_variable notFull;
    const size_t maxSize;
    bool finished;
    
public:
    ProducerConsumer(size_t size = 10);
    
    void produce(int item);
    bool consume(int& item);
    void setFinished();
    size_t size() const;
};

// 4. Atomic operations demonstration
class AtomicDemo {
private:
    std::atomic<int> atomicCounter{0};
    std::atomic<bool> flag{false};
    std::atomic<double*> ptr{nullptr};
    
public:
    void incrementAtomic();
    int getAtomicValue() const;
    
    void setFlag();
    bool checkFlag() const;
    
    void demonstrateAtomicOperations();
};

// 5. Deadlock demonstration and prevention
class DeadlockDemo {
private:
    std::mutex mutex1;
    std::mutex mutex2;
    int resource1 = 0;
    int resource2 = 0;
    
public:
    void taskA();  // Potential deadlock
    void taskB();  // Potential deadlock
    
    void taskASafe();  // Deadlock prevention
    void taskBSafe();  // Deadlock prevention
};

// 6. Thread pool (simplified)
class SimpleThreadPool {
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
    
public:
    SimpleThreadPool(size_t numThreads);
    ~SimpleThreadPool();
    
    template<typename F>
    void enqueue(F&& task);
    
    void shutdown();
};

// Function prototypes for demonstrations
void demonstrateBasicThreads();
void demonstrateMutexAndLocking();
void demonstrateConditionVariables();
void demonstrateAtomicOperations();
void demonstrateRaceConditions();
void demonstrateDeadlockPrevention();
void demonstrateFuturesAndPromises();
void demonstrateThreadPool();

int main() {
    std::cout << "=== Multithreading Examples ===\n\n";
    
    // TODO: Call these functions to demonstrate concepts
    demonstrateBasicThreads();
    demonstrateMutexAndLocking();
    demonstrateConditionVariables();
    demonstrateAtomicOperations();
    demonstrateRaceConditions();
    demonstrateDeadlockPrevention();
    demonstrateFuturesAndPromises();
    demonstrateThreadPool();
    
    return 0;
}

// TODO: Implement these demonstration functions
void demonstrateBasicThreads() {
    std::cout << "1. Basic Thread Creation and Management:\n";
    
    // TODO: Create threads with different approaches
    // Function pointers, lambdas, member functions
    // Join vs detach
    // Thread IDs
    
    std::thread t1(ThreadBasics::simpleTask, 1, "Hello from thread 1");
    
    auto lambda = [](int n) {
        for (int i = 0; i < n; ++i) {
            std::cout << "Lambda thread: " << i << "\n";
        }
    };
    std::thread t2(lambda, 3);
    
    // TODO: Join threads and show thread management
    
    std::cout << "---\n\n";
}

void demonstrateMutexAndLocking() {
    std::cout << "2. Mutex and Lock Management:\n";
    
    ThreadSafeCounter counter(0);
    std::vector<std::thread> threads;
    
    // TODO: Create multiple threads that modify shared data
    // Show mutex protection
    // Demonstrate lock_guard, unique_lock
    
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back([&counter, i]() {
            for (int j = 0; j < 10; ++j) {
                counter.increment();
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });
    }
    
    // TODO: Join threads and show final result
    
    std::cout << "---\n\n";
}

void demonstrateConditionVariables() {
    std::cout << "3. Condition Variables:\n";
    
    ProducerConsumer pc(5);
    
    // TODO: Create producer and consumer threads
    // Show wait/notify mechanism
    // Demonstrate spurious wakeups handling
    
    std::thread producer([&pc]() {
        for (int i = 0; i < 10; ++i) {
            pc.produce(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        pc.setFinished();
    });
    
    std::thread consumer([&pc]() {
        int item;
        while (pc.consume(item)) {
            std::cout << "Consumed: " << item << "\n";
        }
    });
    
    // TODO: Join threads
    
    std::cout << "---\n\n";
}

void demonstrateAtomicOperations() {
    std::cout << "4. Atomic Operations:\n";
    
    AtomicDemo demo;
    std::vector<std::thread> threads;
    
    // TODO: Show atomic operations
    // Compare with non-atomic operations
    // Memory ordering (if time permits)
    
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&demo]() {
            for (int j = 0; j < 100; ++j) {
                demo.incrementAtomic();
            }
        });
    }
    
    // TODO: Join and show results
    
    std::cout << "---\n\n";
}

void demonstrateRaceConditions() {
    std::cout << "5. Race Conditions:\n";
    
    // TODO: Show race condition example
    // Demonstrate data races
    // Show how synchronization fixes them
    
    int unsafeCounter = 0;
    std::vector<std::thread> threads;
    
    // Unsafe increment (race condition)
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back([&unsafeCounter]() {
            for (int j = 0; j < 1000; ++j) {
                ++unsafeCounter;  // Race condition!
            }
        });
    }
    
    // TODO: Show unpredictable results
    
    std::cout << "---\n\n";
}

void demonstrateDeadlockPrevention() {
    std::cout << "6. Deadlock Prevention:\n";
    
    DeadlockDemo demo;
    
    // TODO: Show deadlock scenario
    // Demonstrate prevention techniques
    // std::lock, lock ordering
    
    std::cout << "---\n\n";
}

void demonstrateFuturesAndPromises() {
    std::cout << "7. Futures and Promises:\n";
    
    // TODO: Show std::future and std::promise
    // std::async usage
    // std::packaged_task
    
    auto future1 = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return 42;
    });
    
    auto future2 = std::async(std::launch::deferred, []() {
        return std::string("Hello from future");
    });
    
    // TODO: Show how to get results
    
    std::cout << "---\n\n";
}

void demonstrateThreadPool() {
    std::cout << "8. Thread Pool:\n";
    
    // TODO: Create thread pool and submit tasks
    // Show task queuing and execution
    
    SimpleThreadPool pool(4);
    
    for (int i = 0; i < 10; ++i) {
        pool.enqueue([i]() {
            std::cout << "Task " << i << " executing on thread " 
                      << std::this_thread::get_id() << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        });
    }
    
    std::cout << "---\n\n";
}

// TODO: Implement all class methods
void ThreadBasics::simpleTask(int id, const std::string& message) {
    std::cout << "Thread " << id << ": " << message << "\n";
}

void ThreadBasics::taskWithParameters(int start, int end, int& result) {
    result = 0;
    for (int i = start; i <= end; ++i) {
        result += i;
    }
}

void ThreadBasics::memberFunction(int value) {
    memberData = value;
    std::cout << "Member function called with " << value << "\n";
}

ThreadSafeCounter::ThreadSafeCounter(int initial) : count(initial) {}

void ThreadSafeCounter::increment() {
    std::lock_guard<std::mutex> lock(mtx);
    ++count;
}

void ThreadSafeCounter::decrement() {
    std::lock_guard<std::mutex> lock(mtx);
    --count;
}

int ThreadSafeCounter::getValue() const {
    std::lock_guard<std::mutex> lock(mtx);
    return count;
}

void ThreadSafeCounter::add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    count += value;
}

// TODO: Implement remaining class methods...

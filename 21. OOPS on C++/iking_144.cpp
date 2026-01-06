// RAII (RESOURCE ACQUISITION IS INITIALISATION)

// RAII is a core C++ idiom for automatic resource management.
// RAII, which stands for Resource Acquisition Is Initialization, is a fundamental C++ programming idiom that ties the 
// lifetime of a resource to the lifetime of an object. This technique ensures that resources are properly managed, 
// acquired when an object is constructed, and released when the object is destroyed, even in the presence of exceptions.

// Key principles of RAII:
//  >> Resource Ownership: An object takes ownership of a specific resource 
//      (e.g., memory, file handles, network connections, mutexes).

//  >> Acquisition in Constructor: The resource is acquired and initialized within the object's constructor. 
//     This ensures the object is always in a valid state upon creation.

//  >> Release in Destructor: The resource is released and cleaned up within the object's destructor. 
//      Since destructors are automatically called when an object goes out of scope
//      (or is explicitly deleted), this guarantees resource release.

//  >> Exception Safety: Because destructors are guaranteed to be called during stack unwinding, 
//     RAII provides exception safety by ensuring resources are released even if an exception occurs during the object's lifetime.


// SMART POINTERS
// Smart pointers are RAII wrappers for dynamically allocated memory.
// They manage the lifetime of heap-allocated objects so that we don’t have to manually call delete.

#include <memory>
#include <iostream>

// std::unique_ptr
// Exclusive ownership → only one unique_ptr can own the object at a time.
// Cannot be copied; can only be moved.
// Lightest and fastest smart pointer.
class Demo {
public:
    Demo()  { std::cout << "Constructed\n"; }
    ~Demo() { std::cout << "Destructed\n"; }
};

int main() {
    std::unique_ptr<Demo> ptr = std::make_unique<Demo>(); // RAII: constructed
    // ptr automatically deletes Demo at end of scope
}

// std::shared_ptr
// Shared ownership → multiple shared_ptr instances can point to the same object.
// Internally maintains a reference count.
// When the last shared_ptr is destroyed, the resource is freed.
int FUNC1() {
    std::shared_ptr<int> p1 = std::make_shared<int>(10);
    std::shared_ptr<int> p2 = p1; // both share ownership
    std::cout << "Count: " << p1.use_count() << "\n"; // 2
} // both p1 & p2 go out of scope → memory freed automatically
// ENUM

#include <iostream>

// --- Traditional C-style enum (unscoped) ---
enum TrafficLight {
    Red,
    Yellow,
    Green
};

// Another traditional enum with a clashing name
// enum Color {
//     Blue,
//     Green // COMPILER ERROR: 'Green' is redefined. Unscoped enums pollute the parent scope.
// };

// --- C++11 enum class (scoped) ---
enum class Direction {
    North,
    South,
    East,
    West
};

// Another enum class with the same enumerator name. No clash.
enum class Movement {
    North, // OK: This 'North' is scoped to Movement::
    Up,
    Down
};

// Example using a specified underlying type
enum class Status : char {
    Success,
    Failure
};

void processTraffic(TrafficLight light) {
    switch (light) {
        case Red:
            std::cout << "Traffic is Red. Stop." << std::endl;
            break;
        case Yellow:
            std::cout << "Traffic is Yellow. Slow down." << std::endl;
            break;
        case Green:
            std::cout << "Traffic is Green. Go!" << std::endl;
            break;
    }
}

int main() {
    // --- Scoping demonstration ---
    TrafficLight tl = Red; // OK: Red is in the current scope
    std::cout << "Processing TrafficLight..." << std::endl;
    processTraffic(tl);

    // This would be a compiler error due to the `Color` enum.
    // enum Color { Blue, Green }; // Green redefinition error.

    Direction d = Direction::North; // OK: Must be qualified with the enum class name
    // Direction invalid_d = North; // COMPILER ERROR: 'North' is not in this scope

    Movement m = Movement::North; // OK: No name clash with Direction::North
    
    // --- Type Safety and Implicit Conversion ---
    int traffic_light_value = tl; // OK: Implicit conversion from unscoped enum to int
    std::cout << "TrafficLight::Red as int: " << traffic_light_value << std::endl;

    // int direction_value = d; // COMPILER ERROR: Cannot implicitly convert 'Direction' to 'int'
    int direction_value = static_cast<int>(d); // OK: Explicit cast required
    std::cout << "Direction::North as int: " << direction_value << std::endl;

    // --- Preventing comparison bugs ---
    // if (tl == d) // COMPILER ERROR: Cannot compare different enum types
    // {
    //    // This is illegal and prevents logical errors
    // }

    // This comparison compiles for traditional enums but is illogical
    enum Feeling { Happy, Sad };
    TrafficLight tl2 = Green;
    Feeling f = Happy;
    if (tl2 == f) { // OK: Compares underlying integer values (2 == 0),
                    // but the logic is flawed. This code can compile but is wrong.
        std::cout << "Logical error: Comparing unrelated enums implicitly." << std::endl;
    }

    // With enum class, this is an error
    // if (d == m) // COMPILER ERROR: Cannot compare different enum class types
    // {
    //    // ...
    // }

    // --- Specified Underlying Type ---
    Status s = Status::Success;
    std::cout << "Status::Success as underlying char: " << static_cast<int>(s) << std::endl;

    // This is useful for interoperability or memory-constrained systems
    Status s_failure = static_cast<Status>(1);
    if (s_failure == Status::Failure) {
        std::cout << "Casting to enum class works with explicit cast." << std::endl;
    }
    
    return 0;
}

// STATIC_CAST<> VS ( ... )
// Which should you use?
// For modern C++ development, the static_cast is always the superior choice over the C-style cast. 
// The enhanced type-safety, clarity, and searchability lead to fewer bugs and more maintainable code. 

class Base {};
class Derived : public Base {};
class Unrelated {};

int main() {
    double value = 3.14;
    
    // --- Basic conversions (no practical difference) ---
    int a = static_cast<int>(value); // C++-style cast
    int b = (int)value;              // C-style cast
    std::cout << "static_cast result: " << a << std::endl;
    std::cout << "C-style cast result: " << b << std::endl;

    // --- Type-safety for pointer conversions ---
    char char_val = 'A';
    
    // static_cast will fail to compile because char* and int* are unrelated types
    // int* static_cast_ptr = static_cast<int*>(&char_val); // COMPILE-TIME ERROR
    
    // C-style cast will compile but results in undefined behavior
    // Writing to this pointer will corrupt memory because an int is 4 bytes
    // and the char variable only has 1 byte allocated.
    int* c_style_ptr = (int*)&char_val; 
    std::cout << "\nWarning: The next line may cause a crash or unpredictable output." << std::endl;
    std::cout << "C-style pointer cast result (Undefined Behavior): " << *c_style_ptr << std::endl;

    // --- Inheritance and unrelated types ---
    Derived* derived_ptr = new Derived;
    
    // Valid static_cast: upcasting to a base class
    Base* base_ptr = static_cast<Base*>(derived_ptr); 
    
    // Invalid static_cast: fails compilation for unrelated classes
    // Unrelated* unrelated_ptr = static_cast<Unrelated*>(derived_ptr); // COMPILE-TIME ERROR
    
    // C-style cast allows unsafe conversions to unrelated classes
    Unrelated* c_unrelated_ptr = (Unrelated*)(derived_ptr); 
    
    delete derived_ptr;
    return 0;
}
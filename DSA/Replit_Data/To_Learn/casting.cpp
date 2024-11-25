// Const Cast: Used to add or remove const qualifiers.

// cpp
// Copy code
// const int a = 10;
// int* b = const_cast<int*>(&a);
// This allows a (which is const) to be cast to a non-const integer pointer b.

// Dynamic Cast: Used for casting within a hierarchy of classes (downcasting).

// cpp
// Copy code
// class Base { virtual void foo() {} };
// class Derived : public Base {};

// Base* base_ptr = new Derived();
// Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
// This is used when you have polymorphic types (with virtual functions) and need to safely downcast pointers or references.

// Reinterpret Cast: Used for casting between unrelated types, such as converting a pointer to an integer.

// cpp
// Copy code
// int* a = new int(10);
// uintptr_t b = reinterpret_cast<uintptr_t>(a);
// This is a low-level cast and should be used with caution as it bypasses type checking.

// Example of Explicit Casting in Your Context
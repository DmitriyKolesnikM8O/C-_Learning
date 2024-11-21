// One Definition Rule (ODR)
// - in any translation unit a template, type, function or object can have no more than one definition
// - some of these can have any number of declarations
// - in the entire program, an object or non-inline function cannot have more than one definition
//
// 1. there might be name conflicts between different libraries
// 2. we need a way to organize larger libraries
//
// Namespaces:
// - can be used to avoid name collisions
// - organize libraries into distinct parts
//
// Example:
namespace my {
    class vector {...};
}

std::vector<int> v1;
my::vector v2;

//Multiple files
// - any number of files per namespace
// - any number of namespaces per file
//
// Example:
// vec.h
namespace my {
    class vector {...};
}
//set.h
namespace my {
    class set {...};
}
//main.cpp
#include "vec.h"
#include "set.h"

int main() {
    my::vector v;
    my::set v;
}

//Nested namespaces
//
//Example:
namespace std {
    namespace chrono {
        class system_clock {...};
    }
}

auto t1 = std::chrono::system_clock::now();

//Make one symbol usable without qualifier
namespace std {
    namespace chrono {
        class system_clock {...};
    }
}

using std::chrono::system_clock;

auto t1 = systen_clock::now();

//don`t use entire namespaces in header files -> namespace pollution

//Alias
namespace std {
    namespace chrono {
        class system_clock {...};
    }
}

namespace sc = std::chrono;

auto t1 = sc::system_clock.now();

//inline namespaces
inline namespace current {
    class A {...};
}

namespace old {
    class A {...};
}

mylib::A ac;
mylib::old::A ao;

//ADL
//unifies treatment of member and non-member functions
//member function call:
//object.fn()
//
//non-member function call:
//fn(object)

namespace lib1 {
    class A;
    void foo(A);
    void bar(int);
}

namespace lib2 {
    class A;
    void foo(A const&);
}

lib1::bar(5); //need qualified call - no ADL for an int

lib1::A a1;
lib2::A a2;

foo(a1); //no need to qualify - ADL selects lib1::foo
foo(a2); //no need to qualify - ADL secelst lib2::foo

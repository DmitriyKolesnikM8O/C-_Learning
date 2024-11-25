//Encapsulation
// - separate public interfaces from private implementation details
// - guarantee type invariants
//
//Inheritance (наследование)
// - base type with member functions as common interface
// - several derived types can inherit interface from base type
//
//Polymorphism
// - derived types may override inherited functions
// - calls to such functions throught references/pointers to the base type will be resoldev at runtime
//----------------------------------------------------------------------
//
// Encapsulation    
// public interface: drawing and manipulating
// implementation details: data representation
// invariant: we can`t change internal data
//
// Example:
class Circle {
public:
    void draw() const;
    void place(point const&);
    void rotate(point const&, degrees);
private: //internal representation
    double radius_;
    point center_;
};

//Inheritance
//
//Example:
class Shape {
public:
  void draw() const;
  void place(point const&);
  void rotate(point const&, degrees);
};

class Circle : public Shape {
...
};

class Rectangle : public Shape {
...
};

//Polymorphism
//
//Example:
void foo(Shape const& s) {
    s.rotate(point{0,0}, 90);
    s.draw();
}

Rectangle r;
foo(r);

Triangle t;
foo(t);

//Polymorphism is NOT the Default

//--------------------------------------------------------------------------
// Virtual Functions
//polymorphic type = class with at least one virtual function
class Base {
    ...
    virtual void print() const { cout << "Base\n"; }
};

class Derived : public Base {
    void print() const override { cout << "Derived\n"; }
};

void print(Base const& b) { b.print(); }

Derived d;
d.print(); //prints "Derived"

print(d); //prints "Derived"

Base& b = d;
b.print(); //print "Derived"

//override - optional, but recommended!
//compiler will check if we really override

class Base {
    ...
    void f(int i ) {...}
};

class Derived1 : public Base {
    ...
    void f(int i) override; //compiler ERROR, because f is NOT virtual
};

class Derived2 : public Base {
    void f(double i) const override; //compiler ERROR
};

//Base Class Destructor must be virtual
//or we might leak resources

class Base {
    ~Base() {}
    virtual void foo() {}
};

class Derived : public Base {
    void foo() override {}
    SomeType x_;
};

unique_ptr<Base> b = make_unique<Derived>();

b = nullptr; //only calls ~Base() -> x_ member leaks!

//Correct Example
class Base {
    virtual ~Base() = default;
    virtual void foo() {}
};

class Derived : public Base {
    void foo() override {}
    SomeType x_;
};

unique_ptr<Base> b = make_unique<Derived>();

b = nullptr; //calls ~Derived() -> x_ destroyed

//Abstract Types
class Shape {
    public:
        virtual ~shape() = default;
        virtual void draw() const = 0;
        virtual void place(point const&) = 0;
        virtual void rotate(point const&, degrees) = 0;
};

//absract type = class with at least one pure virtual function
//= 0; means pure(чистый) virtual
//instantiable classes must implement these functions
//derived classes that do not implement them are also abstract
//can`t make objects of abstract types!
class Shape {
    public:
        virtual ~shape() = default;
        virtual void draw() const = 0;
        virtual void place(point const&) = 0;
        virtual void rotate(point const&, degrees) = 0;
};

class Circle : public Shape {
    public:
        explicit Circle(double r, const point& str): r_{r}, ctr_{ctr} {}

        void draw() const override {...};
        void place(point const& p) override { ctr_ = p; }
        void rotate(point const&, degrees) override {}
   private:
        double r_;
        point ctr_;
};

//Calling Base Class (Super) Functions
class CircleWithHole : public Circle {
    public:
        CircleWithHole(double r, point const& ctr, Circle const& hole)
    :
        Circle(r, ctr), //call base constructor
        hole_{hole}
    {}

    void draw() override {
        Circle::draw(); //call base draw
        hole_.draw();
    }
};

//--------------------------------------------------------------------------
//Liskod Substitution Principle
// - inheritance should reflect an IS-A relationship (наследование должн оотражать отношение IS-A)
// - every Derived should be able to be used in place of a Base
// - beware: real-world or math relationships != type relationships (реальные или математические отношения != отношения типов)


//Final function & Classes
// - final functions are not overridable
// - final classes are nod derivable
class Base: {
    public:
        virtual void print() const;
};

class Type1 final : public Base { //can`t derive from Type1
    public:
        void print() const override;
}

class Type2 : public Base {
    public:
        void print() const override final; //can`t override print furhter
}

//Don`t use protected Data Members, because derived classes could break base class invariant(s)!

//Bad:
class Counter {
public:
  void increase()  { ++n_; }
  int get() const { return n_; }
protected:
  int n_;
};

class XYZ : public Conter {
    public:
        void scale(int s) {
            Base::n_ *= s;
            //n_ might be negative!
        }
};

//Good
class Counter {
public:
  void increase()  { ++n_; }
  int get() const { return n_; }

protected:
  void reset(int c) {
    if (c >= 0) n_c = c;
  }
private:
  int n_;
};

//Try Avoid Inheriting Data Members
//base class data:
// - might not be needed in derived classes -> waste of memory
// - might conflict with future derived classes -> broken interface
// -> data members should be seen as an implementation detail


//Non-Virtual Interface (NVI) idiom
// - virtual functions = derivation interface of a class
// - only derives classes may/need to override them
// - use public non-virtual member functions to call them
// - prefer pure virtual functions

class Base {
    public:
        virtual ~Base() = default;
        void log() const { do_log(); }
    private:
        virtual void do_log() const = 0;
};

class Derived : public Base {
    private:
        virtual bool do_log() const { //implementation }
};





















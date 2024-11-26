//Move On Assignment(назначение)
auto x = make_unique<int>(5); //x -> 5
unique_ptr<int> y; // x -> 5 nothing <-  y 
y = std::move(x); //x -> nothing 5 <- y

//lvalue - выражение, из которого мы можем взять адрес памяти
//rvalue - выражение, из которого мы не можем взять адрес памяти
int a = 1; //a and b are both lvalues
int b = 2;
a = b;
b = a;

a = (a * b); // (a * b) is an rvalue
int c = a * b; //ok
a * b = 3; //Compiler Error, we cannot assign 3 to rvalue

int i = 1; //ok, literals are rvalues
i  = 2;

int* pi = &i; //ok, we can take address of lvalue i
int& foo();
int bar();

i = bar(); //ok, result of bar is an rvalue
foo() = 3; //ok, result of foo is an lvalue reference

int* pf = &foo();
int* pb = &bar(); //compiler error, cannot take address of rvalue

//lvalue references
//T & - bind to non-constant lvalues of type T only
//T const & -bind to const lvalues and rvalues of type T

//rvalue references
//T && - bind(связать) to rvalues of type T only

void foo (T & x ); //modify x
void bar (T const & x); //just read from x
void baz(T && x); //might absorb(поглощать?) x

int i = 0;
foo(i); //ok
foo(move(i)); //ERROR: lvalue ref cannot bind to rvalue


bar(i); //ok
bar(move(i)); //ok

baz(i); //ERROR: rvalue ref cennont bind to lvalue
baz(move(i)); //ok


//everything that has name is an lvalue
//we must use std::move to cast source.root_ to an rvalue
//move constractors should be noexcept

//lvalue
int& inc(int&);

int i = 3 + 2;
int l = inc(i);

//xvalues
void g(T&&);
T&& h(T&&);

T a;
g(std::move(a));

T b = h( T{} );

//prvalues
BinaryTree f() {...}

auto t = f();

int i = 3 + 2;
int j = i + 5;
int k = i * j;

//move
using lines_t = std::vector<std::string>;
lines_t src {"X", "Y", "A", "B", "C", "D", "E", "F", "G"};
lines_t tgt;
tgt.resize(5);

move(begin(src) + 2, begin(src) + 7, begin(tgt)); // A B C D E





















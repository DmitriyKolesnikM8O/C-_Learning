//write a template once
//instantiate functions for different types
//parameter types are deduced from arguments

template<class T>
void swap(T& a, T& b) {
    auto temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

double d1, d2;
swap(d1, d2);

int d3, d4;
swap(d3, d4);
swap(&d3, &d4);

template<class T>
struct point {
    T x;
    T y;
};

point<double> p1 { 1.0 , 2.0 };
point<float> p2 { 1.0f, 2.0f };

template<class T>
class point {
public:
    point(T x, T y): x_{x}, y_{y} {}
};

point pi {1, 2}; //point <int>
point pd {1.0, 2.3}; //point<double>

//variable templates = generic constant

template<class T>
constexpr T pi = T(3.142543567);

auto rf = 0.254f;
auto af = pi<float> * rf * rf;

auto rl = 0.254l;
auto al = pi<long double> * rl * rl;

//шаблоны (template) в C++ похожи на дженерики в Go. Оба механизма позволяют писать обобщённый код, работающий с различными типами данных. Однако в C++ шаблоны компилируются, а в Go дженерики интерпретируются во время выполнения.

//Template Aliases
using NewType = OldType;

using DoubleVector = vector<double>;

template<class T>
using PairVector = vector<pair<T,T>>;













































//объекты, чьи типы предоставляют по крайне мере одну функцию перегрузки
class Multiplier {
    int m_;
public:
    //constructor
    explicit constexpr Multiplier (int m) noexcept : m_{m} {}
    //'call operator':
    constexpr int operator () (int x) const noexcept { return m_ * x; }
};

//can use it like a function
Multiplier triple{3};
int i = triple(2); //i = 6

//can be stateful
class Accumulator {
  int sum_ = 0;
public:
  void operator () (int x) noexcept { sum_ += x; }
  int total () const noexcept { return sum_; }
};

Accumulator acc;
acc(2);
acc(3);
int sum = acc.total(); //sum: 5

//example: interval query
class in_interval {
    int a_;
    int b_;
public:
    //constructor:
    explicit constexpr
    in_interval (int a, int b) noexcept: a_{a}, b_{b} {}

    //call operator:
    [[nodiscard]] constexpr
    bool operator() (int x) const noexcept {
        returb x >= a_ && x <= b_;
    }
};

in_interval test {-10, 5};

cout << test(1); //true
cout << test(5); //true
cout << test(12); //false


//стоит избегать stateful операторов, то есть когда текущее значение оператора зависит от прошлых его вызовов









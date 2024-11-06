#include <vector>
#include <iostream>
/*
В чем идея: обычные композитные типы данных, типо структур, не подходят для многих вещей.
Например, если даже мы просто хотим создать автоматический счетчик, который начинается с 0 и может только
инрементироваться, мы не можем это сделать с помощью структур. На помощь приходят классы.
*/


class monotous_counter {
    int count_; //<- data member

    void increment () { //<- member function
        ++count_;
    }
};


//доступ к приватным аргументам может быть предоставлен только из внутренних функций (member function)

class asceding_sequence {
    private:
        std::vector<int> seq_;

    public:
        void insert(int x) {
        
        }
        auto size() const { return seq_.size(); }
};

int main() {
    asceding_sequence s;
    //s.insert()  'insert' is public
    auto n = s.size(); //'size' is public
    
    std::cout << n << '\n';
    //auto i = s.seq_[0] - error, because seq_ is private
    //auto m = s.seq_.size() - compiler error
    //s.seq_.push_back() - compiler error
}


/*
Difference between struct and class:
    struct point {}; == class point {
                          public:
                        };


   class point {}; == struct point {
                         private:
                      };

structure обычно используются для простых совокупностей публичных данных
class обычно используется для приватных данных, функций-членов и инвариантов 

*/

class asceding_sequence {
    std::vector<int> seq_;
    public:
        void insert(int x) {
        
        }
        auto size() const { return seq_.size(); } // только const функции-члены могут быть использованы для const
                                                  // объектов 
};

int main() {
    asceding_sequence s;
    s.insert(88); //ok, because s not const
    
    auto const& sc = s;
    sc.insert(5); //compiler error, because 'insert' is not const
}

void foo (asceding_sequence const& s) {
    auto n = s.size() // ok, because 'size' is const
    s.insert(5) //compiler error, because 'insert' isn`t const
}


class monotous_counter {
    int count_;
    public:
        int reading () const {
            count_ += 2; //compiler error, because members are const inside const-qualified member functions
            return count_;
        }
}

//member functions can be overloads by const
//2 функции могут иметь одинаковое название и список аргументов, если одна из них будет const-modified, а другая нет
//это позволяет четко разграничить доступ только для чтения от чтения/запись
class interpolation {
    int t_;
    public:
        // setter / getter pair
        void threshold (int t) {if (t > 0) t_ = t;}
        int threshold () const {return t_;}

        // write access to a 'node'
        node& at (int x) {...}

        //read-only access to a 'node'
        node const& at (int x) const {...}
}

// Declaration Vs Definition


class MyType {
    int n_;
    // more data members …
    public:
    // declaration + inline definition
    int count () const { return n_; }

    // declaration only
    double foo (int, int);
};

//separate definition
double MyType::foo (int x, int y) {
    //много всего
}

//для сложных функций-членов их определение обычно выносится за пределы класса, нередко даже во отдельный файл
//но небольшие члены-функции можно реализовать прямо в классе, например, в формате inline, это повышает 
//производительность


// Operator Member functions
class X {
    Y operator [] (int i) { ... }
};

//X x;
//Y y = x[0];


class asceding_sequence {
    private:
        std::vector<int> seq_;
    public:
        void insert (int x) { ... }
        int operator [] (size_t index) const { return seq_[index]; }
};

int main() {
    asceding_sequence s; //s.seq_ = []
    s.insert(9); // s.seq_ = [9]
    s.insert(2); // s.seq_ = [2 9]
    s.insert(4); // s_seq_ = [2 4 9]
    std::cout << s[0] << '\n'; //prints '2'
    std::cout << s[1] << '\n'; //prints '4'
}

//Initializations:
//Member initializer: int count_ = 0;
//Constructor Initialization lists:
//Конструктор - специальная member_function, которая выполняется при создании объекта
//class counter {
//  int count_;
//  public:
//      counter(): count_{0} { }
//};
//
//class Foo {
//  int i_;
//  double x_;
//  public:
//      Foo(): i_{10}, x_{3.14} { }
//};
//Порядок элементов в списке инициализации всегда должен совпадать с порядком элементов в объявлении
//Иначе может возникнуть неопределенная ситуация, например, попытка доступа к неинициализированной памяти
//Некоторые компиляторы с включенными предупреждениями могут об этом подсказывать: -Wall или -Wreorder

//Подробнее про конструкторы:
//- Имя конструктора = имени типа
//- не имеет возвращаемого типа
//- можно инициализировать элементы данных через список инициализации
//- может выполнить код еще до первого использования объекта
//- может быть использован для установления инвариантов
//(Инвариант - свойство, которое должно сохраняться во время выполнения программы, условие, которое всегда 
//истинно. Это заявление о том, что определенные условия или свойства объекта, класса или чего-то еще, будут сохранены во всех состояниях программы
//Пример: есть сортировка пузырьком. Инвариант - на каждой итерации сравниваются именно 2 соседних элемента. Это
//гарантия корректности в принципе всей сортировки)
//- по умолчанию (default) не принимает параметров

class Samples {
    int min_;
    int max_;
    std::vector v_;

    public:
        //default constuctor
        Samples (): min_{0}, max_{1}, v_{min_, max_} {v.reverse(8); }

        explicit //special constructor
        Samples (int x): min_{x}, max_{x}, v_{x} {v.reverse(8); }

        int add (int i) {
            if (i < min_) min_ = i;
            else if (i > max_) max_ = i;
            v.push_back(i);
        }

        int min () const { return min_; }
        int max () const {return max_; }
};

Samples s1; //default -> s1.v_ = {0 1}, min_ = 0, max_ = 1
Samples s2 {3}; //special -> s2.v_ = {3}, min_ = 3, max_ = 3

//Also can use separate definition for constructor, works as other member-function

class MyType {
    public:
        MyType(); //Declaration
};

MyType::MyType (): ... { ... } //Definition
//также нужно контролировать, что порядок элементов в списках инициализации совпадает с порядков их объявлений

//если нет определяемого пользователем конструктора, то компилятор просто сгенерирует его самостоятельно

class BoringType { public: int i = 0; };

BoringType obj1; //correct
BoringType obg2 {}; //correct

//если есть хотя бы один специальный конструктор, компилятор не будет генерировать дефолтный конструктор сам

class SomeType {
    public:
        explicit SomeType (int x) ... { ... };
};

SomeType s1 {1}; //correct
SomeType s2; // compiler error, because no default constructor
SomeType s3 {}; //compiler error, because no default constructor

//TypeName() = default - компилятор создаст реализацию дефолтного конструктора

class MyType {
    public:
        MyType() = default;
        explicit MyType (int x) ... { ... };
};


MyType m1; //correct
MyType m1 {}; //correct
MyType m1 {3}; //correct

//Если мы используем default, обязательно нужно инициализировать данные с помощью member initializers

//мы можем вызывать конструкторы инициализации внутри других конструкторов инцициализации
class Range {
    int a_;
    int b_;
    public:
        explicit Range (int a, int b): a_{a}, b_{b} { if (b_ > a_) std::swap(a_, b_); }
        
        //delegates to [a, b] ctor
        explicit Range(int a): Range(a, a) {}
        //default constructor - delegates to Range [a, a] ctor
        Range (): Range{0} {}
};

Range r1; // r1.a_ = 0, r1.b_ = 0
Range r2 {3}; // r2.a_ = 3, r2.b_ = 3
Range r3 {2, 6}; // r3.a_ = 2, r3.b_ = 6

//Types of interfaces


#include <cstdint>
#include <numeric_limits>

class monotonous_counter {
    public:
        //public type alias
        using value_type = std::uint64_t;
    private:
        value_type count_ = 0;
    public:
        value_type reading () const { return count_; }
};

const auto max = std::numeric_limits<monotonous_counter::value_type>::max();
//- делать псевдонимы типов публичными только в том случае, если они используются в публичном интерфейсе класса, то
//есть используются в качестве возвращаемых типов или параметров функций-членов
//- не делать псевдонимы типов публичными, если они используются исключительно в закрытых функциях-членах или для закрытов членов-данных


// как реализовывать фичу, добавлять новый функционал:
// - если нужен доступ только к публичным данным (например, функции-члены), то реализовать, как отдельную функцию
// - если нужен доступ к приватным данным, то реализовать, как member-function

class gap {
  int a_; 
  int b_;
public:
  explicit gap (int a, int b): a_{a}, b_{b} {}
  int a () const { return a_; }
  int b () const { return b_; }
};

//как реализовать функцию, которая делает новый gap объект, обе границы которого смещены на одинаковую величину

//реализация зависит только от публичного интерфейса
//сам тип gap не изменяется
gap shifted (gap const& g, int x) {
    return gap{g.a() + x, g.b() + x};
}

//bad practice
class gap { 
  …
  gap shifted (int x) const {
    return gap{a_+x, b_+x};
  }
};
//другие пользователи могут захотеть использовать shift с другой семантикой, но теперь не смогут это делать
//весь остальной код, который зависит от пробела, нужно будет перекомпилировать

//избегать пар setter/getter
// - использовать функции действия вместо просто setter
// - более детальный контроль
// - лучше моделируют проблемы
// - лучшая читаемость кода

//Good practice
class Account { …
  void deposit (Money const&);
  Money try_withdraw (Money const&);
  Money const& balance () const;
};

//Bad practice
class Account { …
  void set_balance (Money const&);
 
  Money const& balance () const;
};

//не использовать начальные подчеркивания или подчеркивания в именах типов, переменных, функций и так далее
// Вместо: _member         Использовать: m_ember          
//         member__                       member_
//         m__ember


//Example 1: monotonous counter:
//new counters start at 0
//can only count up, not down
//read-only access to current count value

#include <iostream>
#include <sctdint>

class monotonous_counter {
    public:
        using value_type = std::uint64_t;
    private:
        value_type counter_ = 0;
    public:
        monotonous_counter ()=default;
        explicit monotonous_counter (value_type init) noexcept: counter_{init} {}
        void increment () noexcept {counter_++;}
        [[nodiscard]] value_type reading () noexcept {return counter_;}

};

//noexcept - ключевое слово, показывающее, что функция не выбрасывает исключений. Это позволяет компилятору провест
//ряд оптимизаций, так как нет нужды генерировать дополнительный код для обработки.
//если же исключение все же выбрасывается, программа завершается с ошибкой сразу же. В обычных же функциях
//программист может обработать исключения, например, с помощью блоков try catch


//Example 2: asceding sequence (восходящая последовательность)
//- храним целые числа
//- доступ только для чтения к сохраненным элементам по индексу
//- можем только добавлять новые элементы, но не удалять их
//- элементы всегда отсортированы по возрастанию
//- содержимое можно изменять только через публичный интерфейс
//

#include <vector>
#include <algorithm>

class asceding_sequence {
    public:
        using value_type = int;
    private:
        using storage_t = std::vector<value_type>;
        storage_t seq_;
    public:
        using size_type = storage_t::size_type;

        void insert (value_type x) {
            //use binary search to find insert position
            seq_.insert(std::lower_bound(seq_.begin(), seq_,end(), x), x);
        }
        [[nodiscard]] value_type operator [] (size_type idx) const noexcept {return seq_[idx];}

        [[nodiscard]] size_type size () const noexcept {return seq_.size();}

        //enable range bages iteration
        [[nodiscard]] auto begin() const noexcept {return seq_.begin();}
        [[nodiscard]] auto end() const noexcept {return seq_.end();}
};


int main () {
  ascending_sequence s;  // s.seq_:
  s.insert(7);           // s.seq_: 7
  s.insert(2);           // s.seq_: 27
  s.insert(4);           // s.seq_: 247
  s.insert(9);           // s.seq_: 2479
  s.insert(5);           // s.seq_: 24579
  std::cout << s[3];     // prints 7
  for (auto x : s) {
    std::cout << x <<' ';  // 2 4 5 7 9
  }
  // use type aliases
  ascending_sequence::value_type x = 1;
  ascending_sequence::size_type  n = 2;
}













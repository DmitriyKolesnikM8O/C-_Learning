//Exception - объект, который можно пробрасывать вверх по иерархии вызовов
// - пробрасывание возвращает управление обратно вызывающей стороне текущей функции
// - исключения можно обработать с помощью try ... catch блоков
// - если не обрабатывать, то исключения достигнут main
// - если и в main не будут обработаны: вызовется std::terminate
// - обычное поведение std::terminate: прервать программу

void bar() {
    ...
    throw error{}; // go back to caller
    ...
}

void foo() {
    ...
    bar();  // not handler -> go back to caller
    ...
}

int main() {
    ...
    foo(); // not handler -> terminate program
    ...
}

//Оригинальная мотивация для исключений: сообщенить об ошибки конструктора при инициализации объекта, то есть об ошибке при установлении требуемых инвариантов класса
//Example 1:

#include <stdexcept> //standart exception types

class Fraction {
    int numer_;
    int denom_;
public:
    explicit constexpr
    Fraction (int numerator, int denominator):
        numer_{numerator}, denom_{denominator}
    {
        if (denom_ == 0) {
            throw std::invalid_argument{"Denominator can`t be a zero value"};
        }
    }
    ...
};

int main() {
    try {
        int d = 1;
        std::cin >> d;
        Fraction f {1, d};
    }
    catch (std::invalid_argument const& e) {
        //deal with / report error here
        std::cerr << "error" << e.what() << '\n';
    }
}

//Также можно использовать для сообщений о нарушении условий контракта
//1. Нарушение предварительных условий
// - Предварительные условия: ожидание относительно input, то есть валидных аргументов
// - Примеры нарушений: отрицательное число для квадратного корня, выход за пределы контейнеры
// - "Wide contract" функции выполняют предварительные проверки прежде чем использовать входные значения
//Такой тип обычно не используется в коде, где критически важна производительность и известно, что данные точно
//будут валидными
//
//2. Неспособность установить или сохранить инварианты
// - public member function не может установить допустимые значения членов
// - Пример: нехватка памяти во время роста вектора
//
//3. Нарушение постусловий
// - Постусловие: ожидание относительно output, то есть возвращаемых значений
// - Нарушение: функция не может вернуть допустимое значение или повреждает глобальное состояние
// - Примеры: ошибка конструктора, нельзя вернуть значение или деление на 0
//
// Советы по Exceptions:
// - разделение кода обработки ошибок от бизнес-логики
// - централизация обработки ошибок (выше по цепочке вызовов)
// - в настоящее время незначительное влияние на производительность, когда не выбрасывается исключение
// - но, как правило, при возникновении исключения производительность снижается
// - влияние на производительность из-за дополнительных проверок достоверности
// - легко создать утечки ресурсов/памяти (подробнее ниже)
//
//Альтернатива исключениям:
//1. Для некорректных входных значений:
// - перед передачей значений убеждаться в том, что они валидны
// - использовать типы параметров, которые исключают некорректные значения
// - это лучше сегодня для производительности программы
//
//2. Ошибка установки или сохранения инвариантов
// - состояния ошибок или флагов
// - установить объект в специальное недопустимое значение
//
//3. При невозможности корректного вывода
// - вернуть код ошибки через отдельный выходной параметр
// - вернуть специальное недопустимое значение
// - использовать специальный тип словаря, который может содержать либо допустимый вариант, либо ничего, например,
// std::optional
//
// Все стандартные типы исключений являются подтипами std::exception
// std::exception
//  ↑ logic_error
//  |  ↑ invalid_argument
//  |  ↑ domain_error
//  |  ↑ length_error
//  |  ↑ out_of_range
//  |  …
//  ↑ runtime_error
//    ↑ range_error
//    ↑ overflow_error
//    ↑ underflow_error
//    …
//

try {
  throw std::domain_error{
    "Error Text"};
}
catch (std::invalid_argument const& e) {
  // handle only 'invalid_argument'
  …
}
// catches all other std exceptions
catch (std::exception const& e) {
  std::cout << e.what()
  // prints "Error Text"
}


//Некоторые стандартные библиотечные контейнеры предлагают широкие функции контракта, которые сообщают о недопустимых входных значениях, выдавая исключения:
std::vector<int> v {0,1,2,3,4};
// narrow(узкий) contract: no checks, max performance
int a = v[6];     //  UNDEFINED BEHAVIOR
// wide contract: checks if out of bounds
int b = v.at(6);  // throws std::out_of_range

//Обработка
//Re-Throwing:
try {   
   // potentially throwing code
} 
catch (std::exception const&) {  
  throw;  // re-throw exception(s)
}

//Catching all Exceptions:
try {                              
  // potentially throwing code
} 
catch (...) {  
  // handle failure
}

//Необходимо централизировать обработку исключений
//Стоит избегать дубликоватов кода когда одинаковые ошибки пробрасываются в разных местах кода
//Полезно конвертировать исключения в коды ошибок

void handle_init_errors () {
    try { throw: //re-throw! }
    catch (err:device_unreachable const& e) { ... }
    catch (err:bad_connection const& e) { ... }
    catch (err:bad_protocol const& e) { ... }
}

void init_server {
    try {
        ...
    } catch (...) {handle_init_errors(); }
}

void init_client {
    try {
        ...
    } catch (...) {handle_init_errors(); }
}

//Почти любой кусок кода может вызывать исключения
//Потенциальная учетка ресурсов или памяти, если используется вместе с:
// - внешними библиотеками С, которые выполняют собственное управление памятью
// - библиотеками, которые не используют RAII для автоматического управления ресурсами
// - типами, которые не очищают свои ресурсы в деструкторе
//
// Example: Leak due (обусловлена) C-style обработки ресурсов
void add_to_database (database const& db, str::string_view filename) {
    DBHandle h = open_database_connection(db);

    auto f = open_file(filename);
    // if open_file throws -> connection not closed!
    ...

    close_database_connection(h);
    // not reached (не достигнуто), if 'open_file' throws
} 

//Можно использовать RAII для предотвращения утечек
class DBConnector {
  DBHandle handle_;
public:
  explicit
  DBConnector (Database& db): 
    handle_{make_database_connection(db)} {}
  ~DBConnector () { close_database_connection(handle_); }
  // make connector non-copyable:
  DBConnector (DBConnector const&) = delete;
  DBConnector& operator = (DBConnector const&) = delete;
};

void add_to_database (database const& db, std::string_view filename) {
  DBConnector(db);
  auto f = open_file(filename);
  // if 'open_file' throws ⇒ connection closed!
  // do work normally…
} // connection closed!


//В деструкторах не стоит позволять исключениям исчезать
class E {
public:
  ~E () { 
    // throwing code ⇒ BAD!
  }  
  …
};
class A {
  // some members:
  G g;  F f;  E e;  D d;  C c;  B b;
  …
};
//Здесь если будет проблема с уничтожением e, то получится, что b c d уже уничтожены, e выкинет исключение и f g
//просто не будут уничтожены
//поэтому лучше делать это так:
class MyType {
public:
  ~MyType () { …
    try {
      // y throwing code…
    } catch ( /* … */ ) {
      // handle exceptions…
    } …
  }
};


//Гарантии исключений
//1. Нет гарантий
//Если в документации к коду не сказано противное, то стоит предполагать, что может быть:
// - операция может быть fail
// - ресурсы могут утечь
// - может произойти ошибка с установлением инвариантов (элементы могут содержать недопустимые значения)
// - частичное выполнение неудачных операций может вызывать побочные эффекты
// - исключения могут распространяться наружу
//
//2. Базовые гарантии (К этому минимуму стоит стремиться)
// - инварианты сохраняются, утечки ресурсов не происходит
// - все элементы будут содержать допустимые значения
// - частичное выполнение неудачных операций может вызывать побочные эффекты
//
//3. Сильные гарантии (предпочтительно для высокопроизводительного кода)
// - операции гарантированно проходят
// - исключения не наблюдаются извне, либо перехватываются
// - задокументировано с помощью noexcept ключевого слова
//
// С noexcept нужно быть осторожным, ставить осмысленно. Изменение функции с noexcept на обычную может приводить
// к поломкам кода, где ожидается, что исключения не будет
constexpr int N = 5;
// 'foo' is noexcept if N < 9
void foo () noexcept( N < 9 ) { … }    
// 'bar' is noexcept if foo is
void bar () noexcept( noexcept(foo()) ) {  
    …
    foo();
    …
}






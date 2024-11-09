// Warnings - messages from compiler, hinting at potentially problematic runtime
// Assertions(Утверждения) - операторы сравнения и представления ожидаемых и фактических аргументов выражения
// Testings - сравнение актуального и ожидаемого поведения частей или всей программы
// Code Coverage - какой объем кода фактически тестируется
// Static Analysis - поиск потенциальных проблем, например, утечка памяти, во время запуска программы
// Debugging - пошагово выполнять код во время выполнения, проверять значения в памяти
// Profiling - выяснить, какой вклад каждая функция/цикл/блоквносит в общее время выполнения, потребление памяти
// Micro Benchmarking - небольшие тесты, измеряющие отдельные функции, а не всю программу
// 
// Compiler Error - program not compilable
// Compiler Warnings - program compilable, but there is a problematic piece of code that might lead to runtime bugs
//
// gcc/clang Options:
// -Wall - recommended. Всегда следует использовать хотя бы это. Это не включает все предупреждения, а только самые
// важные, которые не производят слишком много ложных срабатываний.
// -Wextra - recommended. Включить еще больше предупреждений, чем -Wall.
// -Wpedantic - recommended. Выдавать все предупреждения, требуемые строгим ISO C++; отклонять расширения,
//  специфичные для компилятора.
// -Wshadow - recommended. Выдавать предупреждения, если переменные или объявления типов затеняют друг друга.
// -Werror - Рассматривать все предупреждения как ошибки ⇒ любое предупреждение прервет компиляцию.
// -fsanitize=undefined,address - Enables Undefined Behavior Sanitizer and Address Sanitizer
// (more on that in the following chapters)
//
// Example:
// High performance: -Wdisabled-optimization -Wpadded -Wsign-conversion -Wsign-promo -Wstrict-aliasing=2 -Wstrict-overflow=5 -Wunused -Wunused-parameter
//
// Recommended Set: -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -fsanitize=undefined,address -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch -Wlogical-op -Wmissing-declarations -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wnested-externs -Wpacked -Wpointer-arith -Wredundant-decls -Wstack-protector -Wstrict-null-sentinel -Wswitch-enum -Wundef -Wwrite-strings

//Assertions
//
//Runtime Assertions
#include <cassert>

assert(bool_expression);
//if expression = false - abort the program
//Use cases:
//check expected values/conditions at runtime
//verify input values
//verify invariants (states, results)
//verify output/return
//
//Should be deactivated on realease to avoid performance impact!
#include <cassert>

double sqrt (double x) {
    assert (x >= 0);
    ..
}

double r = sqrt(-2.4); //assertion 'x >= 0' failed - aborted


//assert - preprocessor macro, so commas would otherwise be interpreted as macro argument separator
//Example:
//assert ( min(1, 2) == 1  ) - ERROR
//assert ((min(1, 2) == 1)) - OK

//can be added with a custom macro:
#define assertmsg(expr, mas) assert(((void)msg, expr))
assertmsg(1+2==2, "1 plus 1 must be 2");

//Static assertions
static_assert(bool_constexpr);
//if expression - false -> abort compilation

using index_t = int;
index_t constexpr DIMS = 1;  // oops

void foo () { 
  static_assert(DIMS > 1, "DIMS must be at least 2");
  …
}

index_t bar (…) {
  static_assert(
    std::numeric_limits<index_t>::is_integer &&
    std::numeric_limits<index_t>::is_signed, 
    "index type must be a signed integer");
  …
}
//static_assert(DIMS > 1, "DIMS must be at least 2");

//Testing
//
//Use Assertions:
//для проверки ожиданий/предположений, которые еще не выражены/не гарантированы типами:
//- ожидаемые значения, доступные только во время выполнения
//- input
//- invariants
//- output
//
//Write Tests:
//как только будет определено основное назначение и интерфейс функции или типа.
//- более быстрая разработка: меньше необходимости в длительных сеансах регистрации и отладки
//- более простая настройка производительности: можно постоянно проверять, все ли еще правильно
//- документация: ожидания/предположения записаны в коде
//
//Use A Testing Framework
//Более удобно и менее подвержено ошибкам: предопределенные проверки, средства настройки, средство запуска тестов
// и т. д.
//
//For Beginners or Small Projects: doctest
// - compact and self-documenting style
// - easy setup: only include a singer header
// - very fast compilation
//
//Larger Projects: Catch 2
// - same philosophy as doctest
// - value generations for performing same test with different values
// - micro benchmaring with timer, averaging, etc.
// - slowe to compiler adn slighty more complicated to set up than doctest


// doctest - Simple Test Case

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int factorial (int n) {
    if (n <= 1) return n;
    return factorial (n - 1) * n;
}

TEST_CASE("testing factorial") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
}
//Fails, because the implementation of factorial doesn`t handler the case of n = 0 properly
// test.cpp(7) FAILED!
// CHECK( factorial(0) == 1 )
// with expansion:
// CHECK( 0 == 1 )

//doctest - Subcases
TEST_CASE("vectors can be sized and resized") {
    std::vector<int> v(5);
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);
    SUBCASE("push_back increases the size") {
        v.push_back(1);
        CHECK(v.size() == 6);
        CHECK(v.capacity() >= 6);
    }
    SUBCASE("reserve increases the capacity") {
        v.reserve(6);
        CHECK(v.size() == 5);
        CHECK(v.capacity() >= 6);
    }
}
//для каждого SUBCASE TEST_CASE выполняется с самого начала
//с помощью REQUIRE на верхнем уровне мы обеспечиваем соблюдение требований для каждого SUBCAE по поводу емкости
//и размера
//If CHECK fails: test is marked as fails, but execution continues
//If REQUIRE fails: execution stops
//
//Нельзя использовать прямые потоки: cin/cout/cerr, это затрудняет тестирование
//Вместо этого нужно передавать потоки по ссылке:
struct State { std::string msg; … };

void log (std::ostream& os, State const& s) { os << s.msg; }

TEST_CASE("State Log") {
  State s {"expected"};
  std::ostringstream oss;
  log(oss, s);
  CHECK(oss.str() == "expected");
}

//Example:
class Logger {
  std::ostream* os_;
  int count_;
public:
  explicit
  Logger (std::ostream* os): os_{os}, count_{0} {}
  …
  bool add (std::string_view msg) {
    if (!os_) return false;
    *os_ << count_ <<": "<< msg << '\n';
    ++count_;
    return true;
  }
};

TEST_CASE("Logging") {
  std::ostringstream oss;
  Logger log {&oss};
  log.add("message");
  CHECK(oss.str() == "0: message\n");
}
















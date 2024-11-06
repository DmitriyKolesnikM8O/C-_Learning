#include <cmath>
#include <iostream>

//alias
using real = double_t;

/*
 constexpr в C++ - это ключевое слово, которое указывает компилятору, что выражение может быть вычислено 
 во время компиляции. Это означает, что результат выражения известен еще до запуска программы.
 Функции, объявленные с помощью constexpr, должны быть вычислимыми во время компиляции.
 Они могут использоваться для вычисления константных значений, таких как размер массива или значение константы.
 Переменные, объявленные с помощью constexpr, должны быть инициализированы константным выражением.
 Значение constexpr переменной вычисляется во время компиляции и доступно во всей программе.
*/

constexpr int cxf (int i) { return i * 2; }

constexpr int size (int i) {
    return i * i; 
}

int factorial (int n) {
    if (n < 2) return n;
    
    return (n * factorial(n - 1));
}

/*
Ключевое слово noexcept в сигнатуре функции в C++ означает, что функция гарантированно не выбросит исключение.
Гарантия: Компилятор использует эту информацию, чтобы оптимизировать код. Если функция помечена как noexcept, 
компилятор может: Удалить код обработки исключений для этой функции. Выполнять оптимизации, которые невозможны 
в случае возможного исключения.
Если функция помечена как noexcept, но она все же выбрасывает исключение, то программа будет прервана с ошибкой
std::terminate()
*/

int add(int a, int b) noexcept {
    return a + b;
}

int main()
{
    real valuable = 5.4;
    std::cout << valuable << '\n';

    constexpr int i = 2;

    constexpr int l = cxf( i );

    constexpr int g = cxf( 2 );

    std::cout << i << ' ' << l << ' ' << g;


    constexpr int figure = size( 5 );
    std::cout << '\n' << figure;

    std::cout << '\n' << factorial(23) << ' ' << add(3, 5);
}

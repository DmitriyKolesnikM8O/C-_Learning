//Стандартные алгоритмы:
// - построение блоков
// - работа с диапазонами элементов
// - реализация самостоятельных функций
// - реализация вне зависимоси от контейнера
// - кастомизация с лямбдами или функциями
// - эффективность

//return the smallest element and thereby both its position and value
#include <vector>
#include <algorithm> //std::min_element

std::vector<int> v {7 9 3 5 3 2 4 1 8 0};
auto i = min_element(v.begin() + 2, v.begin() + 7);
auto min = *i; //2

//Немодифицирующие запросы:
// - поиск элементов
// - минимум или максимум
// - сравнение диапазонов элементов
// - бинарный поиск
//Модифицирующие запросы:
// - копирование, перемещение
// - замена
// - удаление
// - объединение или пересечение отсортированных диапазонов

//Many standarts algorithms can be customized by passing a "callable entity" like a function lambda or custom function object as parameter
min_element(@begin, @end, compare(O, O) -> bool)

struct P { int q; char c; };
std::vector<P> v { {2, 'c'}, {1, 'b'}, {3, 'a'} };

bool less_q (P const& x, P const& y) {
    return x.q < y.q;
}

auto i = min_elemen(begin(v), end(v), less_q);
auto q1 = i->q; // 1
auto q2 = i->c; // 'b'              

//Большинство стандартных алгоритмов могут выполняться параллельно. Для этого в начале нужно добавить специальный параметр
#include <execution>

sort(std::execution::par, begin(v), end(v));

//Execution Policy:
// - seq - распараллеливание и векторизация не допускаются
// - unseq - допускается векторизация
// - par - допускается распараллеливание
// - par_unseq - можно все

//Category - set of supported iterator / range object operations & gearanteees
// - sentinel - обычно используется только для обозначения конца диапазона supports '==' '!='
// - input - доступ на чтение объектов, переход на следующую позицию supports '*' '++' '==' '!='
// - output - доступ на запись объектов, переход на следующую позицию supports '*' '++' '==' '!='
// - forward - доступ на чтение и на запись, прямой обход без произвольного доступа supports '*' '++' '==' '!='
// - BiDirectional - многопроходная гарантия, путешествие в обе стороны, но без случайного доступа '*' '++' '--' '==' '!='
// - RandomAccess - рандомный доступ, но необязательно к непрерывному блоку памяти all operators
// - Contiguous - рандомный доступ к непрерывному блоку памяти

//Error messages
//может быть довольно запутанным, всегда стоит ориентироваться на error в output









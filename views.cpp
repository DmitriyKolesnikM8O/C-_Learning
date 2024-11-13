//объект считается владельцем ресурса (памяти, файлового дескриптора, соединения), если он отвечает за его жизненный цикл (инициализация, уничтожение).
#include <string_view>
// - легковесный
// - не отвечает за выделение или удаление памяти
// - только для чтения
// - основной вариант использования, параметры функции только для чтения

//когда нужно избежать необязательного выделения памяти:
//проблема традиционного std::string const&:
//- std::string может быть сконструкирован из строковых литераторов или диапазона итератора в последовательность символов
//- если передать объект в качестве аргумента функции, который не является строкой, но является чем-то, что мы можем использовать для построения строки, например, литерал строковый, то будет выделен временный строковый объект и привязан к константной ссылке.
//string_view приходит здесь на помощь
void f_cref (std::string const& s) {...}
void f_view (std::string_view s) {...}

int main() {
    std::string stdStr = "Standart String";
    auto const cStr = "C-string";
    std::vector<int> v {'c', 'h', 'a', 'r', 's', '\0'};

    f_cref(stdStr); //no copy
    f_cref(cStr); //copy!
    f_cref({begin(v), end(v)}); //copy!

    f_view(stdStr); // no copy
    f_view(cStr); //no copy
    f_view({v.begin(), v.end()}); //no copy
}

//Выбор параметров-строк для функций:
// - если нужно всегда копировать строк внутри функции: std::string
// - если нужен доступ только для чтения без копирования (C++ 17/20): std::string_view
// - если нужен доступ только для чтения без копирования (C++ 11/14): std::string const&
// - если нужно изменить входную строку: string &

//making string_views
//1 with constructor calls
std::string s = "Some String";
std::string_view s_v { s };
//2 with special literal ""sv
using namespace std::string_view_literals;
autho literal_view = "C-string"sv;
//Лучше всего использовать string_view только для параметров функций

//std::span
// - легковесный
// - не отвечает за выделение или удаление памяти
// - непрерывный блок памяти, std::array...
// - чаще всего как параметр для функции
span<int> //sequence of integers whose values can be changed
span<int const> //sequence of integers whose values can`t be changed
span<int, 5> //sequence of exactly 5 integers                

vector<int> w { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
span<int> s { w.begin() + 2, 5 } // 2 3 4 5 6

//Лучше всего использовать как параметр для функции
void print_ints (std::span<int const> s);
void modify_ints (std::span<int> s);
void print_chars (std::span<char const> s);

std::array<int, 3> a {1, 2, 3};
print_ints(a);
std::string s = "Some string";
print_chars(s);




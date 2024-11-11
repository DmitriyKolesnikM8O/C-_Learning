//объекты, указывающие на местоположение
//могут указывать на читаемый адрес памяти или объект
//используется для итерации по элементам контейнера вне зависимости от 
//их компоновки

//итератор ссылается на позицию в контейнере
#include <vector.h>

// 1  2  3  4  5  6  7 
// i                   e
std::vector<int> v {1, 2, 3, 4, 5, 6, 7};
auto i = begin(v);
auto e = end(v);

std::cout << *i; // 1
std::cout << *(i + 2); // 3
std::cout << *e; //undefined behavior
                 //потому что end нельзя использовать для доступа к
                 //элементу, только как индикатор позиции

//Reverse Iterators
//  1  2  3  4  5  6  7
//e                   i
auto i_r = rbegin(v); // last element
auto e_r = rend(v); // one before first element
std::cout << *i; // 7
std::cout << *e; //undefined behavior


//циклы на основе итераторов
// - работает для всех стандартных контейнеров
// - возможны ошибки выхода за границы массива
// - многословны
std::vector<int> v {1, 2, 3, 4, 5, 6};
for (auto i = begin(v); i != end(v); ++i) {
   std::cout << *i;
} 
std::vector<int> v {1, 2, 3, 4, 5, 6};
for (auto i = rbegin(v); i != rend(v); ++i) { std::cout << *i; }

std::vector<int> v {1,2,3,4,5,6,7,8,9};  
v.erase(begin(v)+3, begin(v)+6); // 1 2 3 7 8 9



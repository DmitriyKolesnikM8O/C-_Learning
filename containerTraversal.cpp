//писать циклы стоит только в том случае, если нет хорошо протестированной библиотечной функции для того, что я хочу сделать
//
//Range-Based Loop
std::vector<Type> v {...};

//read-only, type cheap to copy
for (Type x : v) { ... }
for (auto x : v) { ... }
//read-only,type expensive to copy
for (Type const& x : v) { ... }
for (auto const& x : v) { ... }
//modify values
for (Type& x : v) { ... }
for (auto& x : v) { ... }

//for_each
//rangex::for_each(range, f(0)) -> применяем f к каждому элементу штуки, по которой проходим range
// read-only, type cheap to copy or copy needed:
ranges::for_each(v, [](Type x){ cout << x; }); 
ranges::for_each(v, [](auto x){ cout << x; });
// read-only, type expensive to copy:
ranges::for_each(v, [](Type const& x){ cout << x; });
ranges::for_each(v, [](auto const& x){ cout << x; });
// modify values:
ranges::for_each(v, [](Type& x){ cin >> x; });
ranges::for_each(v, [](auto& x){ cin >> x; });

#include <algorithm>  // std::for_each
Container<Type> v; …
// read-only, type cheap to copy or copy needed:
for_each(begin(v), end(v),       [](Type x){ cout << x; });
for_each(begin(v)+2, begin(v)+5, [](auto x){ cout << x; });
// read-only, type expensive to copy:
for_each(begin(v), end(v), [](Type const& x){ cout << x; });
for_each(begin(v), end(v), [](auto const& x){ cout << x; });
// modify values:
for_each(begin(v), end(v), [](Type& x){ cin >> x; });
for_each(begin(v), end(v), [](auto& x){ cin >> x; });

//явное использование итераторов
std::vector<int> v {1, 2, 3, 4, 5, 6};
for (auto i = begin(v); i != end(v); ++i) { cout << *i; }
for (auto i = begin(v); i != end(v); ++i) { cin  >> *i; }
// read-only - using const iterators
for (auto i = cbegin(v); i != cend(v); ++i { cout << *i; }

















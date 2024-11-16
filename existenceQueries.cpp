// any_of/all_of/none_of

std::vector<int> v {0, 1, 2, 3, 4, 5, 6, 7};
auto const check = [](int x) { return x >= 1; };
cout << all_of(begin(v) + 1, begin(v) + 7, check); //true
cout << any_of(begin(v) + 1, begin(v) + 7, check); //true
cout << none_of(begin(v) + 1, begin(v) + 7, check); //false

cout << all_of (begin(v), end(v), check);  // false
cout << any_of (begin(v), end(v), check);  // true
cout << none_of(begin(v), end(v), check);  // false

cout << std::ranges::all_of (v, check);  // false
cout << std::ranges::any_of (v, check);  // true
cout << std::ranges::none_of(v, check);  // false

//count
std::vector<int> v {5,2,9,1,3,2,5,2,2,9};
auto n = count(begin(v) + 1, begin(v) + 8) // n = 3

cout << std::ranges::count(v, 3);  // 1
cout << std::ranges::count(v, 2);  // 3
cout << std::ranges::count(v, 7);  // 0

//count_if
std::vector<int> v {5,4,9,1,3,2,5,6,8,9};

auto const is_even = [](int x) { return x % 2 == 0; };
auto n = count_if (begin(v), begin(v), is_even); // n = 4

//finding elements

//find
#include <vector>
#include <algorithm>
std::vector<int> v {9,0,4,1,8,3,8,2,9};

auto i = find(begin(v)+2, begin(v)+7, 8);
if (i != begin(v)+7) {
    ... //true -> found
}
auto j = find(begin(v), end(v), 9);
if (j != end(v)) { //true  -> found
    auto const value = *j;
    auto const index = distance(begin(v), j);
}
//find_if
std::vector<int> v {4,1,8,3,7};
auto const f = [](int x) { return x >= 6; };
auto i = std::ranges::find_if (v, f);  
if (i != end(v)) {   // true ⇒ found
  auto const value = *i;  // int value = 8
  auto const index = distance(begin(v), i);  // index = 2
}

//comparing ranges
std::vector<int> r1 {0,1,2,3,4,5,6,7,8,9};
std::vector<int> r2 {1,2,3,4,5,6,0,0};

cout << equal(begin(r1) + 2, begin(r1)+ 7, begin(r2)+1); // true
cout << equal(begin(r1)+1, begin(r1)+7, begin(r2), begin(r2)+6);  // true



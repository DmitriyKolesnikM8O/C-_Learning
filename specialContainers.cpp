//pair
pair<int, double> p {4, 8.21};

cout << p.fisrt; //4
cout << p.second // 8.21

//tuple
#include <tuple>
tuple<int, double, vector<int>> t {3, 1.3, vector<int>{4, 5, 6}};

cout << get<0>(t); // 3
cout << get<1>(t); //1.3

cout << get<double>(t); //1.3

for(int x : get<t>(t)) {
    cout << x; //456
}

//tie

tuple<doudle, int, int> foo(int x) {
    return {2*x, 3*x, 4*x};
}

double d;
int i, j;
tie(d, i, j) = foo(2);

cout << d << i << j; //4 6 8

//auto
tuple<doudle, int, int> foo(int x) {
    return {2*x, 3*x, 4*x};
}

auto [d, i, j] = foo(2);

cout << d << i << j; //4 6 8

struct A {
    dobule a;
    int b;
    int c;
};
A foo(int x) {
    return A{2*x, 3*x, 4*x};
}

auto [b, d, i] = foo(2);

cout << b << d << i; //4 6 8

//optional
//специальный тип данных, который позволяет обозначить, что значение может отсутствовать.
//Использование optional позволяет избежать ситуаций, когда используется значение, которого нет.
#include <optional>

std::optional<int> getValue(bool condition) {
    if (condition) {
        return 40;
    }

    return std::nullptr;
}

auto value = getValue(false);
if (value) {
    cout << value;
} elze {
    cout << "No value";
}









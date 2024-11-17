//compiler-generated function objects
//can be used like anonymous functions

[] {
    return 200;
}

[] (int x, int y) -> double {
    return (0.5 * (x + y));
}

vector<int> v {1, 2, 3, 4, 5};

int i = 2;

transform(begin(v), end(v), begin(v),
        [=] (int x) {
            return (x * i);
        });
cout << i << '\n';

[=] (...) {...} //captures all by value
[&] (...) {...} //captures all by reference
[x, &y] (...) {...} //captures x by value and y by reference
[=, &y] (...) {...} //captures all except y by value

vector<int> v {1, 2, 3, 4, 5};

auto squ = [] (int x) { return (x * x); }

transform(begin(v), end(v), begin(v), squ);















#include <iostream>

/*
Хранятся переменные в том же порядке, в каком они были объявлены в структуре
*/

struct point {
    int x; //member variable
    int y;
};

void function_with_pointer (point const& p) {}

enum class month {jan, febr, march, apr, may, june, july};

struct data {
    int year;
    month m;
    int day;
};

struct person {
    data bday;
    std::string name;
};

int main() {
    point p {44, 55}; //new object create on stack
    std::cout << p.x << ' ' << p.y << '\n';
    
    data some_data {2024, month::jan, 23};

    person one {{2005, month::may, 4}, "Ivan"};

    std::cout << one.bday.day << ' ' << one.name;

    person two = one; // точная копия всех значений, все на стеке
    
    person three {{2003, month::febr, 23}, "Dima"};

    one = three // перезапись всех значений существующего обхекта
                      

}

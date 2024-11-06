#include <string>
#include <iostream>

/*
- Dynamic array of char (similar to vector<char>)
- Модифицируемый в отличие от Python или Java
- auto a = "seven of" - type of a is char const[], NOT STRING

however:
using namespace std::string_literals;
auto a1 = "seven of"s - this is already string


int edit (std::string_view s1) {...}
In this function we use string_view for only read parametes
It help us: lightweight, non-owning and ...

stirng const сперва создает объект типа string, который уже ссылается на динамический массив,
а string_view сразу на него ссылается, что выгоднее, если мы его не будем изменять
*/

int main() {
    std::string str = "Hello";
    std::string str_copy = str;

    str += " World!";

    std::cout << str << '\n';
    std::cout << str_copy << '\n';

    str[5] = 65;
    str += "\'use reverse slash(\\) for \' or for \"";

    std::cout << str << '\n';

    str.insert(5, "I can insert in string");
    std::cout << str << '\n';
    
    str.erase(4, 1);
    std::cout << str << '\n';
    std::cout << str.find("I") << '\n';

    std::string s;
    std::getline(std::cin, s);
    std::cout << "My string: " << s << '\n';
}

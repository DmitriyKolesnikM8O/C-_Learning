#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }

    auto second_argument_string = std::string(argv[1]);
    auto five_argument_int = atoi(argv[4]);
    std::cout << second_argument_string << ' ' << five_argument_int;
}

#include <iostream>
#include <vector>

using real = double;

int main() 
{
    std::vector<int> v {1, 2, 3};
    std::vector<int> v_all_4 (10, 4);
    std::cout << v[0] << "\n";
    std::cout << v_all_4[5] << "\n";

    v[0] = 5;
    std::cout << v[0] << "\n";
   
    std::cout << v.front() << "\n";
    std::cout << v.back() << "\n";

    std::cout << "Vector size before push_back: ";
    std::cout << v.size() << '\n';
    v.push_back(-123145);
    std::cout << v.back() << "\n";
    std::cout << "Vector size after push_back: ";
    std::cout << v.size() << '\n';

    v.resize(10, -3);

    std::cout << "Vector size after resize: ";
    std::cout << v.size() << '\n';
    
    std::cout << v.back() << "\n";

    std::vector<int> b = v; //it is copy vector


    std::cout << "And clear vector in the end";
    v.clear();
    std::cout << v.size() <<'\n';

    std::cout << "All elements in vector" << '\n';
    for (int x : b) { std::cout << x << ' '; }

    real tests = 3.4;
    std::cout << tests;
} 

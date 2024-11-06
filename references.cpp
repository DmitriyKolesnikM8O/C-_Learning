#include <iostream> 
#include <string>
#include <vector>

/*
Если чтение происходит из легко копируемого объекта, например, double, лучше передавать по значению
Если чтение происходит из тяжело копируемого объекта (больше чем 64 бита), лучше передавать как const&
example:
void print(std::vector<std::string> const& v) {
    for (auto const& s : v) {
        std::cout << s << ' ';
    }
}
Если в любом случае нужно копировать внутри функции - по значению
Если функция возвращает ссылку на аргумент, то и передавать его надо в нее по ссылке, иначе создастся локальная
копия, которая просто уничтожится после конца функции, то есть ссылка в никуда.
Неправильно:
int& increase (int x, int delta) {
    x += delta;
    return x;
}  //  local x destroyed

int main () {
  int i = 2;
  int j = increase(i,4);  //  accesses invalid reference!
}
Правильно:
int& increase (int& x, int delta) {
    x += delta;
    return x;  // x references non-local int
}  // OK, reference still valid

int main () {
  int i = 2;
  int j = increase(i,4);  // OK, i and j are 6 now
}

Нужно быть аккуратным со ссылками на значения вектора, ведь любая операция может изменить порядок значений

Dangling references (оборванные ссылки) - ссылки, указывающие на уже некорректные значения в памяти 
*/

void swap(int& i, int& j) {
    int tmp = i;
    i = j;
    j = tmp;
}

int main() {
    int i = 2;
    int& ri = i; //reference to i, ri and i refer to same object
                // ссылка всегда должна быть инициализована 
    i = 5;
    std::cout << i << '\n';
    std::cout << ri << '\n';

    ri = 4;
    std::cout << i << '\n';
    std::cout << ri << '\n';
    
    int k = 3;
    ri = k; //мы присваиваем i значение k, на само k ссылки нет! Она идет на i
     
    std::cout << i << '\n';
    std::cout << ri << '\n';
    ri = 6;
    std::cout << k << '\n';
    std::cout << i << '\n';
    

    int const& cri = i; //мы не можем теперь поменять значение i через изменение cri, только через i
                        //read-only access, save memory, good thing
    
    std::vector<std::string> v;
    v.resize(3);

    std::cout << "Now work with vector" << '\n';
    for (std::string& s : v) {
        std::cin >> s;
    }

    for(std::string const& s : v) {
        std::cout << s << ' ';
    }

    std::cout << "Swap functions" << '\n';
    int a = 5;
    int b = 6;
    std::cout << a << ' ';
    swap(a, b);
    //swap(a, 5); мы  не можем привязать ссылку к литералу, поэтому это ошибка
    std::cout << a << ' ';
}

auto incl_first_last (std::vector<int> x, std::vector<int> const& y) {
  if (y.empty()) return x;
  // append to local copy 'x'
  x.push_back(y.front());
  x.push_back(y.back());
  return x;
}

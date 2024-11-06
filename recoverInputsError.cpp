#include <iostream>

//int main() {
//  std::cout << "i? ";
//  int i = 0;
//  std::cin >> i;  // ← 1st
//  std::cout << "j? ";
//  int j = 0;
//  std::cin >> j;  // ← 2nd
//  std::cout << "i: " << i <<", " 
//       << "j: " << j <<'\n';
//}
//
/*
если в первый cin ввести некорректный ввод, например, "ваыпрп", то программа просто выведет последний cout и все
Так происходит из-за следующего:
- в cin устанавливается failbit из-за некорректного ввода
- буфер cin при это не освобождается и по прежнему содержит некорректный ввод
- из-за этого каждая следующая попытка чтения в cin будет приводит к fail

чтобы решить проблему - сбросить входной поток после ошибки, то есть очистить failbit и буфер cin
*/

void reset_cin() {
    std::cin.clear(); //clear all error status bit
    std::cin.ignore(32767, '\n'); //clear input buffer
    std::cout << "Here";
}

int main() {
  std::cout << "i? ";
  int i = 0;
  std::cin >> i;  // ← 1st
  
  if (std::cin.fail()) reset_cin();

  std::cout << "j? ";
  int j = 0;
  std::cin >> j;  // ← 2nd
  std::cout << "i: " << i <<", " 
       << "j: " << j <<'\n';
}


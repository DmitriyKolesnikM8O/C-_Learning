//что такое heap
// - семейство структур данных (не путать с разделом для динамических объектов)
// - содержат ключи, которые можно упорядочить
// - обычно используются для реализации приоритетных очередей
// Поддерживаемые операции:
// - взятие максимума за константу
// - удаление максимума за константу
// - вставка нового ключа за константу или логарифм
// - увеличить или уменьшить значение по ключи за константу или логарифм
//
// Binary Max Heaps
// - ключи хранятся в узлах бинарного дерева
// - ключи должны быть сравниваемыми
// - корень имеет максимум, все дочерние элементы всегда содержат меньшие значения, чем у их родителей
//
// Heap operations = алгоритмы, которые переупорядочивают элементы
//
// Initialize heap

std::vector<int> h {1, 6, 4, 2, 9, 7, 8};
make_heap(begin(v), end(v))
//       9
//   6      8
// 2   1  7   4  

//Shrink heap
std::vector<int> h {1,2,4,9,8,7,6};
make_heap(begin(h), end(h));  // 9 6 8 2 1 4 7

//removing element from heap
pop_heap(begin(h), end(h));
auto oldmax = h.back();  // oldmax = 9
h.pop_back();
//9 not in heap now

//Grow heap
std::vector<int> h {1,2,4,8,6,7};
make_heap(begin(h), end(h));  // 8 6 7 2 1 4

//add new element in heap
h.push_back(9);
push_heap(begin(h), end(h));


//еще есть операции по сортировки и так далее
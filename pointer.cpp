/*
Зачем они нужны?
1. Наблюдение за объектами:
- передача ссылки вместо копирования объекта
- если хотим изменить цель косвенного обращения во время выполнения -> ссылки использовать нельзя
2. Доступ к динамической памяти
- получение доступа к объектам, время жизни которых не привязано к переменной или области действия
3. Создание динамических структур данных на основе узлов
- Динамический массив [0 4 * 0 0 0 '0' 1 2 3 0 0 0 0]: * ссылается на '0'
- Связные списки [0 '0' * 0 0 0 1 * 0 2 * 0 0 3 * 0]: * ссылается на 1, * ссылается на 2, * ссылается на 3 и тд
- Деревья, графы [0 2 * * 0 0 5 * * 0 0 0 7 * * 0 0]: у 5 правая * - на 7, левая - на 2


Pointer to object of Type T:
0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07
               C=5                 p=0x3
- хранит адрес памяти объекта типа Т
- может использоваться для взаимодействия с целевым объектом
- может быть перенаправлен на другую цель (в отличие от ссылок)
- объекта может и не ьыть (нулевой pointer)

В чем разница между ссылкой и указателем?
Указатель - это переменная, которая содержит адрес памяти другой переменной. Указатель необходимо разыменовать с помощью этого оператора * , чтобы получить доступ к ячейке памяти, на что он указывает.
Ссылка - Ссылочная переменная — это псевдоним, то есть другое имя для уже относительной переменной. Ссылка, как и указатель, также осуществляется посредством сохранения адреса адреса. 

int i = 3;
//A pointer to 'i'
int *ptr = &i;
//OR
int *ptr;
ptr = &i;

//A reference for 'i'
int &ref = i;

Ссылки объявляются и инициализируются на 1 шаге, в то время как указатель может быть объявлен, как отдельная переменная (данное различие может варьироваться от компилятора к компилятору)
Указатель также можно переназначить, а ссылку нельзя
Указатель использует собственный адрес памяти и размер в стеке, в то время как ссылка использует тот же адрес памяти, что и переменная, не занимая место в стеке.
Указатель может быть равен NULL, в то время как ссылке не может
Можно иметь указатель на указатель, что делает более глубокую косвенность, в то время как со ссылками так нельзя

!Если я удалю объект, на который указывает ссылка, то она может указывать на что угодно, что небезопасно!

Производительность будет одинаковой, поскольку ссылку внутри реализованы, как указатели
Использовать ссылки:
- в параметрах функций и возвращаемых типах
Использовать указатели:
- если требуется арифметика указателей или передача указателя NULL. Например, для массивов.
- для реализации структур данных, например, связного списка

"Ссылки обычно предпочтительнее указателей, использовать их, когда можно, а указатели, когда необходимо".

Исходные указатели:
- по сути, беззнаковая целочисленная переменная, хранящая адрес объекта
- размер: 64 бита на 64 битной платформе
- множество указателей могут указывать на один и тот же адрес памяти
- время жизни указателя и объекта независимо


Smart Pointers
1) std::unique_pointer<T>
- Используется для доступа к динамическим объектам, то есть тем, которые выделены в куче
- только один такой указатель на объект
- указатель и целевой объект имеют одинаковое время жизни
2) std::shared_pointer<T> и std::weak_pointer<T>
- Используется для доступа к динамическим объектам, то есть тем, которые выделены в кучe
- много таких указателей на объект
- целевой объект будет существовать до тех пор, пока на него указывает хотя бы один shared_ptr



*/


int main() {
    //address operator &
    char c = 65; // stack 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07
    char* p = &c; //                      65  0x03
    // *p хранит указатель на объект c
    // &c - возвращает адрес объекта с

    //operator *
    char c = 65; //stack 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07
    char* p = &c; //                     65  0x03
     *p = 88; //                         88  0x03
    char b = *p; //                      88  0x03  88
    // *p - получает доступ к значению по адресу, указанному в p

    //operator ->
    //struct Coord {
    //  char x = 0;
    //  char y = 0;
    //}                             // stack 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07
    //Coord a {12, 34};             //                       12   34  0x03
    //Coord* p = &a;                //                       a.x  a.y  p
    //char v = p->x; // v = 12
    //char w = p->y; // w = 34
    //
    //alternative version:
    //char s = (*p).x // s = 12
    //char t = (*p).y //t = 34
    // оператор -> просто представляет собой удобный способ обращения к членам объектов через указатели. Этот оператор банально делает код более понятным и читабельным

}

//                             *                                          &
// Type Modifier     Pointer Declaration                    Reference Declaration(объявление)
//                    Type* p = nullptr;                            Type& ref = variable;
//
//Unary operator    Dereferencing(Разыменование)                     Taking address
//                      value = *pointer;                           pointer = &variable
//
//Binary operator    Multiplication(умножение)                   Bitwise AND(побитовое И)
//                      product = exp1 * exp2                         bitland = exp1 & exp2
//
//Ловушка при объявлении
//int * i1, i2 // int*, int
//Лучше так: int* i1 = ....;
//           int* i2 = ....;
//



//Redirection (unlike references, pointers can be redirected)
int redirection() {
    int a = 0;
    int b = 0;
                                    // a:0 b:0
    int* p = &a;                    // p->a a:0 b:0
    *p = 2;                         // p->a a:2 b:0
    p = &b;                         // a->b a:2 b:0    
    *p = 9                          // a->b a:2 b:9  

}

//Nullptr (special pointer value), implicit (неявно) convertible to false, not necessary represented (представлено) 0 in memory (depends on platform)
//Соглашение: nullptr означает, что значение недоступно
//- устанавливать при инициализации
//- проверять, что != nullptr до разыменования

int nullptr() {
    int* p = nullptr;
    if (...) {
        int i = 5;
        p = &i //assign valid address

        //check before dereferencing
        if (p) *p = 7;
    }
}

//const and Pointers:
//- чтобы запретить перенаправление
//- чтобы открыть доступ только для чтения объекта
//
//Syntax:
// T*  - значение модифицируется, указатель можно изменять
// T const *  - значение не модифицируется, указатель можно изменять
// T * const - значение модифицируется, указатель нельзя изменять
// T const * const - значение не модифицируется, указатель можно не изменять
//Читать справа налево: константный указатель на константу

int const() {
    int i = 5;
    int j = 8;
    int const* cp = &i;
    *cp = 8;   //  COMPILER ERROR: pointed-to value is const
    cp = &j;   //  OK
    int *const pc = &i;
    *pc = 8;   //  OK
    pc = &j;   //  COMPILER ERROR: pointer itself is const
    int const*const cpc = &i;
    *cpc = 8;  //  COMPILER ERROR: pointed-to value is const
    cpc = &j;  //  COMPILER ERROR: pointer itself is const

}

//The 'this' Pointer
//- доступен внутри member-function
//- this возвращает адрес самого объекта
//- this-> можно использовать для доступа к members
//- *this получает доступ к самого объекту

class IntRange {
  int l_ = 0;
  int r_ = 0;
public:
  explicit
  IntRange (int l, int r): l_{l}, r_{r} {
    if (l_ > r_) std::swap(l_, r_);
  }
  int left ()  const { return l_; }
  // can also use 'this' to access members:
  int right () const { return this->r_; }
  …
  // returns reference to object itself
  IntRange& shift (int by) {
    l_ += by;
    r_ += by;
    return *this;
  }
  IntRange& widen (int by) {
    l_ -= by;
    r_ += by;
    return *this;
  }
};

IntRange r1 {1,3};                        // 1 3
r1.shift(1);                              // 2 4
r1.shift(2).widen(1);  // chaining possible! 3 7

//Forward Declarations of Types (Предварительное объявление типов)
//Иногда такое необходимо, если нужно, чтобы 2 типа ссылались друг на друга

// forward declaration
class Hub;
class Device {
  Hub* hub_;
  …
};
class Hub {
  std::vector<Device const*> devs_;
  …
};


//Чтобы определить тип, необходимо знать объемы памяти всех его членов.
//Это, в свою очередь, возможно только в том случае, если известно полное определение всех членов.
//Однако все типы указателей имеют одинаковый размер.
//мы можем просто объявить о существовании Hub, поскольку Device нужен только указатель на него.


//По возможности стоит избегать pointer
//pointer склонны к dangling
//dangling - поинтер указывает на недействительный, неверный адрес
//Всегда нужно следить за тем, что целевой адрес до сих пор действителен, актуален
//

int Avoid_pointer() {
    int* p;  // p not initialized!
    *p = 7;  //  UNDEFINED BEHAVIOR
    
    p = nullptr;
    *p = 7;  //  UNDEFINED BEHAVIOR access to nullptr
            
    {
      int x = 8;  
     p = &x;   
    }        // x's lifetime ends
    *p = 7;  //  UNDEFINED BEHAVIOR access to freed memory
  
}

//Пример передачи аргументов с ошибкой
void swap_values (int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int x = 3, y = 4;
swap_values(&x, &y)        // OK
swap_values(&x, 0);        //  UNDEFINED BEHAVIOR
swap_values(&x, nullptr);  //  UNDEFINED BEHAVIOR

//Ну и код становится сложнее читать: *p = *p * *p + (2 * *p + 1);
//Ccылки лучше, особенно когда речь идет про параметры функций









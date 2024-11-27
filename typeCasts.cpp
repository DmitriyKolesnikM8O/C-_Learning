//A cast is a transformation between two types
//some of them are slow
//can make code less understandable and more brittle(хрупким)
//only use them if absolutely necessary

static_cast<NewType>(expression)
dynamic_cast<NewType>(expression)
const_cast<NewType>(expression)
reinterpret_cast<NewType>(expression)
bit_cast<NewType>(expression)


//static_cast
int i = 5, j = 20;
auto r = static_cast<double>(i) / j; //prevents int division

//dynamic_cast
class Vehicle {};
class Car : public Vehicle {};

class Movie {};

Car c;
Vehicle* v = &c;

auto cc = dynamic_cast<Car*> (v); //succeeds: cc = &c
auto m = dynamic_cast<Movie*> (v); //fails: m = nullptr

//const_cast
Circle c;
Circle const* cpc = &c;

Circle* pc = const_cast<Circle*>(cpc);



































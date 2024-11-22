//Different levels of Encapsulation
// public - accessed by all functions
// private - only accessed by member functions of the sam type
// friend - allows a limited number of function access to private member (позволяет ограниченному числу функций иметь доступ к приватным членам)
//
// Use Cases:
// - split an abstraction into severa; friend types with private access
// - keep members hidden from any other function except for a select few friends
// - write free-standing friend functions that can act like member functions
// - prevent implicit argument conversions (предотвращать неявные преобразования типов)

//friend Types
class Simulation {
    friend class SimulationView;
public:
    Simulation(Settings const&); //init & run
    ~Simulation(); //finalize                                 
};

class SimulationView {
public:
    explicit SimulationView(Simulation const*);
};

//friend Functions
class Point2d {
    double x_; //private
    double y_;
public:
    explicit Point2d (double x, double y): x_{x}, y_{y} {}
    double x () const {return x_; }
    double y () const {return y_; }

    //можем получить доступ к закрытым членам Point2d
    friend std::istream& operator >> (std::istream& is, Pointr2d& p) {
        return is >> p.x_ >> p.y_;
    }
};

int main() {
    Pointr2d p {0,0};
    std::cin >> p;
}

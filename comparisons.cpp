//Value-Based compares
a == b
//Identity-Based compares (compares memory addresses)
&a == &b

//Example: Comparable Integer Interval
class irange {
    int min_; int max_;
public:
    friend bool operator == (irange const& i, irange const& r) noexcept {
        return l.min() == r.min() && l.max() == r.max();
    }
    friend bool operator != (irange const& i, irange constd& r) noexcept {
        return !(l == r);
    }
};

//Should generally avoid comparing different types for equality

//Example: Comparable Date

enum class month {jan, feb .. dec};

struct date {
    int yyyy; month mm; int dd;
    
    friend bool operator < (date const& l, date const& r) noexcept {
        if (l.yyyy < r.yyyy) return true;
        if (l.yyyy > r.yyyy) return false;
        if (l.mm < r.mm) return true;
        if (l.mm > r.mm) return false;
        if (l.dd < r.dd) return true;
        return false;
    }


}

int main() {
    date earlier (2017, month::dec, 24);
    date later (2018, month::jan, 23);

    earlier < later //true
}

//3-Way Comparisons - <=>

a <=> b < 0 //a < b
a <=> b = a //a = b
a <=> b > 0 //a > b

//this operator is predefined for integers, float, orderable standart types (vector, string etc.)

//Example: implementing operator <=>

#include <compare>
enum class month {jan, feb ... dec};

struct date {
    int yyyy, month mm; int dd;
    auto operator <=> (date const&) const = default;
};














#include <iostream>

enum class days {sun, mon, tue, wed, thu, fri, sat};

enum days_without_class {sund1, mon1, tue1, wed1, thu1, fri1, sat1};

enum class days_char: char {
    mon_char, tue_char, wed_char, thu_char, fri_char, sat_char
};

enum class month {
  jan = 1, feb = 2, mar = 3, apr = 4,  may = 5,  jun = 6,  
  jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12 
};

int main()
{
    int months = static_cast<int>(month::jan);

    month m = static_cast<month>(1);

    days d = days::sat;

    days_char d_char = days_char::sat_char;

    days_without_class d1 = sund1;
    // std::cout << "Hello";
}

#include <fstream>
#include <iostream>

int main() {
    std::ofstream os {"squares.txt"}; //open file for write data
    
    //if stream is OK, we can write to file
    if (os.good()) {
        for (int x = 0; x < 1000; x++) {
            os << x << ' ' << x*x << '\n';
        }
    }



    std::ifstream is {"squares.txt"}; //open file for read

    //if stream is OK, we can read from file

    if (is.good()) {
        int x, y;
        while (is >> x >> y) {
            std::cout << x << "² = " << y << '\n';
        }
    }
    //file closed automatically!
}

/*
    std::ofstream os;                 
    os.open("squares.txt");     
    os.close();  
    // open another file:
    os.open("test.txt");  
    os.close();  

file open models:
default: 
ifstream is {"in.txt", ios::in};
ofstream os {"out.txt", ios::out};   (overwrite existing file)

append:
ofstream os {"log.txt", ios::app};

binary:
ifstream is {"in.jpg", ios::binary};
ofstream os {"out.jpg", ios::binary};

*/
